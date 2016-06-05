#ifndef GAME_H
#define GAME_H

#include <stdint.h>
#include "vector2D.h"

struct game_state {
    Vector2D pos;
    float rot;
    float scl;
};

struct game_memory {
    bool init;
    uint64_t permanentStorageSize;
    void*    permanentStorage;
    uint64_t transientStorageSize;
    void*    transientStorage;
};

struct game_offscreen_buffer {
    int  width;
    int  height;
    int  pitch;
    void *memory;
};

struct game_button_state {
    bool endDown;
};

struct game_input {
    union {
        game_button_state buttns[0];
        struct {
            game_button_state up;
            game_button_state down;
            game_button_state left;
            game_button_state right;
        };
    };
};

class Game
{
    public:
        Game(game_memory * memory, game_offscreen_buffer * buffer, game_input * input);
        ~Game();
        void GameUpdateAndRender();

    private:
        game_state * state;
        game_input * input;
        game_offscreen_buffer * buffer;

        void RenderGradient();
        void RenderTriangle();
};

#endif // GAME_H
