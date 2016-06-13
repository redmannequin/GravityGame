#ifndef GAME_H
#define GAME_H

#include "./vector2D.h"
#include "./game_defs.h"
#include "./defs.h"

// entities
#include "./entity/entity.h"
#include "./entity/player.h"
#include "./entity/space_object/planet.h"

struct game_state {
  Vector2D accel;
  Player player;
  Planet planet;
};

class Game {
  public:
    Game();
    ~Game();

    void Init(game_memory * memory, game_offscreen_buffer * buffer, game_input * input);
    void Update(float, float); 
    void Render(float interpolation);

  private:
    game_state * state;
    game_input * input;
    game_offscreen_buffer * buffer;

    Player * player;
    Planet * planet;
};

#endif
