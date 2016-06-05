#include <iostream>
#include <SDL2/SDL.h>

#include "game.h"

#define Kilobytes(n) ((n)*1024)
#define Megabytes(n) (Kilobytes(n)*1024)
#define Gigabytes(n) (Megabytes(n)*1024)

using namespace std;

#define TITLE "test"
#define WIDTH  640
#define HEIGHT 480

int main()
{
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
    gameMemory.permanentStorageSize = Kilobytes(1);
    gameMemory.permanentStorage = ::operator new(gameMemory.permanentStorageSize);
    gameMemory.transientStorageSize = 1;
    gameMemory.transientStorage = ::operator new(gameMemory.transientStorageSize);

    // screen buffer
    game_offscreen_buffer buffer = {};
    buffer.memory = surface->pixels;
    buffer.width  = surface->w;
    buffer.height = surface->h;
    buffer.pitch  = surface->pitch;

    Game game(&gameMemory, &buffer, newInput);

    SDL_Texture *texture;
    // game loop
    while (1) {
      // events
      SDL_Event e;
      if (SDL_PollEvent(&e) && e.type == SDL_QUIT) break;

      // keyboard states
      SDL_PumpEvents();
      const Uint8 *keystate = SDL_GetKeyboardState(NULL);

      if (keystate[SDL_SCANCODE_ESCAPE]) break;
      newInput->up.endDown = keystate[SDL_SCANCODE_UP];
      newInput->down.endDown = keystate[SDL_SCANCODE_DOWN];
      newInput->left.endDown = keystate[SDL_SCANCODE_LEFT];
      newInput->right.endDown = keystate[SDL_SCANCODE_RIGHT];

      //update game and screen buffer
      SDL_FillRect(surface, NULL, 0x000000);
      game.GameUpdateAndRender();

      // render to screen
      texture = SDL_CreateTextureFromSurface(renderer, surface); // hardware rendering context
      SDL_RenderCopy(renderer, texture, NULL, NULL);
      SDL_RenderPresent(renderer);
      SDL_DestroyTexture(texture);

      SDL_RenderClear(renderer);


      // swap old and new inputs
      game_input *temp = newInput;
      newInput = oldInput;
      oldInput = temp;

    }


    SDL_FreeSurface(surface);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();
    return 0;
}
