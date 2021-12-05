#include "state_id.h"

#ifndef ARDUINO

std::string GetStateName(StateId stateId)
{
    switch (stateId) {
        case ST_IDLE:
            return("ST_IDLE");
        case ST_OPEN_MAN:
            return("ST_OPEN_MAN");
        case ST_CLOSE_MAN:
            return("ST_CLOSE_MAN");
        case ST_PULL_UP:
            return("ST_PULL_UP");
        case ST_PULL_DN:
            return("ST_PULL_DN");
        case ST_PULL_DN_TO_OPEN:
            return("ST_PULL_DN_TO_OPEN");
        case ST_PULL_DN_OPEN:
            return("ST_PULL_DN_OPEN");
        case ST_COUNT:
            return("ST_COUNT");
        case ST_NONE:
            return ("ST_NONE");                    
    }
};

#endif