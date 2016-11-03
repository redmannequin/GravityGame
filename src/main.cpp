#include <iostream>
#include "window.h"
#include "game.h"


int main(int argc, char **argv) {
    // init window
    Window win;
    win.Init();
    
    // init intput
    game_input input[2] = {};
    game_input * oldInput = &input[0];
    game_input * newInput = &input[1];
    
    // init game 
    Game game;
    game.init(newInput);

    float interpolation;
    bool running = true;
    
    int frames = 0;
    Uint32 next_game_tick = SDL_GetTicks();
    Uint32 start = SDL_GetTicks();
    
    // game loop
    while (running) {
        // updates the game 25 times a secones
        for (int i=0; SDL_GetTicks() > next_game_tick && i < MAX_FRAMESKIP; i++) {
            // gets new input
            win.ConvertInput(newInput);
            if (newInput->escape.endDown || newInput->quit) running = 0;
            // calulates time diff 
            float t = next_game_tick/1000.f;
            float dt = (SDL_GetTicks()/1000.f) - t;
            next_game_tick += SKIP_TICKS;
            
            //  game update
            game.update();
            
            // swap old and new inputs
            game_input * temp = newInput;
            newInput = oldInput;
            oldInput = temp;
            
        }
        
        // game render
        interpolation = (float(SDL_GetTicks() + (SKIP_TICKS - next_game_tick)) / float(SKIP_TICKS));
        game.render();
        
        // render to screen
        win.Render();
        
        // print FPS
        ++frames;
        std::cout << "FPS: " << (frames / ((SDL_GetTicks() - start) / 1000.f)) << std::endl; 
    }
    
    // destroy window
    win.Destroy();
    return 0;
}