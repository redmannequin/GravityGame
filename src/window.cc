#include "window.h"

Window::Window() {
  this->width = 640;
  this->height = 480;

  this->window = 0;
}

Window::~Window() {

}

// init
bool Window::Init () {
  // init SDL
  SDL_Init(SDL_INIT_VIDEO);

  // create game window
  this->window = SDL_CreateWindow("test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, this->width, this->height, SDL_WINDOW_OPENGL);
  if (this->window == NULL) return false;

  // set up openGL
  SDL_GLContext glContext = SDL_GL_CreateContext(this->window);

  GLenum error = glewInit();
  if (error != 0) return false;

  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

  glClearColor(0, 0, 0, 0);

  return true;
}

// render
void Window::Render() {
  SDL_GL_SwapWindow(this->window);
  
  glClearDepth(1.0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glMatrixMode(GL_PROJECTION); 

  float a = 2.f / this->width;
  float b = 2.f / this->height;  

  float proj[] {
     a,  0,  0,  0,
     0,  b,  0,  0,
     0,  0,  1,  0,
    -1, -1,  0,  1
  };
  
  glLoadMatrixf(proj);

  /*
  glBegin(GL_TRIANGLES);
  glColor3f(1, 0, 0);
  glVertex2f(0, 0);
  glVertex2f(0, 100);
  glVertex2f(100, 100);
  glEnd();
  */

}

// dertroy
void Window::Destroy() {
  SDL_DestroyWindow(window);
  SDL_Quit();
}

// convert input
void Window::ConvertInput(game_input * input) {
  SDL_Event e;
  input->quit = (SDL_PollEvent(&e) && e.type == SDL_QUIT);
  //SDL_PumpEvents();
  const Uint8 *keystate = SDL_GetKeyboardState(NULL);
  input->up.endDown = keystate[SDL_SCANCODE_UP];
  input->down.endDown = keystate[SDL_SCANCODE_DOWN];
  input->left.endDown = keystate[SDL_SCANCODE_LEFT];
  input->right.endDown = keystate[SDL_SCANCODE_RIGHT];
  input->escape.endDown = keystate[SDL_SCANCODE_ESCAPE];
}

// Get Ticks
Uint32 Window::GetTicks() {return SDL_GetTicks();}

