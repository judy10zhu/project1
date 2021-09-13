#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "State.h"
#include "NFA.h"

typedef struct NFA *NFA;

struct NFA{
	int totalNumOfStates;
	State initialState;
};

NFA new_nfa(int nstates){
	NFA nfa = (NFA)malloc(sizeof(struct NFA));
	nfa -> totalNumOfStates = nstates;
	if (nstates <= 0){
		nfa -> initialState = NULL;
		return nfa;
	}

	nfa -> initialState = new_state(0);
	State iterate = nfa -> initialState;
	for (int i = 1; i < nstates; i ++){
		State next = new_state(i);
		set_nextState(iterate, next);
		iterate = get_nextState(iterate);
	}
	return nfa;
}

int NFA_get_size(NFA nfa){
	return nfa -> totalNumOfStates;
}

State NFA_get_initialState(NFA nfa){
	return nfa -> initialState;
}

State NFA_find_state(NFA nfa, int src){
	State search = nfa -> initialState;
	while(search != NULL){
		if (get_stateNum(search) == src){
			return search;
		}
		search = get_nextState(search);
	}
	return NULL;
}

NFA NFA_set_acceptingState(NFA nfa, int indexOfState){
	set_accept(NFA_find_state(nfa, indexOfState), true);
	return nfa;
}

void NFA_set_transition(NFA nfa, int src, char sym, int dst){
	//find the state
	State srcState = NFA_find_state(nfa, src);
	if (srcState == NULL){
		printf("DFA_set_transition failed, no state %d", src);
	}
	//add transition
	add_transition(srcState, sym, dst);
}

void NFA_set_transition_all(NFA nfa, int src, int dst){
	for (unsigned char c = 0; c < 128; c++){
		NFA_set_transition(nfa, src, c, dst);
	}
}




//int DFA_get_transition(DFA dfa, int src, char sym){
//	return search_char(DFA_find_state(dfa, src), sym);
//}
//
//
//bool DFA_get_accepting(DFA dfa, int state){
//	return is_accept(DFA_find_state(dfa, state));
//}
//
//void DFA_print(DFA dfa){
//	State search = dfa -> initialState;
//	while(search != NULL){
//		print_state(search);
//		printf("\n");
//		search = get_nextState(search);
//	}
//}
//
//void DFA_free(DFA dfa){
//	State search = dfa -> initialState;
//	while(search != NULL){
//		State next = get_nextState(search);
//		free_state(search);
//		search = next;
//	}
//}
//
//bool DFA_execute(DFA dfa, char input[]){
//	int currentState = 0;
//	for(int i = 0; i < strlen(input); i ++){
//		char in = input[i];
//		int nextState = DFA_get_transition(dfa, currentState, in);
//		//printf("nextState: %d\n", nextState);
//		if (nextState == -1){
//			return false;
//		}
//		currentState = nextState;
//
//	}
//	bool result = DFA_get_accepting(dfa, currentState);
//	return result;
//}
