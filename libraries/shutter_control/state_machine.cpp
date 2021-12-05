#include "state_machine.h"
#include "tranzition_map.h"


StateMachine::StateMachine(TranzitionMap & tranzitionMap, StateId initialState) : 
_tranzitionMap(tranzitionMap), _state(initialState), _stateSetTimeMs(0)
{
};


void StateMachine::OnTime(unsigned long timeMs) {
    unsigned long duration = _StateDurationMs(timeMs);
    StateId nextState = _tranzitionMap.GetNextStateDuration(_state, duration);
    _ChangeState(nextState, timeMs);
};


void StateMachine::OnEvent(EventId eventId, unsigned long timeMs) {
   // zde cely stavovy automat
    if (eventId == EV_NONE) {        
        return;
    }

    StateId nextState = _tranzitionMap.GetNextStateEvent(_state, eventId);
    _ChangeState(nextState, timeMs);
};


StateId StateMachine::GetState() {
    return _state;
};


unsigned long StateMachine::_StateDurationMs(unsigned long timeMs) {
    // solve time overflow
    if (timeMs < _stateSetTimeMs) {
        _stateSetTimeMs = timeMs;
    }
    
    unsigned long ret = timeMs - _stateSetTimeMs;
    return ret;
};


void StateMachine::_ChangeState(StateId newState, unsigned long timeMs) {
    if (newState != ST_NONE) {
        _state = newState;
        _stateSetTimeMs = timeMs;
    }
}