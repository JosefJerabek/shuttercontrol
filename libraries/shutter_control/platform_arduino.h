#ifndef PLATFORM_ARDUINO_H
#define PLATFORM_RDUINO_H

#include "platform_if.h"

class PlatformArduino : public PlatformIf
{
public:
   
    PlatformArduino(PlatformIf::Pinout pinout);
    
    virtual void Setup();

    virtual unsigned long GetTimeMs();

private:
    // zapouzdreni pro pripad, ze pin nenastaven (-1)
    virtual void _SetupPin(int number, int type);
    virtual void _WritePin(int number, int value);
    virtual int _ReadPin(int number);
   
};


#endif // PLATFORM_H

