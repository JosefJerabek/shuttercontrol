#ifndef EVENT_TYPE_H
#define EVENT_TYPE_H

#include "global.h"

enum EventId {
    EV_UP_CLICK = 0,  // stisk tlacitka nahoru
    EV_UP_PRESS,      // drzeni tlacitka - dlouhy stisk tlacitka
    EV_UP_RELEASE,    // uvolneni tlacitka dolu
    EV_DOWN_CLICK,
    EV_DOWN_PRESS,    // drzeni tlacitka dolu
    EV_DOWN_RELEASE,
    EV_COUNT,         // pocet udalosti
    EV_NONE = -1      // zadna udalost
};


#ifndef ARDUINO

#include <string>
std::string GetEventName(EventId eventId);

#endif

#endif
