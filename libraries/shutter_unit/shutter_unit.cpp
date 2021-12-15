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
    unsigned long openTimeMs,
    unsigned char id
)
:
_pullTimeMs(pullTimeMs),
_openTimeMs(openTimeMs),
_stateMachine(_tranzitionMap, ST_IDLE, id),
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
    unsigned long timeMs = _platform->GetTimeMs();

    IoState switchIoState = _platform->ReadSwitch();
    EventId eventId = _twinButton.Loop(timeMs, switchIoState);
    if (eventId != EV_NONE) {
        _stateMachine.OnEvent(eventId, timeMs);
    } else {
        _stateMachine.OnTime(timeMs);
    }

#ifndef ARDUINO // NOTE: state can be printed out also in StateMachine
    StateId state = _stateMachine.GetState();
    printf("time=%06d switch=%s event=%s new_stateid=%s\n", 
            (unsigned int) timeMs,
            GetIoStateName(switchIoState).c_str(), 
            GetEventName(eventId).c_str(),
            GetStateName(state).c_str());
#endif
    
    IoState out = outputFunction(state);
    _platform->WritePower(out);
    
};

