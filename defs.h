#ifndef DEFS_H
#define DEFS_H

#define PI 3.14159265359f
#define ArraySize(array) (sizeof(array) / sizeof((array)[0]))

#define Kilobytes(n) ((n)*1024)
#define Megabytes(n) (Kilobytes(n)*1024)
#define Gigabytes(n) (Megabytes(n)*1024)

#define TICKS_PER_SECOND 25
#define SKIP_TICKS (1000/TICKS_PER_SECOND)
#define MAX_FRAMESKIP 5

#endif 
