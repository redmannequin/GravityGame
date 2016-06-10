#include "./game.h"
#include "./vector2D.h"

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
    this->state->pos.x = 0;
    this->state->pos.y = 0;
    this->state->player.init();
  }
  this->buffer = buffer;
  this->input  = input;
}

void Game::Update() {
  if (this->input->up.endDown && !this->input->down.endDown && this->state->pos.y > -6) this->state->pos.y--;
  else if (!this->input->up.endDown && this->input->down.endDown && this->state->pos.y < 6) this->state->pos.y++;
  else this->state->pos.y *= 0.9;
    
  if (this->input->left.endDown && !this->input->right.endDown && this->state->pos.x > -6) this->state->pos.x--;
  else if (!this->input->left.endDown && this->input->right.endDown && this->state->pos.x < 6) state->pos.x++;
  else this->state->pos.x *= 0.9;
  
  this->state->player.update(&this->state->pos);
}

// updates and renders to buffer game 
void Game::Render(float i) {
  this->state->player.draw(this->buffer, i);
}
