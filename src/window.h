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

  private:
    int _width;
    int _height;
    
    SDL_GLContext glContext;
    SDL_Window * _window;
};

#endif
