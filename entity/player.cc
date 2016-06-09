#include "./player.h"

Player::Player() {}

Player::~Player() {}

void Player::init() {
  
  this->poly.setPolygon(3, 5);

  this->pos.x = 0;
  this->pos.y = 0;
  
  this->vel.x =0;
  this->vel.y =0;
 
  this->rot = 0;
}

void Player::update() {}

void Player::draw(game_offscreen_buffer * buffer, float i) {
  
  Vector2D vertex;  
  uint8_t * row = (uint8_t*)buffer->memory;
  uint32_t * pixel;
  uint8_t blue, green, red;

  for (int y=0; y < buffer->height; ++y) {
    vertex.y = y;
    pixel = (uint32_t*)row;
    for (int x=0; x < buffer->width; ++x) {
      blue = green = red = 0;
      if (this->poly.PnPoly(vertex)) red = 200;
      red = 20;
      *pixel++ = ((red << 16) | (green << 8) | blue);
    }
    row += buffer->pitch;
  }

}
