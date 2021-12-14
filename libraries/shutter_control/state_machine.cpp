#include <Arduino.h>

#include "state_machine.h"
#include "tranzition_map.h"


StateMachine::StateMachine(TranzitionMap & tranzitionMap, StateId initialState, unsigned char id) : 
_id(id),
_tranzitionMap(tranzitionMap), 
_state(initialState), 
_nonIdleSetTimeMs(0),
// _debugLastPrintedTime(0),
// _debugLastPrintedDuration(0)
{
};


void StateMachine::OnTime(unsigned long timeMs) {
    unsigned long nonIdleDurationMs = _NonIdleDurationMs(timeMs);
// #ifdef ARDUINO
//     unsigned int time = (unsigned int) timeMs / 1000;
//     if (_debugLastPrintedTime != time) {
//         Serial.print("SM");  
//         Serial.print(_id);
//         Serial.print(": ");
//         Serial.print("time: ");
//         Serial.println(time);
//         _debugLastPrintedTime = time;
//     }    
//     unsigned int duration = (unsigned int) nonIdleDurationMs / 1000;
//     if (_debugLastPrintedDuration != duration) {
//         Serial.print("SM");  
//         Serial.print(_id);
//         Serial.print(": ");
//         Serial.print("duration: ");
//         Serial.println(duration);
//         _debugLastPrintedDuration = duration;
//     }    
// #endif
    StateId nextState = _tranzitionMap.GetNextStateOnDuration(_state, nonIdleDurationMs);
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
    if (_state == ST_IDLE) {
        return 0;
    }
    else {
        return timeMs - _nonIdleSetTimeMs;
    }
};


void StateMachine::_ChangeState(StateId newState, unsigned long timeMs) {
    if (newState != ST_NONE) {
        if (_state == ST_IDLE && newState != ST_IDLE) {
            _nonIdleSetTimeMs = timeMs;
        }
#ifdef ARDUINO
        Serial.print("SM");  
        Serial.print(_id);
        Serial.print(": ");
        Serial.print(_state);
        Serial.print("->");
        Serial.println(newState);
#endif
        _state = newState;
    }
}