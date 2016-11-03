#include "window.h"

Window::Window() {
    _width = WIDTH;
    _height = HEIGHT;
    _window = 0;
    _surface = 0;
}

// init
bool Window::Init () {
    // init SDL
    SDL_Init(SDL_INIT_VIDEO);
    
    // create game window
    _window = SDL_CreateWindow("test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _width, _height, SDL_WINDOW_OPENGL);
    if (_window == NULL) return false;
    
    _glContext = SDL_GL_CreateContext(_window);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    
    glClearColor(0, 0, 0, 0);
    return true;
}

void Window::Render() {
    SDL_GL_SwapWindow(_window);
    
    glClearDepth(1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glMatrixMode(GL_PROJECTION); 

    float a = 2.f / _width;
    float b = 2.f / _height;  

    float proj[] {
        a,  0,  0,  0,
        0,  b,  0,  0,
        0,  0,  1,  0,
        0,  0,  0,  1
    };

    glLoadMatrixf(proj);

    glLineWidth(1);
    glColor3f(0, 0.2, 0);

    for (int i=0; i < WIDTH/BOX; ++i) {
    glBegin(GL_LINES);
    glVertex2f((-WIDTH/2)+(BOX*i), (-HEIGHT/2));
    glVertex2f((-WIDTH/2)+(BOX*i), (HEIGHT/2));
    glEnd();
    }

    for (int i=0; i < HEIGHT/BOX; ++i) {
    glBegin(GL_LINES);
    glVertex2f((-WIDTH/2), (-HEIGHT/2)+(BOX*i));
    glVertex2f((WIDTH/2), (-HEIGHT/2)+(BOX*i));
    glEnd();
    }

    glColor3f(0, 0, 0.5);

    glBegin(GL_LINES);
    glVertex2f((-WIDTH/2)+PADDING, (-HEIGHT/2)+PADDING);
    glVertex2f((-WIDTH/2)+PADDING, (HEIGHT/2)-PADDING);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f((WIDTH/2)-PADDING, (-HEIGHT/2)+PADDING);
    glVertex2f((WIDTH/2)-PADDING, (HEIGHT/2)-PADDING);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f((WIDTH/2)-PADDING, (-HEIGHT/2)+PADDING);
    glVertex2f((-WIDTH/2)+PADDING, (-HEIGHT/2)+PADDING);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f((WIDTH/2)-PADDING, (HEIGHT/2)-PADDING);
    glVertex2f((-WIDTH/2)+PADDING, (HEIGHT/2)-PADDING);
    glEnd();
}

void Window::Destroy() {
    SDL_GL_DeleteContext(_glContext);
    SDL_DestroyWindow(_window);
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

