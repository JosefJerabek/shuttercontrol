#include "twin_button.h"

TwinButton::TwinButton(unsigned long pressedTimeout) : 
_upButton(pressedTimeout), _downButton(pressedTimeout)
{
};


EventId TwinButton::Loop(unsigned long timeMs, IoState ioState)
{
    bool upState = false;
    bool downState = false;
    if ( (ioState == IO_UP) || (ioState == IO_BOTH) ) {
        upState = true;
    }
    if ( (ioState == IO_DOWN) || (ioState == IO_BOTH) ) {
        downState = true;
    }

    const Button::Event eventUp = _upButton.Loop(timeMs, upState);
    const Button::Event eventDown = _downButton.Loop(timeMs, downState);
    
    switch (eventUp) {
        case Button::BT_EV_CLICK:
            return EV_UP_CLICK;
        case Button::BT_EV_PRESS:
            return EV_UP_PRESS;
        case Button::BT_EV_RELEASE:
            return EV_UP_RELEASE;
        case Button::BT_EV_NONE:
            break;
    };
    
    switch (eventDown) {
        case Button::BT_EV_CLICK:
            return EV_DOWN_CLICK;
        case Button::BT_EV_PRESS:
            return EV_DOWN_PRESS;
        case Button::BT_EV_RELEASE:
            return EV_DOWN_RELEASE;
        case Button::BT_EV_NONE:
            break;
    };
    
    return EV_NONE;    
};

