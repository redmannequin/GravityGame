#ifndef PHYSICS_H
#define PHYSICS_H

#include "./vector2D.h"

#define ACCEL_THRES 5.f

struct State {
  Vector2D pos;
  Vector2D vel;
};

struct Derivative {
  Vector2D dx;
  Vector2D dv;
};

Derivative evaluate(State * initial, Vector2D accel, float t);
Derivative evaluate(State * initial, Vector2D accel, float t, float dt, Derivative d);
void acceleration(State * state, Vector2D * accel);
void integrate(State * state, Vector2D accel, float t, float dt);
State interpolate(State prev, State curr, float alpha);
 
#endif
