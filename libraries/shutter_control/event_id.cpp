#include "event_id.h"

#ifndef ARDUINO

#include <string>

std::string GetEventName(EventId eventId)
{
    switch (eventId) {
        case EV_UP_CLICK:
            return("EV_UP_CLICK");
        case EV_UP_PRESS:
            return("EV_UP_PRESS");
        case EV_UP_RELEASE:
            return("EV_UP_RELEASE");
        case EV_DOWN_CLICK:
            return("EV_DOWN_CLICK");
        case EV_DOWN_PRESS:
            return("EV_DOWN_PRESS");
        case EV_DOWN_RELEASE:
            return("EV_DOWN_RELEASE");
        case EV_COUNT:
            return("EV_COUNT");
        case EV_NONE:
            return("EV_NONE");
    }
};

#endif