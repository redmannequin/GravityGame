#ifndef GAME_DEFS_H
#define GAME_DEFS_H

#include <stdint.h>
#include "vector2D.h"

struct game_offscreen_buffer {
  int  width;
  int  height;
  int  pitch;
  void *memory;
};

struct game_memory {
  bool init;
  uint64_t permanentStorageSize;
  void*    permanentStorage;
  uint64_t transientStorageSize;
  void*    transientStorage;
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
      game_button_state escape;
    };
  };
};

#endif
