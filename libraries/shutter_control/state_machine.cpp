#include "state_machine.h"
#include "tranzition_map.h"


StateMachine::StateMachine(TranzitionMap & tranzitionMap, StateId initialState) : 
_tranzitionMap(tranzitionMap), _state(initialState), _nonIdleSetTimeMs(0)
{
};


void StateMachine::OnTime(unsigned long timeMs) {
    unsigned long nonIdleDuration = _NonIdleDurationMs(timeMs);
    StateId nextState = _tranzitionMap.GetNextStateOnDuration(_state, nonIdleDuration);
    if (nextState != _state) {
        _ChangeState(nextState, timeMs);
    }
};


void StateMachine::OnEvent(EventId eventId, unsigned long timeMs) {
   // zde cely stavovy automat
    if (eventId == EV_NONE) {        
        return;
    }

    StateId nextState = _tranzitionMap.GetNextStateEvent(_state, eventId);
    if (nextState != _state) {
        _ChangeState(nextState, timeMs);
    }
};


StateId StateMachine::GetState() {
    return _state;
};


unsigned long StateMachine::_NonIdleDurationMs(unsigned long timeMs) {
    // solve time overflow
    if (timeMs < _nonIdleSetTimeMs) {
        _nonIdleSetTimeMs = timeMs;
    }
    
    unsigned long ret = timeMs - _nonIdleSetTimeMs;
    return ret;
};


void StateMachine::_ChangeState(StateId newState, unsigned long timeMs) {
    if (newState != ST_NONE) {
        if (_state == ST_IDLE && newState != ST_IDLE) {
            _nonIdleSetTimeMs = timeMs;
        }
        _state = newState;
    }
}