#ifndef STATE_ID_H
#define STATE_ID_H

#include "global.h"

enum StateId {
    ST_IDLE = 0,          // zaluzie stoji
    ST_OPEN_MAN,          // otviram dokud drzim tlacitko
    ST_CLOSE_MAN,         // priviram dokud drzim tlacitko
    ST_PULL_UP,           // uplne vytahnout nahoru
    ST_PULL_DN,           // uplne sjet dolu
    ST_PULL_DN_TO_OPEN,   // uplne sjet dolu a nasledne otevrit
    ST_PULL_DN_OPEN,      // otevreni po sjeti dolu
    ST_COUNT,             // pocet stavu
    ST_NONE = -1          // neplatny stav / stav nenastaven
};

#ifndef ARDUINO

#include <string>
std::string GetStateName(StateId stateId);
       
#endif
        
#endif
