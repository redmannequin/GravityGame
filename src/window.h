#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <GL/glu.h>

#include "defs.h"
#include "game_defs.h"

class Window {
  public:
    Window();
    ~Window();

    bool Init();
    void Render();
    void Destroy();

    //bool loadMedia();
    void ConvertBuffer(game_offscreen_buffer * buffer);
    void ConvertInput(game_input * input);
    Uint32 GetTicks();

  private:
    int height;
    int width;
    
    SDL_Window * window;
    SDL_Surface * surface;
    SDL_Texture * texture;
    SDL_Renderer * renderer;
};

#endif
