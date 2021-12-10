#ifndef SHUTTER_CONTROL_H
#define SHUTTER_CONTROL_H


// Complete control of one shutter (zaluzie)
#include "global.h"

#include "platform_if.h"
#include "twin_button.h"
#include "state_machine.h"
#include "tranzition_map.h"

class ShutterControl
{
public:

    ShutterControl(PlatformIf * platform, int pressedTimeout, unsigned long pullTimeMs);

    void Setup();
    
    void Loop();

private:
    unsigned long _pullTimeMs;

    PlatformIf * _platform;
    TwinButton _twinButton;
    StateMachine _stateMachine;
    TranzitionMap _tranzitionMap;   
};




#endif /* SHUTTER_CONTROL_H */

