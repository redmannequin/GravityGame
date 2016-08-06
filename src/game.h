#ifndef GAME_H
#define GAME_H

#include "./defs.h"
#include "./game_defs.h"

class Game {
  public:
    Game();
    ~Game();

    void Init(game_input * input);
    void Update(float, float);
    void Render(float interpolation);

  private:
    game_input * input;
    void UserInput();
};

#endif

