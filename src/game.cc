#include "./game.h"
#include "./math/vector2D.h"

#define ACCEL_MAX 800
#define ACCEL_FACTOR 20

Game::Game() {
  _state = 0;
  _input = 0;
  _player = 0;
}

Game::~Game() {}

// init
void Game::Init(game_memory * memory, game_input * input) {
  _state = (game_state *) memory->permanentStorage;
  if (!memory->init) {
    memory->init = 1;
    _state->accel.x = 0;
    _state->accel.y = 0;
    _state->player.init();
  }

  _input  = input;
  _player = &(_state->player);
}

void Game::Update(float t, float dt) {
  if (_input->up.endDown && !_input->down.endDown && _state->accel.y > -ACCEL_MAX) { 
    // up button
    _state->accel.y += ACCEL_FACTOR;
  } else if (!_input->up.endDown && _input->down.endDown && _state->accel.y < ACCEL_MAX) { 
    // down button
    _state->accel.y-= ACCEL_FACTOR;
  } else {
    // stops vertical acceleratnio
    _state->accel.y = 0;
  }

  if (_input->left.endDown && !_input->right.endDown && _state->accel.x > -ACCEL_MAX) {
    // left button down
    _state->accel.x -= ACCEL_FACTOR;
  } else if (!_input->left.endDown && _input->right.endDown && _state->accel.x < ACCEL_MAX) { 
    // right button down
    _state->accel.x += ACCEL_FACTOR;
  } else {
    // stops horizontal acceleration
    _state->accel.x = 0;
  }

  // updates the player pos
  _player->update(&_state->accel, t, dt);
}

// renders game
void Game::Render(float i) {
  _state->player.draw(i);
}
