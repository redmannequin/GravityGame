#ifndef PLAYER_H
#define PLAYER_H

#include "./entity.h"
#include "../vector2D.h"
#include "../draw/polygon.h"

class Player: public Entity {
  public:
    Player();
    ~Player();
    
    void init();
    void update();
    void update(Vector2D *);
    void draw(game_offscreen_buffer *, float);
    
  protected:
    Polygon poly;

};

#endif
