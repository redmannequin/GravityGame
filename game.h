#ifndef GAME_H
#define GAME_H

#include "vector2D.h"
#include "game_defs.h"

class Game {
  public:
    Game();
    ~Game();

    void Init(game_memory * memory, game_offscreen_buffer * buffer, game_input * input);
    void GameUpdateAndRender();

  private:
    game_state * state;
    game_input * input;
    game_offscreen_buffer * buffer;
};

#endif
