#include <iostream>

#include "./defs.h"
#include "./game.h"
#include "./window.h"
#include "./game_defs.h"

int main() {
  // init window
  Window win;
  win.Init();
  
  // init intput
  game_input input[2] = {};
  game_input * oldInput = &input[0];
  game_input * newInput = &input[1];

  // init game memory
  game_memory gameMemory = {};
  gameMemory.permanentStorageSize = Megabytes(1);
  gameMemory.permanentStorage = ::operator new(gameMemory.permanentStorageSize);
  gameMemory.transientStorageSize = 1;
  gameMemory.transientStorage = ::operator new(gameMemory.transientStorageSize);

  // init game
  Game game;
  game.Init(&gameMemory, newInput);
  
  float interpolation; 
  bool running = true;

  int frames = 0;
  Uint32 next_game_tick = win.GetTicks();
  Uint32 start = win.GetTicks();

  // game loop
  while (running) {
    
    // updates the game 25 times a seconed
    for (int i=0; win.GetTicks() > next_game_tick && i < MAX_FRAMESKIP; i++) {
      // gets new input
      win.ConvertInput(newInput);
      if (newInput->escape.endDown || newInput->quit) running = 0;

      // calulates time diff 
      float t = next_game_tick/1000.f;
      float dt = (win.GetTicks()/1000.f) - t;
      next_game_tick += SKIP_TICKS;
     
      // updates the game state
      game.Update(t, dt);

      // swap old and new inputs
      game_input * temp = newInput;
      newInput = oldInput;
      oldInput = temp;
    }
   
    // software render
    interpolation = (float(win.GetTicks() + (SKIP_TICKS - next_game_tick)) / float(SKIP_TICKS));
    game.Render(interpolation);

    // render to screen
    win.Render();
    
    ++frames;
    std::cout << "FPS: " << (frames / ((SDL_GetTicks() - start) / 1000.f)) << std::endl;
  }

  win.Destroy();
  return 0;
}

