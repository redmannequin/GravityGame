#ifndef ENTITY_H
#define ENTITY_H

#include "../game_defs.h"
#include "../draw/draw.h"
#include "../vector2D.h"
#include "../defs.h"

class Entity {
  public:
    Entity();
    virtual ~Entity();

    virtual void init() = 0;
    virtual void update() = 0;
    void draw(game_offscreen_buffer*, float);

  protected:
    float rot;
    Vector2D vel;
    Vector2D pos;
    Draw obj;
};

#endif
