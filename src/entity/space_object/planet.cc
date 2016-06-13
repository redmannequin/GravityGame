#include "./planet.h"

Planet::Planet() {}

Planet::~Planet() {}

void Planet::init() {
  this->poly.setPolygon(6, 12);
  this->pos = 200;
}

// updater
void Planet::update(){}


// draw
void Planet::draw(game_offscreen_buffer * buffer, float i) {

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

}

