#include "./player.h"

#define ACCEL_THRES 5.f

Player::Player() {}

Player::~Player() {}

void Player::init() {
  
  this->poly.setPolygon(6, 12);

  this->dx = 0;
  this->dv = 0;
  this->pos = 0;
  this->vel = 0;
  this->rot = 0;

  this->curr.pos = this->pos;
  this->curr.vel = this->vel;

  this->prev.pos = this->pos;
  this->prev.vel = this->vel;
}

// updater
void Player::update(){}

void Player::update(Vector2D * input, float t, float dt) {

  this->prev.pos = this->curr.pos;
  this->prev.vel = this->curr.vel;

  Vector2D accel = *input;
  this->curr.pos = this->pos;
  this->curr.vel = this->vel;

  this->integrate(&this->curr, accel, t, dt);

  this->pos = this->curr.pos;
  this->vel = this->curr.vel;

  
}

// draw
void Player::draw(game_offscreen_buffer * buffer, float i) {
  
  State temp = interpolate(this->prev, this->curr, i);
  this->poly += temp.pos;

  Vector2D vertex;  
  uint8_t * row = (uint8_t*)buffer->memory;
  uint8_t blue, green, red;

  for (int y=0; y < buffer->height; ++y) {
    vertex.y = y;
    uint32_t * pixel = (uint32_t*)row;
    for (int x=0; x < buffer->width; ++x) {
      vertex.x = x;
      blue = green = red = 0;
      if (this->poly.PnPoly(vertex)) red = 200;
      *pixel++ = ((red << 16) | (green << 8) | blue);
    }
    row += buffer->pitch;
  }
  this->poly -= temp.pos;
}

// physics 
Derivative Player::evaluate(State * initial, Vector2D accel, float t) {
  State state;
  state.pos = initial->pos;
  state.vel = initial->vel;

  acceleration(&state, &accel);
  
  Derivative output;
  output.dx = state.vel;
  output.dv = accel;
  return output;
}

Derivative Player::evaluate(State * initial, Vector2D accel, float t, float dt, Derivative d) {
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

void Player::acceleration(State * state, Vector2D * accel) {
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

void Player::integrate(State * state, Vector2D accel, float t, float dt) {
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

State Player::interpolate(State prev, State curr, float alpha) {
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
