#ifndef ENTITY_H
#define ENTITY_H

#include "../game_defs.h"
#include "../defs.h"

#include "../math/vector2D.h"

class Entity {
  public:
    Entity();
    virtual ~Entity() = 0;

    virtual void init() = 0;
    virtual void update() = 0;
    virtual void draw(float) = 0;

  protected:
    float _rot;
    Vector2D _pos;
};

#endif
