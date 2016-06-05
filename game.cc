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
  if (input->up.endDown && !input->down.endDown) state->pos.y--;
  else if (input->down.endDown) state->pos.y++;
  else state->pos.y *= 0.8;
    
  if (input->left.endDown && !input->right.endDown) state->pos.x++;
  else if (input->right.endDown) state->pos.x--;
  else state->pos.x *= 0.8;
  
  state->player.update(state->pos);
  state->player.draw(buffer);

}
/*
void Game::RenderTriangle() {
  Vector2D triangle[3];
  triangle[0].x = 0;
  triangle[0].y = 0;
  triangle[1].x = 50.f;
  triangle[1].y = 0.f;
  triangle[2].x = 25.f;
  triangle[2].y = 50.f;

  Polygon tri(3, triangle);

  Vector2D point, vertex;

  vertex.x = -25;
  vertex.y = -43.3;

  tri.Translate(vertex);
  tri.Rotate(state->rot);
  vertex *= -1;
  tri.Translate(vertex);    
    
  tri.Translate(vertex);
  tri.Scale(state->scl);

  uint8_t* row = (uint8_t*)buffer->memory;
  for (int y=0; y < buffer->height; ++y) {
    uint32_t* pixel = (uint32_t*)row;
    for (int x=0; x < buffer->width; ++x) {
      uint8_t blue = 0, green = 0, red = 0;
      vertex[0] = x;
      vertex[1] = y;
      point = vertex;
      if (tri.PnPoly(point)) red = 200;
        *pixel++ = ((red << 16) | (green << 8) | blue);
      }
      row += buffer->pitch;
  }

  tri.Clear();
}
*/
