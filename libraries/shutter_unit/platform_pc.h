#ifndef PLATFORM_PC_H
#define PLATFORM_PC_H


// Realize input-output layer - prowide hardware / platform abstraction 
// * reading switch state
// * switching power
// * writing state number
// * reading time
// * Input logic: Pouzit PULL_UP rezistor, spinano nulou.

#include "platform_if.h"
#include "io_state.h"

class PlatformPc : public PlatformIf
{
public:
  
    /// Specifikuje jaké hodnoty mají kdy dávat vstupy (testovací scénář)
    struct InputSwitching {
        enum {PLATFORM_STATE_COUNT = 1000} e;    
        /// krok času
        int TimeStepMs;
        /// zadané hodnoty vypínače
        IoState Values[PLATFORM_STATE_COUNT];        
        int ValuesSize;
        
        InputSwitching();
    };
    
    PlatformPc(PlatformIf::Pinout pinout, InputSwitching inputSwitching);
    
    virtual void Setup();

    virtual unsigned long GetTimeMs();
    
    // udělat krok v čase
    void DoStep();

private:
    // zapouzdreni pro pripad, ze pin nenastaven (-1)
    virtual void _SetupPin(int number, int type);
    virtual void _WritePin(int number, int value);
    virtual int _ReadPin(int number);
    
    const InputSwitching _inputSwitching;
    int _step;
};


#endif // PLATFORM_H

