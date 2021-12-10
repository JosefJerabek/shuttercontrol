#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

#include "global.h"
#include "tranzition.h"
#include "tranzition_map.h"


class StateMachine
{
public:

	StateMachine(TranzitionMap & tranzitionMap, StateId initialState);

	void OnTime(unsigned long timeMs);

	void OnEvent(EventId eventId, unsigned long timeMs);

	StateId GetState();

private:
    
    unsigned long _NonIdleDurationMs(unsigned long timeMs);
    
    void _ChangeState(StateId stateId, unsigned long timeMs);
    
    StateId _state;
    unsigned long _nonIdleSetTimeMs;  // čas přechodu do jiného než IDLE stavu
    TranzitionMap & _tranzitionMap;
};

#endif
