#include "tranzition_map.h"


void TranzitionMap::SetEventTranzition(StateId stateId, EventId eventId, StateId nextStateId) {
    _tranzitions[stateId].NextStates[eventId] = nextStateId;
};


void TranzitionMap::SetDurationTranzition(StateId stateId, 
        unsigned long durationMs, StateId nextState) 
{
   	_tranzitions[stateId].DurationMs = durationMs;
    _tranzitions[stateId].DurationNextState = nextState;
};


StateId TranzitionMap::GetNextStateEvent(StateId stateId, EventId eventId) const {
	return _tranzitions[stateId].NextStates[eventId];
};


StateId TranzitionMap::GetNextStateDuration(StateId stateId, 
        unsigned long durationMs) const 
{
    const Tranzition & tranzition = _tranzitions[stateId];
    if ( (tranzition.DurationMs > 0) &&  (durationMs >= tranzition.DurationMs) ) {
        return tranzition.DurationNextState;
    }
    else {
        return ST_NONE;
    }
};

#ifndef ARDUINO
void TranzitionMap::Print() {
    printf("Tranzition map:\n\n");
    printf("event ");
    for (int iEvent = 0; iEvent < EV_COUNT; ++iEvent) {
        printf("  %02d", iEvent);
    }
    printf("\n");
    printf("state ------------\n");
    for (int iState = 0; iState < ST_COUNT; ++iState) {
        printf("  %02d |", iState);
        Tranzition & tranzition = _tranzitions[iState];
        for (int iEvent = 0; iEvent < EV_COUNT; ++iEvent) {
            StateId nextStateId = tranzition.NextStates[iEvent];
            printf("  %02d", nextStateId);
        }
        printf("\n");
    }
    printf("\n");
};
#endif

