#ifndef ENEMY_h
#define ENEMY_H

#include "./entity.h"

class Enemy : public Entity {
  public:
    Enemy();
    ~Enemy();

    void init();
    void update();

  protected:
    
};

#endif
