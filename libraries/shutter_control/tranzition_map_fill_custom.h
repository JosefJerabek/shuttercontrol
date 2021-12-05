#ifndef TRANZITION_MAP_FILL_CUSTOM_H
#define TRANZITION_MAP_FILL_CUSTOM_H

#include "tranzition_map.h"


#define PULL_UP_TIME_MS   60000  // [ms] cas na vytazeni
#define PULL_DOWN_TIME_MS 60000  // [ms] cas na stazeni zaluzii

void tranzitionMapFillCustom(TranzitionMap & tranzitionMap);

#endif
