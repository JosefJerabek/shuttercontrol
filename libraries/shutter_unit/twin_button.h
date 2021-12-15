#ifndef TWIN_BUTTON_H
#define TWIN_BUTTON_H

#include "global.h"
#include "io_state.h"
#include "event_id.h"
#include "button.h"

// generator udalosti ze stavu vstupu
class TwinButton 
{
public:

    TwinButton(unsigned long pressedTimeout);

    EventId Loop(unsigned long timeMs, IoState ioState);

private:
    
    Button _upButton;
    Button _downButton;
   
};


#endif
