#include "./game.h"

Game::Game() {
  input = 0;
}

Game::~Game() {}

// init
void Game::Init(game_input * in) {
  input  = in;
}

// game update
void Game::Update(float t, float dt) {
  UserInput();
}

// renders game
void Game::Render(float i) {
}

void Game::UserInput() {
  bool up    = (input->up.endDown && !input->down.endDown);
  bool down  = (!input->up.endDown && input->down.endDown);
  bool left  = (input->left.endDown && !input->right.endDown);
  bool right = (!input->left.endDown && input->right.endDown);
}
