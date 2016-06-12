#ifndef SPACE_OBJECT_H
#define SPACE_OBJECT_H

#include "./entity.h"

class SpaceObject : public Entity {
  public:
    SpaceObject();
    ~SpaceObject();

    void init();
    void update();
    void draw(game_offscreen_buffer * buffer, float i);

  protected:

};

#endif
