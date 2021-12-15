#include "tranzition.h"

Tranzition::Tranzition() {
    NonIdleDurationMs = 0;               // časový přechod neaktivní
    DurationNextState = ST_NONE;   
    for (int iEvent = 0; iEvent < EV_COUNT; ++iEvent) {
        NextStates[iEvent] = ST_NONE;
    }
};
