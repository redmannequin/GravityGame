#ifndef DEFS_H
#define DEFS_H

#define PI 3.14159265359f
#define ArraySize(array) (sizeof(array) / sizeof((array)[0]))

// GAME LOOP
#define TICKS_PER_SECOND 30
#define SKIP_TICKS (1000/TICKS_PER_SECOND)
#define MAX_FRAMESKIP 5

// WINDOW
#define WIDTH 720
#define HEIGHT 480

#define BOX 60
#define PADDING 10

// WALKER
#define TRAIL 10
#define STEP 250.f
#define SIZE 1

#define WALKERS 2000

//PHYSICS
#define NUM_P (64*100)
#define MAX_VEL 10

#define LOCAL 128

#endif 
