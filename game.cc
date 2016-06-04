#include "game.h"

Game::Game(game_memory * memory, game_offscreen_buffer * buffer, game_input * input) {
    state = (game_state *) memory;
    if (!memory->init) {
        memory->init = 1;
        state->pos[0] = 0;
        state->pos[1] = 0;
    }
    this->buffer = buffer;
    this->input = input;
}

Game::~Game() {}

void Game::GameUpdateAndRender() {
    if (input->up.endDown && !input->down.endDown) {
        if (input->left.endDown) {
            // move left up
        } else if (input->right.endDown) {
            // move right up
        } else {
            // move up
            state->pos[1]--;
        }
    } else if (input->down.endDown) {
        if (input->left.endDown) {
            // move left down
        } else if (input->right.endDown) {
            // move right down
        } else {
            // move down
            state->pos[1]++;
        }
    } else {
        if (input->left.endDown) {
            // move left
            state->pos[0]--;
        } else if (input->right.endDown) {
            // move right
            state->pos[0]++;
        }
    }

    this->RenderGradient();

}

void Game::RenderGradient() {
    uint8_t* row = (uint8_t*)buffer->memory;
    for (int y=0; y < buffer->height; ++y) {
        uint32_t* pixel = (uint32_t*)row;
        for (int x=0; x < buffer->width; ++x) {
            uint8_t blue = 0, green = 0, red = 0;
            blue  = y+(state->pos[1]);
            green = x+(state->pos[0]);
            *pixel++ = ((red << 16) | (green << 8) | blue);
        }
        row += buffer->pitch;
    }
}

void Game::RenderTriangle() {}
bool Game::PnPoly() {return 0;}
