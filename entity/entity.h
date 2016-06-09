#ifndef ENTITY_H
#define ENTITY_H

#include "../game_defs.h"
#include "../vector2D.h"
#include "../defs.h"

class Entity {
  public:
    Entity();
    virtual ~Entity();

    virtual void init() = 0;
    virtual void update() = 0;
    virtual void draw(game_offscreen_buffer *, float) = 0;

  protected:
    float rot;
    Vector2D vel;
    Vector2D pos;
};

#endif
