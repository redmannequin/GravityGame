#ifndef PLAYER_H
#define PLAYER_H

#include "./entity.h"
#include "../draw/polygon.h"

class Player: public Entity {
  public:
    Player();
    ~Player();
    
    void init();
    void update();
    void draw(game_offscreen_buffer *, float);
    
  protected:
    Polygon poly;

};

#endif
