#ifndef PLAYER_H
#define PLAYER_H

#include "./entity.h"
#include "../vector2D.h"
#include "../draw/polygon.h"

struct State {
  Vector2D pos;
  Vector2D vel;
};

struct Derivative {
  Vector2D dx;
  Vector2D dv;
};

class Player : public Entity {
  public:
    Player();
    ~Player();
    
    void init();
    void update();
    void update(Vector2D * input, float t, float dt);
    void draw(game_offscreen_buffer * buffer, float i);
    
  protected:
    Polygon poly;

    Vector2D vel;
    Vector2D dx;
    Vector2D dv;

    State curr;
    State prev;

    Derivative evaluate(State * initial, Vector2D accel, float t);
    Derivative evaluate(State * initial, Vector2D accel, float t, float dt, Derivative d);
    void acceleration(State * state, Vector2D * accel);
    void integrate(State * state, Vector2D accel, float t, float dt);
    State interpolate(State prev, State curr, float alpha);
 
};

#endif
