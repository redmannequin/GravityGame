#ifndef PLAYER_H
#define PLAYER_H

#include "./entity.h"

#include "../math/vector2D.h"
#include "../math/physics.h"

#include "../draw/polygon.h"

class Player : public Entity {
  public:
    Player();
    ~Player();
    
    void init();
    void update();
    void update(Vector2D * input, float t, float dt);
    void draw(float i);
    
  protected:
    Polygon _poly;

    Vector2D _vel;
    Vector2D _dx;
    Vector2D _dv;

    State _curr;
    State _prev;
};

#endif
