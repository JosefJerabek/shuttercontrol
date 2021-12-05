#include "tranzition.h"

Tranzition::Tranzition() {
    DurationMs = 0;               // časový přechod neaktivní
    DurationNextState = ST_NONE;   
    for (int iEvent = 0; iEvent < EV_COUNT; ++iEvent) {
        NextStates[iEvent] = ST_NONE;
    }
};
