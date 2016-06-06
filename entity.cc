#include "entity.h"

Entity::Entity() {
  init();
}

Entity::~Entity() {}

void Entity::init() {
  pos.x = 0;
  pos.y = 0;
  poly.setPolygon(3, 10);
 
  rot = 0;
  acc = 0; 
}

void Entity::update(Vector2D& mov) {
  // mov.x is used to rotate 
  // mov.y is used to accelrate
  poly.tran(mov);
}

void Entity::draw(game_offscreen_buffer * buffer) {
  Vector2D vertex;  
  uint8_t* row = (uint8_t*)buffer->memory;
  for (int y=0; y < buffer->height; ++y) {
    uint32_t* pixel = (uint32_t*)row;
    for (int x=0; x < buffer->width; ++x) {
      uint8_t blue = 0, green = 0, red = 0;
      vertex.x = x;
      vertex.y = y;
      if (poly.PnPoly(vertex)) red = 200;
      *pixel++ = ((red << 16) | (green << 8) | blue);
    }
    row += buffer->pitch;
  }
}
