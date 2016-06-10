#include "./game.h"
#include "./vector2D.h"

#define ACCEL_MAX 100
#define ACCEL_FACTOR 10

Game::Game() {
  state = 0;
  input = 0;
  buffer = 0;
}

Game::~Game() {}

// init
void Game::Init(game_memory * memory, game_offscreen_buffer * buffer, game_input * input) {
  this->state = (game_state *) memory->permanentStorage;
  if (!memory->init) {
    memory->init = 1;
    this->state->accel.x = 0;
    this->state->accel.y = 0;
    this->state->player.init();
  }
  this->buffer = buffer;
  this->input  = input;
}

void Game::Update(float t, float dt) {
  if (this->input->up.endDown && !this->input->down.endDown && this->state->accel.y > -ACCEL_MAX) this->state->accel.y -= ACCEL_FACTOR;
  else if (!this->input->up.endDown && this->input->down.endDown && this->state->accel.y < ACCEL_MAX) this->state->accel.y += ACCEL_FACTOR;
  else this->state->accel.y = 0;
    
  if (this->input->left.endDown && !this->input->right.endDown && this->state->accel.x > -ACCEL_MAX) this->state->accel.x -= ACCEL_FACTOR;
  else if (!this->input->left.endDown && this->input->right.endDown && this->state->accel.x < ACCEL_MAX) state->accel.x += ACCEL_FACTOR;
  else this->state->accel.x = 0;
  
  this->state->player.update(&this->state->accel, t, dt);
}

// updates and renders to buffer game 
void Game::Render(float i) {
  this->state->player.draw(this->buffer, i);
}
