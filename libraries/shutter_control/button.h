#ifndef BUTTON_H
#define BUTTON_H

// generator udalost z tlacitka
class Button
{
public:
    
    enum Event {
        BT_EV_NONE = 0,
        BT_EV_CLICK,      // zmacknuti
        BT_EV_PRESS,      // drzeni po urtou dobu
        BT_EV_RELEASE     // uvolneni
    };

    Button(int pressedTimeout);

    Event Loop(unsigned long timeMs, bool isPushed);

private:
    
    // tlacitko drzeno dele jak pozadovanou dobu
    bool _IsPressed(unsigned long timeMs);

    const unsigned long _pressedTimeoutMs;  // po jake dobe udalost PRESSED
    
    bool _isPushed;
    unsigned long _pushTimeMs; // validní jen když _isPushed == true
    bool _pressedSended;
};

#endif
