#include "./physics.h"
 
Derivative evaluate(State * initial, Vector2D accel, float t) {
  State state;
  state.pos = initial->pos;
  state.vel = initial->vel;

  acceleration(&state, &accel);
  
  Derivative output;
  output.dx = state.vel;
  output.dv = accel;
  return output;
}

Derivative evaluate(State * initial, Vector2D accel, float t, float dt, Derivative d) {
  State state;
  state.pos = initial->pos;
  state.vel = initial->vel;

  d.dx *= dt;
  d.dv *= dt;

  state.pos += d.dx;
  state.vel += d.dv;
  
  acceleration(&state, &accel);
  
  Derivative output;
  output.dx = state.vel;
  output.dv = accel;
  
  return output; 
}

void acceleration(State * state, Vector2D * accel) {
  if (accel->x == 0) {
    if (state->vel.x  < ACCEL_THRES && state->vel.x > -ACCEL_THRES) state->vel.x = 0;
    else if (state->vel.x > 0) accel->x = -(state->vel.x*0.98);
    else if (state->vel.x < 0) accel->x = -(state->vel.x*0.98);
  }

  if (accel->y == 0) {
    if (state->vel.y  < ACCEL_THRES && state->vel.y > -ACCEL_THRES) state->vel.y = 0;
    else if (state->vel.y > 0) accel->y = -(state->vel.y*0.8);
    else if (state->vel.y < 0) accel->y = -(state->vel.y*0.8);
  }

}

void integrate(State * state, Vector2D accel, float t, float dt) {
  Derivative a = evaluate(state, accel, t);
  Derivative b = evaluate(state, accel, t, dt*0.5f, a);
  Derivative c = evaluate(state, accel, t, dt*0.5f, b);
  Derivative d = evaluate(state, accel, t, dt, c);

  c.dx *= 2.f;
  b.dx += c.dx;
  d.dx += b.dx;
  a.dx += d.dx;
  a.dx *= ((1.f/6.f)*dt);  

  c.dv *= 2.f;
  b.dv += c.dv;
  d.dv += b.dv;
  a.dv += d.dv;
  a.dv *= ((1.f/6.f)*dt);  

  state->pos += a.dx;
  state->vel += a.dv;
}

State interpolate(State prev, State curr, float alpha) {
  curr.pos *= alpha;
  curr.vel *= alpha;
  prev.pos *= (1-alpha);
  prev.vel *= (1-alpha);

  State state;
  state.pos = curr.pos;
  state.vel = curr.vel;

  state.pos += prev.pos;
  state.vel += prev.vel;

  return state;
}
