#ifndef SHUTTER_CONTROL_H
#define SHUTTER_CONTROL_H


// Complete control of one shutter (zaluzie)
#include "global.h"

#include "platform_if.h"
#include "twin_button.h"
#include "state_machine.h"
#include "tranzition_map.h"

class ShutterUnit
{
public:

    // @param pressedTimeoutMs - [ms] doba stisku tlačítka pro klasifikaci jako "držení"
    // @param pullTimeMs - [ms] doba potřebná na sjetí / vytažení žaluzií
    // @param openTimeMs - [ms] doba potřebná na pootevření žaluzie poté co sjela dolů
    ShutterUnit(
        PlatformIf * platform,
        int pressedTimeoutMs,
        unsigned long pullTimeMs,
        unsigned long openTimeMs,
        unsigned char id
    );

    void Setup();
    
    void Loop();

private:
    unsigned long _pullTimeMs;
    unsigned long _openTimeMs;

    PlatformIf * _platform;
    TwinButton _twinButton;
    StateMachine _stateMachine;
    TranzitionMap _tranzitionMap;   
};




#endif /* SHUTTER_CONTROL_H */

