#ifndef TRANZITION_MAP_H
#define TRANZITION_MAP_H

#include "global.h"
#include "event_id.h"
#include "state_id.h"
#include "tranzition.h"


// Mapa prechodu
class TranzitionMap {
public:
	
	//TranzitionMap();

	// Nastaveni prechodu rizeneho udalosti
	void SetEventTranzition(StateId stateId, EventId eventId, StateId nextStateId);

	// Nastaveni prechodu rizeneho casem non IDLE stavu
	void SetDurationTranzition(
		StateId stateId,
		unsigned long nonIdleDurationMs,
		StateId nextState
	);
	
	// Reakce na udalost
	StateId GetNextStateEvent(StateId stateId, EventId eventId) const;

	// Reakce na cas
	StateId GetNextStateOnDuration(StateId stateId, unsigned long nonIdleDurationMs) const;
#ifndef ARDUINO
	void Print();
#endif
private:
	Tranzition _tranzitions[ST_COUNT];
};

#endif
