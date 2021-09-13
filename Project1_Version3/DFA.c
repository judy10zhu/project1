#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "State.h"
#include "DFA.h"


typedef struct DFA *DFA;

struct DFA{
	int totalNumOfStates;
	State initialState;
};

DFA new_dfa(int nstates){
	DFA dfa = (DFA)malloc(sizeof(struct DFA));
	dfa -> totalNumOfStates = nstates;
	if (nstates <= 0){
		dfa -> initialState = NULL;
		return dfa;
	}
	dfa -> initialState = new_state(0);
	State iterate = dfa -> initialState;
	for (int i = 1; i < nstates; i ++){
		State next = new_state(i);
		set_nextState(iterate, next);
		iterate = get_nextState(iterate);
	}
	return dfa;
}

int DFA_get_size(DFA dfa){
	return dfa -> totalNumOfStates;
}

State DFA_get_initialState(DFA dfa){
	return dfa -> initialState;
}

State DFA_find_state(DFA dfa, int src){
	State search = dfa -> initialState;
	while(search != NULL){
		if (get_stateNum(search) == src){
			return search;
		}
		search = get_nextState(search);
	}
	return NULL;
}

DFA DFA_set_acceptingState(DFA dfa, int indexOfState){
	set_accept(DFA_find_state(dfa, indexOfState), true);
	return dfa;
}

void DFA_set_transition(DFA dfa, int src, char sym, int dst){
	//find the state
	State srcState = DFA_find_state(dfa, src);
	if (srcState == NULL){
		printf("DFA_set_transition failed, no state %d", src);
	}
	//add transition
	add_transition(srcState, sym, dst);
}

void DFA_set_transition_all(DFA dfa, int src, int dst){
	for (unsigned char c = 0; c < 128; c++){
		DFA_set_transition(dfa, src, c, dst);
	}
}

int DFA_get_transition(DFA dfa, int src, char sym){
	return search_char(DFA_find_state(dfa, src), sym);
}


bool DFA_get_accepting(DFA dfa, int state){
	return is_accept(DFA_find_state(dfa, state));
}

void DFA_print(DFA dfa){
	State search = dfa -> initialState;
	while(search != NULL){
		print_state(search);
		printf("\n");
		search = get_nextState(search);
	}
}

void DFA_free(DFA dfa){
	State search = dfa -> initialState;
	while(search != NULL){
		State next = get_nextState(search);
		free_state(search);
		search = next;
	}
}

bool DFA_execute(DFA dfa, char input[]){
	int currentState = 0;
	for(int i = 0; i < strlen(input); i ++){
		char in = input[i];
		int nextState = DFA_get_transition(dfa, currentState, in);
		//printf("nextState: %d\n", nextState);
		if (nextState == -1){
			return false;
		}
		currentState = nextState;

	}
	bool result = DFA_get_accepting(dfa, currentState);
	return result;
}
