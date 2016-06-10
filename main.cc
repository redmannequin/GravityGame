#include <iostream>
#include <SDL2/SDL.h>

#include "game_defs.h"
#include "game.h"
#include "defs.h"

#define Kilobytes(n) ((n)*1024)
#define Megabytes(n) (Kilobytes(n)*1024)
#define Gigabytes(n) (Megabytes(n)*1024)

using namespace std;

#define TITLE "test"
#define WIDTH  640
#define HEIGHT 480

#define TICKS_PER_SECOND 25
#define SKIP_TICKS (1000/TICKS_PER_SECOND)
#define MAX_FRAMESKIP 5

int main() {
  SDL_Window   *window   = NULL;
  SDL_Surface  *surface  = NULL;
  SDL_Renderer *renderer = NULL;

  // init SDL
  SDL_Init(SDL_INIT_VIDEO);

  // create game window
  window = SDL_CreateWindow(TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_OPENGL);
  if (window == NULL) {
    std::cout << "Could not create window " << SDL_GetError() << std::endl;
    return 1;
  }

  // create render context
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if (renderer == NULL) {
    std::cout << "Could not create renderer " << SDL_GetError() << std::endl;
    return 1;
  }

  // create surface for software rendering
  surface = SDL_CreateRGBSurface(0, WIDTH, HEIGHT, 32, 0, 0, 0, 0);
  if (surface == NULL) {
    std::cout << "Could not create surface" << SDL_GetError() << std::endl;
    return 1;
  }

  // init intput
  game_input input[2] = {};
  game_input *oldInput = &input[0];
  game_input *newInput = &input[1];

  // game memory
  game_memory gameMemory = {};
  gameMemory.permanentStorageSize = Megabytes(1);
  gameMemory.permanentStorage = ::operator new(gameMemory.permanentStorageSize);
  gameMemory.transientStorageSize = 1;
  gameMemory.transientStorage = ::operator new(gameMemory.transientStorageSize);

  // screen buffer
  game_offscreen_buffer buffer = {};
  buffer.memory = surface->pixels;
  buffer.width  = surface->w;
  buffer.height = surface->h;
  buffer.pitch  = surface->pitch;

  Game game;
  game.Init(&gameMemory, &buffer, newInput);

  SDL_Texture *texture;

  int loops;
  float interpolation; 
  Uint32 next_game_tick;

  bool running = true;

  next_game_tick = SDL_GetTicks();
  Uint32 start = SDL_GetTicks();
  int frames = 0;

  // game loop
  while (running) {
    // events
    SDL_Event e;
    if (SDL_PollEvent(&e) && e.type == SDL_QUIT) break;
    
    loops = 0;
    //update game and screen buffer
    while (SDL_GetTicks() > next_game_tick && loops < MAX_FRAMESKIP) {
      // keyboard states
      SDL_PumpEvents();
      const Uint8 *keystate = SDL_GetKeyboardState(NULL);
      if (keystate[SDL_SCANCODE_ESCAPE]) running = 0;
      newInput->up.endDown = keystate[SDL_SCANCODE_UP];
      newInput->down.endDown = keystate[SDL_SCANCODE_DOWN];
      newInput->left.endDown = keystate[SDL_SCANCODE_LEFT];
      newInput->right.endDown = keystate[SDL_SCANCODE_RIGHT];

      float t = next_game_tick/1000.f;
      float dt = SDL_GetTicks()/1000.f;
      dt = dt - t;
      game.Update(t, dt);
      next_game_tick += SKIP_TICKS;
      loops++;
    }
   
    SDL_FillRect(surface, NULL, 0x000000);
    interpolation = float(SDL_GetTicks() + SKIP_TICKS - next_game_tick) / float(SKIP_TICKS);
    game.Render(interpolation);

    // render to screen
    texture = SDL_CreateTextureFromSurface(renderer, surface); // hardware rendering context
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);
    SDL_DestroyTexture(texture);

    // swap old and new inputs
    game_input *temp = newInput;
    newInput = oldInput;
    oldInput = temp;
    
    ++frames;
    std::cout << "FPS: " << (frames / ((SDL_GetTicks() - start) / 1000.f)) << std::endl;
  }

  SDL_FreeSurface(surface);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);


  SDL_Quit();
  return 0;
}
