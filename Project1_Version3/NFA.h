#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "State.h"

typedef struct NFA *NFA;


extern NFA new_nfa(int nstates);

extern int NFA_get_size(NFA nfa);//return the totalNumOfStates
extern State NFA_get_initialState(NFA nfa);//return the initial State

extern State NFA_find_state(NFA nfa, int src);//find the State of index src
extern NFA NFA_set_acceptingState(NFA nfa, int indexOfState);
extern void NFA_set_transition(NFA nfa, int src, char sym, int dst);
extern void NFA_set_transition_all(NFA nfa, int src, int dst);


