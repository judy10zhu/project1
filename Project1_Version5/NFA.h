#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "State.h"
#include "IntSet.h"

typedef struct NFA* NFA;


extern NFA new_nfa(int nstates);

extern int NFA_get_size(NFA nfa);//return the totalNumOfStates
extern State NFA_get_initialState(NFA nfa);//return the initial State

extern State NFA_find_state(NFA nfa, int src);//find the State of index src
extern NFA NFA_set_acceptingState(NFA nfa, int indexOfState);
extern void NFA_set_transition(NFA nfa, int src, char sym, int dst);
extern void NFA_set_transition_all(NFA nfa, int src, int dst);
extern void NFA_set_transition_all_remove (NFA nfa, int src, char remove, int dst);

extern IntSet NFA_get_transition(NFA nfa, int src, char sym);//Intset is a node whose data type is int and has next IntSet
extern bool NFA_get_accepting(NFA nfa, int state);

extern void NFA_print(NFA nfa);
extern void NFA_free(NFA nfa);
extern bool NFA_execute(NFA nfa, int currentState, char input[]);
