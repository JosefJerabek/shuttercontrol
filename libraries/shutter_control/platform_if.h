#ifndef PLATFORM_IF_H
#define PLATFORM_IF_H


// Realize input-output layer - prowide hardware / platform abstraction 
// * reading switch state
// * switching power
// * writing state number
// * reading time
// * Input logic: Pouzit PULL_UP rezistor, spinano nulou.

#include "global.h"
#include "io_state.h"


class PlatformIf
{
public:

    struct Pinout {        
        int SwitchUpPin;
        int SwitchDownPin;
        int PowerUpPin;
        int PowerDownPin; 
        int StatePin0;
        int StatePin1;
        int StatePin2;
        int EventPin0;
        int EventPin1;

        Pinout(
            int switchUpPin, int switchDownPin, 
            int powerUpPin, int powerDownPin, 
            int statePin0 = -1, int statePin1 = -1, int statePin2 = -1,
            int eventPin0 = -1, int eventPin1 = -1
        ) 
        : 
        SwitchUpPin(switchUpPin), SwitchDownPin(switchDownPin),
        PowerUpPin(powerUpPin), PowerDownPin(powerDownPin),
        StatePin0(statePin0), StatePin1(statePin1), StatePin2(statePin2),
        EventPin0(eventPin0), EventPin1(eventPin1)
        {
        };

        //Pinout(){};

    };
    
    PlatformIf(PlatformIf::Pinout pinout);
    
    virtual void Setup() = 0;

    IoState ReadSwitch();
    
    void WritePower(IoState state);
    
    // pomocná
    void WriteState(int state);
    
    // pomocná
    void WriteEvent(int event);

    virtual unsigned long GetTimeMs() = 0;

protected:
    // zapouzdreni pro pripad, ze pin nenastaven (-1)
    virtual void _SetupPin(int number, int type) = 0;
    virtual void _WritePin(int number, int value) = 0;
    virtual int _ReadPin(int number) = 0;

//private:
    Pinout _pinout;
};


#endif // PLATFORM_H

