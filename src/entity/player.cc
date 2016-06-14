#include "./player.h"


Player::Player() {}

Player::~Player() {}

void Player::init() {
  
  _poly.setPolygon(3, 10);

  _dx = 0;
  _dv = 0;
  _pos = 0;
  _vel = 0;
  _rot = 0;

  _curr.pos = _pos;
  _curr.vel = _vel;

  _prev.pos = _pos;
  _prev.vel = _vel;
}

// updater
void Player::update(){}

void Player::update(Vector2D * input, float t, float dt) {

  _prev.pos = _curr.pos;
  _prev.vel = _curr.vel;

  Vector2D accel = *input;
  _curr.pos = _pos;
  _curr.vel = _vel;

  integrate(&_curr, accel, t, dt);

  _pos = _curr.pos;
  _vel = _curr.vel;

  
}

// draw
void Player::draw(float i) {  
  State temp = interpolate(_prev, _curr, i);
  _poly += temp.pos;

  _poly.draw();

  _poly -= temp.pos;
}

