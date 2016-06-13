#ifndef PLANET_H
#define PLANET_H

#include "../entity.h"
#include "../../vector2D.h"
#include "../../draw/polygon.h"

class Planet : public Entity {
  public:
    Planet();
    ~Planet();
    
    void init();
    void update();
    void draw(game_offscreen_buffer * buffer, float i);
    
  protected:
    Polygon poly;
};

#endif
