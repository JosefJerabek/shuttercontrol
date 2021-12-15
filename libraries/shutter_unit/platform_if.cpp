#include "platform_if.h"

#include "io_state_name.h"


PlatformIf::PlatformIf(PlatformIf::Pinout pinout) : _pinout(pinout)
{
};


IoState PlatformIf::ReadSwitch() 
{
    IoState state = IO_NONE;
    int up = !_ReadPin(_pinout.SwitchUpPin);
    int down = !_ReadPin(_pinout.SwitchDownPin);
    if (up & down) {     
      state = IO_BOTH;
    }
    else if (up) {
      state = IO_UP;
    }
    else if (down) {
      state = IO_DOWN;
    }
    else {
      state = IO_NONE;
    }
    return state;
};


void PlatformIf::WritePower(IoState state){
    int up = 0;
    int down = 0;

    if ( (state == IO_BOTH) || (state == IO_UP) ) { 
      up = 1;
    }
    if ( (state == IO_BOTH) || (state == IO_DOWN) ) { 
      down = 1;
    }

    _WritePin(_pinout.PowerUpPin, up);
    _WritePin(_pinout.PowerDownPin, down);
};
