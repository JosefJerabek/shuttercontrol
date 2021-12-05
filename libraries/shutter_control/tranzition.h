#ifndef STATE_H
#define STATE_H

#include "global.h"
#include "state_id.h"
#include "event_id.h"

// obecny stav 
// vzdy na danou udalost reaguje na prechod do noveho stavu
// pokud ma nastvene nenulove trvani, pak po uplynuti doby trvani prechazi
// do k tomu zadanemu stavu

struct Tranzition {
public:

	Tranzition();

    StateId NextStates[EV_COUNT];  // uplatni se nezavisle na typu stavu
    unsigned long DurationMs;      // po jaké době přechod na stav DurationNextState
                                   // když nula tak k časovému přechodu nedojde
    StateId DurationNextState;     // novy stav po uplynuti trvani stavu
};

#endif
