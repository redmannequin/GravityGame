#ifndef GAME_H
#define GAME_H

#include "./ocl.h"
#include "./defs.h"
#include "./game_defs.h"

class Game {
    
    public:
        Game();
        ~Game();

        int init(game_input*);
        int update();
        void render();

    private:
        OCL test;
        cl_float2 * data;
        cl_float2 * results;
        cl_float2 ** trail;
        game_input * keyboard;

        int j;

};

#endif