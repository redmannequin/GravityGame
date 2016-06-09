#ifndef PLAYER_H
#define PLAYER_H

#include "./entity.h"

class Player: public Entity {
  public:
    Player();
    ~Player();
    
    void init();
    void update();
    
  protected:
    
};

#endif
