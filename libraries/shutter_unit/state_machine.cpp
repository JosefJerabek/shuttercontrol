#ifdef ARDUINO
    #include <Arduino.h>
#else
    #include <iostream>
    #include "event_id.h"  // GetEventName()
#endif

#include "state_machine.h"
#include "tranzition_map.h"


StateMachine::StateMachine(TranzitionMap & tranzitionMap, StateId initialState, unsigned char id) : 
_id(id),
_tranzitionMap(tranzitionMap), 
_state(initialState), 
_nonIdleSetTimeMs(0)
#ifdef DEBUG_STATE_MACHINE
,_debugLastPrintedTime(0)
,_debugLastPrintedDuration(0)
#endif
{
};


void StateMachine::OnTime(unsigned long timeMs) {
    unsigned long nonIdleDurationMs = _NonIdleDurationMs(timeMs);
// #ifdef DEBUG_STATE_MACHINE
//     unsigned int time = (unsigned int) timeMs / 1000;
//     if (_debugLastPrintedTime != time) {
//     #ifdef ARDUINO
//         Serial.print("SM");  
//         Serial.print(_id);
//         Serial.print(": time: ");
//         Serial.println(time);
//     #else
//         std::cout << "SM" << _id << ": time: " << time << std::endl; 
//     #endif
//         _debugLastPrintedTime = time;
//     }    
//     unsigned int duration = (unsigned int) nonIdleDurationMs / 1000;
//     if (_debugLastPrintedDuration != duration) {
//     #ifdef ARDUINO
//         Serial.print("SM");  
//         Serial.print(_id);
//         Serial.print(": duration: ");
//         Serial.println(duration);
//     #else
//         std::cout << "SM" << _id << ": duration: " << duration << std::endl; 
//     #endif
//         _debugLastPrintedDuration = duration;
//     }
// #endif
    StateId nextState = _tranzitionMap.GetNextStateOnDuration(_state, nonIdleDurationMs);
    if (nextState != _state) {
        _ChangeState(nextState, timeMs);
    }
};


void StateMachine::OnEvent(EventId eventId, unsigned long timeMs) {
#ifdef DEBUG_STATE_MACHINE
#ifdef ARDUINO
        Serial.print("SM");  
        Serial.print(_id);
        Serial.print(": event: ");
        Serial.println(eventId);
#else
        std::cout << "SM" << _id << ": event: " << GetEventName(eventId) << std::endl;
#endif
#endif
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
#ifdef DEBUG_STATE_MACHINE
#ifdef ARDUINO
        Serial.print("SM");  
        Serial.print(_id);
        Serial.print(": state: ");
        Serial.print(_state);
        Serial.print("->");
        Serial.println(newState);
#endif
#endif
        _state = newState;
    }
}