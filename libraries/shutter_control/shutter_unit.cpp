#include "shutter_unit.h"

#include "tranzition_map_fill_custom.h"
#include "io_state_name.h"

IoState outputFunction(StateId state) {
	if (state == ST_OPEN_MAN || state == ST_PULL_UP || state == ST_PULL_DN_OPEN) {
		return IO_UP;
	}
	else if (state == ST_CLOSE_MAN || state == ST_PULL_DN || state == ST_PULL_DN_TO_OPEN) {
		return IO_DOWN;
	}	
    return IO_NONE;
};

ShutterUnit::ShutterUnit(
    PlatformIf * platform,
    int pressedTimeoutMs,
    unsigned long pullTimeMs,
    unsigned long openTimeMs
)
:
_pullTimeMs(pullTimeMs),
_openTimeMs(openTimeMs),
_stateMachine(_tranzitionMap, ST_IDLE),
_platform(platform),
_twinButton(pressedTimeoutMs)
{   
}


void ShutterUnit::Setup()
{
    _platform->Setup();   
     tranzitionMapFillCustom(_tranzitionMap, _pullTimeMs, _openTimeMs);
};


void ShutterUnit::Loop()
{
    unsigned int timeMs = _platform->GetTimeMs();

    IoState switchIoState = _platform->ReadSwitch();
    EventId eventId = _twinButton.Loop(timeMs, switchIoState);
    if (eventId != EV_NONE) {
        _stateMachine.OnEvent(eventId, timeMs);
    } else {
        _stateMachine.OnTime(timeMs);
    }

    // helper state output 
    StateId state = _stateMachine.GetState();
    _platform->WriteState(state);

    /*if ( (eventId == EV_UP_CLICK) || (eventId == EV_UP_PRESS)
            || (eventId == EV_UP_RELEASE) ) {
        _platform->WriteEvent(2);
    } else if ( (eventId == EV_DN_CLICK) || (eventId == EV_DN_PRESS)
            || (eventId == EV_DN_RELEASE) ) {
        _platform->WriteEvent(1);
    } else {
        _platform->WriteEvent(0);
    }*/
    
#ifndef ARDUINO
    printf("time=%06d switch=%s event=%s new_stateid=%s\n", 
            timeMs,
            GetIoStateName(switchIoState).c_str(), 
            GetEventName(eventId).c_str(),
            GetStateName(state).c_str());
#endif
    
    IoState out = outputFunction(state);
    _platform->WritePower(out);
    
};

