#include "window.h"

Window::Window() {
  this->width = 640;
  this->height = 480;

  this->window = 0;
  this->surface = 0;
  this->renderer = 0;
}

Window::~Window() {

}

// init
bool Window::Init () {
  // init SDL
  SDL_Init(SDL_INIT_VIDEO);

  // create game window
  this->window = SDL_CreateWindow("test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, this->width, this->height, 0);
  if (this->window == NULL) return false;
  
  // create render context
  this->renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if (this->renderer == NULL) return false;

  // create surface for software rendering
  this->surface = SDL_CreateRGBSurface(0, this->width, this->height, 32, 0, 0, 0, 0);
  if (this->surface == NULL) return false;
  
  //Initialize PNG loading
  int imgFlags = IMG_INIT_PNG;
  if(!(IMG_Init(imgFlags) & imgFlags)) return false;
  
  return true;
}

// render
void Window::Render() {
    // hardware rendering context
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);
    SDL_DestroyTexture(texture);
    SDL_FillRect(surface, NULL, 0x000000);
}

// dertroy
void Window::Destroy() {
  SDL_FreeSurface(surface);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

// convert buffer
void Window::ConvertBuffer(game_offscreen_buffer * buffer) {
  buffer->memory = this->surface->pixels;
  buffer->width  = this->surface->w;
  buffer->height = this->surface->h;
  buffer->pitch  = this->surface->pitch;
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

/*
// load media
bool loadMedia(std::string path) {
  SDL_Surface * loadedSurface = IMG_Load(path.c_str());  
  if (loadedSurface == NULL) {
    std::cout << "Unable to load image: " << path << " ";
    std::cout << "SDL_image Error: " << IMG_GetError() << std::endl;
    return false;
  } else {
    surface = SDL_ConvertSurface(loadedSurface, this->surface->format, NULL);
    if (surface == NULL) {
      std::cout << "Unable to optimize image: " << path << " "; 
      std::cout << "SDL Error: " << SDL_GetError() << std::endl;
      return false;
    }
    SDL_FreeSurface(loadedSurface);
  }
  return true;
}
*/
