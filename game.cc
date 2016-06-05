#include "game.h"

Game::Game() {
  state = 0;
  input = 0;
  buffer = 0;
}
Game::~Game() {}

// init
void Game::Init(game_memory * memory, game_offscreen_buffer * buffer, game_input * input) {
  state = (game_state *) memory;
  if (!memory->init) {
    memory->init = 1;
    state->pos.x = 0;
    state->pos.y = 0;
    state->player.init();
  }
  this->buffer = buffer;
  this->input = input;
}

// updates and renders to buffer game 
void Game::GameUpdateAndRender() {
  if (input->up.endDown && !input->down.endDown && state->pos.y > -6) state->pos.y--;
  else if (!input->up.endDown && input->down.endDown && state->pos.y < 6) state->pos.y++;
  else state->pos.y *= 0.8;
    
  if (input->left.endDown && !input->right.endDown && state->pos.x > -6) state->pos.x--;
  else if (!input->left.endDown && input->right.endDown && state->pos.x < 6) state->pos.x++;
  else state->pos.x *= 0.8;
  
  state->player.update(state->pos);
  state->player.draw(buffer);
}
