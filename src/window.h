#ifndef WINDOW_H
#define WINDOW_H

#include <SDL.h>
#include <SDL_opengl.h>
#include <GL/gl.h>
#include <CL/cl.h>

#include "defs.h"
#include "game_defs.h"

class Window {
  public:
    Window();

    bool Init();
    void Render();
    void Destroy();

    void ConvertInput(game_input * input);

  private:
    int _width;
    int _height;
    
    SDL_GLContext _glContext;
    SDL_Surface* _surface;
    SDL_Window * _window;
};

#endif
