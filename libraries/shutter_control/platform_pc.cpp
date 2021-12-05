#include "platform_pc.h"

#include "io_state_name.h"

#ifndef ARDUINO
#include <iostream>
#endif

PlatformPc::InputSwitching::InputSwitching() : ValuesSize(0), TimeStepMs(0) {
    for (int i = 0; i < PLATFORM_STATE_COUNT; ++i){
        Values[i] = IO_NONE;
    }
};


PlatformPc::PlatformPc(PlatformIf::Pinout pinout, InputSwitching inputSwitching) : 
PlatformIf(pinout), 
_inputSwitching(inputSwitching),
_step(0)
{
};


void PlatformPc::Setup()
{
    //std::cout << "setting bit " << _pin
};


unsigned long PlatformPc::GetTimeMs() {
    return _step * _inputSwitching.TimeStepMs;
};

void PlatformPc::DoStep() {
    ++_step;
}


void PlatformPc::_SetupPin(int number, int type){
    if (number >= 0) {
#ifndef ARDUINO
        std::cout << "SetupPin " << number << "to type: " << type << std::endl;
#endif
    }
};


void PlatformPc::_WritePin(int number, int value) {
    if (number >= 0) {
#ifndef ARDUINO        
    std::cout << "Write: pin_" << number << " = " << value << std::endl;
#endif
    }
};


int PlatformPc::_ReadPin(int number) {
    // pozor: PULL_UP logika - stisk je nula
    int ret = 1;
    
    const IoState switchState = _inputSwitching.Values[_step]; 
    if (number == _pinout.SwitchUpPin) {
        if ((switchState == IO_UP) || (switchState == IO_BOTH)) {
            ret = 0;
        }
    }
    else if (number == _pinout.SwitchDownPin) {
        if ((switchState == IO_DOWN) || (switchState == IO_BOTH)) {
            ret = 0;
        }
    }
#ifndef ARDUINO
    std::cout << "Read: pin_" << number << " = " << ret << std::endl;
#endif
    return ret;
};
