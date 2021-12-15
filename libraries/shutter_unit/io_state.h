#ifndef IO_STATE_H
#define IO_STATE_H

#include "global.h"

// obecny stav pro vypinac i motor
enum IoState {
    IO_NONE = 0,  // zadna akce 
    IO_UP,        // nahoru
    IO_DOWN,      // dolu
    IO_BOTH       // nahoru i dolu
};

#endif
