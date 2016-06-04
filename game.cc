#include "game.h"
#include "polygon.h"

#include <iostream>

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
            state->pos.x -= 1;
            state->pos.y -= 1;
        } else if (input->right.endDown) {
            // move right up
            state->pos.x += 1;
            state->pos.y -= 1;
        } else {
            // move up
            state->pos.y -= 1.5;
        }
    } else if (input->down.endDown) {
        if (input->left.endDown) {
            // move left down
            state->pos.x -= 1;
            state->pos.y += 1;
        } else if (input->right.endDown) {
            // move right down
            state->pos.x += 1;
            state->pos.y += 1;
        } else {
            // move down
            state->pos.y += 1.5;
        }
    } else {
        if (input->left.endDown) {
            // move left
            state->pos.x -= 1;
        } else if (input->right.endDown) {
            // move right
            state->pos.x += 1;
        }
    }

    //this->RenderGradient();
    this->RenderTriangle();
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

void Game::RenderTriangle() {
    Vector2D triangle[3];
    float vertex[2] = {0, 0};
    triangle[0] = vertex;
    vertex[0] = 50.f;
    vertex[1] = 0.f;
    triangle[1] = vertex;
    vertex[0] = 25.f;
    vertex[1] = 40.f;
    triangle[2] = vertex;

    Polygon tri(3, triangle);
    Vector2D point;

    tri.Translate(state->pos);
    //tri.Rotate(90.f); //Bug

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
