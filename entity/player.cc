#include "./player.h"

Player::Player() {}

Player::~Player() {}

void Player::init() {
  
  this->poly.setPolygon(3, 12);

  this->pos.x = 0;
  this->pos.y = 0;
  
  this->vel.x =0;
  this->vel.y =0;
 
  this->rot = 0;
}

void Player::update(){}

void Player::update(Vector2D * input) {
  this->vel = *input;
  this->pos += this->vel;
  //this->rot = this->rot >= 3.14 ? 0 : this->rot + 1;
  //this->poly.rot(this->rot);
}

void Player::draw(game_offscreen_buffer * buffer, float i) {
  Vector2D temp = this->pos;
  temp *= i;
  this->pos += temp;
  this->poly += this->pos;  

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

  this->poly -= this->pos;
  this->pos -= temp;
  //this->vel *= float(1/i);
}
