#ifndef ENTITY_H
#define ENTITY_H

#include "game_defs.h"
#include "polygon.h"
#include "vector2D.h"

class Entity {
  public:
    Entity();
    ~Entity();

    void init();
    void update(Vector2D&);
    void draw(game_offscreen_buffer*);

  private:
    float rot;
    float acc;
    Vector2D vel;
    Vector2D pos;
    Polygon poly;
};

#endif
