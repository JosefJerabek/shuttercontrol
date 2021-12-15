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

        Pinout(
            int switchUpPin, int switchDownPin, 
            int powerUpPin, int powerDownPin
        ) 
        : 
        SwitchUpPin(switchUpPin), SwitchDownPin(switchDownPin),
        PowerUpPin(powerUpPin), PowerDownPin(powerDownPin)
        {
        };
    };
    
    PlatformIf(PlatformIf::Pinout pinout);
    
    virtual void Setup() = 0;

    IoState ReadSwitch();
    
    void WritePower(IoState state);
    
    virtual unsigned long GetTimeMs() = 0;

protected:
    virtual void _SetupPin(int number, int type) = 0;
    virtual void _WritePin(int number, int value) = 0;
    virtual int _ReadPin(int number) = 0;

//private:
    Pinout _pinout;
};


#endif // PLATFORM_H

