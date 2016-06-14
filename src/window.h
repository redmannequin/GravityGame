#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <SDL2/SDL_opengl.h>
#include <GL/glu.h>
#include <GL/gl.h>

#include "defs.h"
#include "game_defs.h"

class Window {
  public:
    Window();
    ~Window();

    bool Init();
    void Render();
    void Destroy();

    void ConvertInput(game_input * input);
    Uint32 GetTicks();

  private:
    int height;
    int width;
    
    SDL_Window * window;
};

#endif
