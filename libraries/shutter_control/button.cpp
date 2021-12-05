#include "button.h"

Button::Button(int pressedTimeoutMs) : 
_pressedTimeoutMs(pressedTimeoutMs), _pressedSended(false), 
_isPushed(false), _pushTimeMs(0)
{
};


Button::Event Button::Loop(unsigned long timeMs, bool isPushed)
{ 
    // timeMs overflow
    if ((_isPushed) && (timeMs < _pushTimeMs)) {
        _pushTimeMs = timeMs;
    }

    bool lastIsPushed = _isPushed;
    _isPushed = isPushed;
    
    if (isPushed != lastIsPushed) {
        if (isPushed) {
            _pushTimeMs = timeMs;
            _pressedSended = false;
            return BT_EV_CLICK;
        }
        else {
            _pushTimeMs = 0;
            return BT_EV_RELEASE;
        }
    }

    if (_IsPressed(timeMs) && (!_pressedSended) ) {
        _pressedSended = true;
        return BT_EV_PRESS;
    }
    
    return BT_EV_NONE;    
};


bool Button::_IsPressed(unsigned long timeMs) {
    if(_isPushed) {
        long durationMs = timeMs - _pushTimeMs;   
        return (durationMs >= _pressedTimeoutMs);
    }
    else {
        return false;
    }
        
}; 