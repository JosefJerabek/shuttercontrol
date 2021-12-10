#include "tranzition_map_fill_custom.h"

void tranzitionMapFillCustom(
    TranzitionMap & tranzitionMap,
    unsigned long pullTimeMs//,
    //unsigned long openTimeMs
) {   
    
    // ST_IDLE
    tranzitionMap.SetEventTranzition(ST_IDLE, EV_UP_CLICK, ST_OPEN_MAN);
    tranzitionMap.SetEventTranzition(ST_IDLE, EV_DN_CLICK, ST_CLOSE_MAN);
    
    // ST_OPEN_MAN
    tranzitionMap.SetEventTranzition(ST_OPEN_MAN, EV_UP_RELEASE, ST_IDLE);
    tranzitionMap.SetEventTranzition(ST_OPEN_MAN, EV_UP_PRESS, ST_PULL_UP);
    
    // ST_PULL_UP
    tranzitionMap.SetDurationTranzition(ST_PULL_UP, pullTimeMs, ST_IDLE);
    tranzitionMap.SetEventTranzition(ST_PULL_UP, EV_DN_CLICK, ST_IDLE);

    
    // ST_CLOSE_MAN       
    tranzitionMap.SetEventTranzition(ST_CLOSE_MAN, EV_DN_RELEASE, ST_IDLE);
    tranzitionMap.SetEventTranzition(ST_CLOSE_MAN, EV_DN_PRESS, ST_PULL_DN);
    
    // ST_PULL_DOWN
    tranzitionMap.SetDurationTranzition(ST_PULL_DN, pullTimeMs, ST_IDLE);
    tranzitionMap.SetEventTranzition(ST_PULL_DN, EV_UP_CLICK, ST_IDLE);
    
#ifndef ARDUINO
    tranzitionMap.Print();
#endif
};
