#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dfa.h"
//#include "LinkedList.h"
#include "state.h"
#include "Node.h"
#include "transition.h"
//#include "table.h"


typedef struct DFA *DFA;

struct DFA{
	int numberOfStates;
	State states[];
};

DFA new_DFA(int nstates){
	DFA dfa = (DFA)malloc(sizeof(struct DFA));
	dfa -> numberOfStates = nstates;
	State s = (State)malloc(sizeof(struct State)*nstates + 1);
	memcpy(dfa -> states, s, sizeof(struct State)*nstates + 1);

	for (int i = 0; i < nstates; i ++){
		dfa -> states[i] = new_state();
	}
	return dfa;
}

void DFA_free(DFA dfa){
	for (int i = 0; i < dfa -> numberOfStates; i ++){
		free_state(dfa -> states[i]);
	}
	free(dfa -> states);
	free(dfa);
}

int DFA_get_size(DFA dfa){
	return dfa -> numberOfStates;
}

int DFA_get_transition(DFA dfa, int src, char sym){
	return search_char(dfa ->states[src], sym);
}

void DFA_set_transition(DFA dfa, int src, char sym, int dst){
	add_transition(dfa -> states[src], sym, dst);
}

void DFA_set_transition_all(DFA dfa, int src, int dst){
	char c;
	for (c = 'a'; c <= 'z'; c++){
		DFA_set_transition(dfa, src, c, dst);
	}
	for (c = 'A'; c <= 'Z'; c++){
		DFA_set_transition(dfa, src, c, dst);
	}
}

bool DFA_get_accepting(DFA dfa, int state){
	return is_accept(dfa -> states[state]);
}

//bool DFA_execute(DFA dfa, char *input){
//
//}

void DFA_print(DFA dfa){
	for (int i = 0; i < dfa -> numberOfStates; i ++){
		print_state(dfa -> states[i]);
	}
}


