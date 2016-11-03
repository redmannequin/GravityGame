#include "game.h"
#include <GL/glew.h>
#include <cstdlib>
#include <cmath>
#include <ctime>

int randint(int a, int b) {
    int diff = std::abs(a-b);
    int rand = std::rand()%diff;
    return (rand+a);
}

Game::Game() {
    std::srand(std::time(0));
    data = new cl_float2[NUM_P];
    results = new cl_float2[NUM_P];
    trail = new cl_float2*[NUM_P];
}

Game::~Game() {
    delete[] data;
    delete[] results;
    for (int i=0; i < TRAIL; ++i) delete[] trail[i];
    delete[] trail;
    test.release();
}

int Game::init(game_input * key) {
    keyboard = key;
    j = 0;
    for (int i=0; i < NUM_P; ++i) {
        data[i].s0 = randint((-WIDTH/2)+PADDING, (WIDTH/2)-PADDING);
        data[i].s1 = randint((-HEIGHT/2)+PADDING, (HEIGHT/2)-PADDING);

        trail[i] = new cl_float2[TRAIL];
        for (int k=0; k < TRAIL; ++k) trail[i][k] = data[i];
    }

    return test.init(sizeof(cl_float2), NUM_P, "../src/kernel.cl");
}

int Game::update() {
    int err = test.run(data, results);
    if (err < 0) return err;
    for (int i=0; i < NUM_P; ++i) {
        float a = results[i].s0*results[i].s0;
        float o = results[i].s1*results[i].s1;
        float h = a + o;
        
        float l = std::sqrt(h);
        float x = (results[i].s0 / l) * MAX_VEL;
        float y = (results[i].s1 / l) * MAX_VEL;
        cl_float2 temp;
        temp.s0 = x;
        temp.s1 = y;

        results[i] = std::sqrt(h) > MAX_VEL ? temp  : results[i];
        data[i].s0 += results[i].s0;
        data[i].s1 += results[i].s1;
        trail[i][j] = data[i];
    }
    ++j;
    j %= TRAIL;
    return 1;
}

void Game::render() {
    glBegin(GL_POINTS);
    glColor3f(1, 0, 0);
    for (int i=0; i < NUM_P; ++i) {
        for (int k=0; k < TRAIL; ++k) {
            glVertex2f(trail[i][k].s0, trail[i][k].s1);
        }
    }
    glEnd();
}