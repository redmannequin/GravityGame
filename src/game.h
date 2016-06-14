#ifndef GAME_H
#define GAME_H

#include "./math/vector2D.h"
#include "./game_defs.h"
#include "./defs.h"

// entities
#include "./entity/entity.h"
#include "./entity/player.h"

struct game_state {
  Vector2D accel;
  Player player;
};

class Game {
  public:
    Game();
    ~Game();

    void Init(game_memory * memory, game_input * input);
    void Update(float, float); 
    void Render(float interpolation);

  private:
    game_state * _state;
    game_input * _input;

    Player * _player;
};

#endif
