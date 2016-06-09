#ifndef GAME_H
#define GAME_H

#include "vector2D.h"
#include "game_defs.h"
#include "defs.h"

struct game_state {
  Vector2D pos;
};

class Game {
  public:
    Game();
    ~Game();

    void Init(game_memory * memory, game_offscreen_buffer * buffer, game_input * input);
    void Update(); 
    void Render(float interpolation);

  private:
    game_state * state;
    game_input * input;
    game_offscreen_buffer * buffer;
};

#endif
