#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "State.h"
#include "NFA.h"
#include "IntSet.h"

typedef struct NFA* NFA;

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

void NFA_set_transition_all_remove (NFA nfa, int src, char remove, int dst){
    for (unsigned char c = 0; c < 128; c++){
        if(c == remove){
            continue;
        }else{
        NFA_set_transition(nfa, src, (char)c, dst);
        }
    }
}

IntSet NFA_get_transition(NFA nfa, int src, char sym){
	return NFA_search_char(NFA_find_state(nfa, src), sym);
}

bool NFA_get_accepting(NFA nfa, int state){
	return is_accept(NFA_find_state(nfa, state));
}

void NFA_print(NFA nfa){
	State search = nfa -> initialState;
	while(search != NULL){
		print_state(search);
		printf("\n");
		search = get_nextState(search);
	}
}

void NFA_free(NFA nfa){
	State search = nfa -> initialState;
	while(search != NULL){
		State next = get_nextState(search);
		free_state(search);
		search = next;
	}
}

bool NFA_execute(NFA nfa, int currentState, char input[]){
	if (input[0] == '\0'){
		return is_accept(NFA_find_state(nfa, currentState));
	}
	char currentChar = input[0];
	IntSet is = NFA_get_transition(nfa, currentState, currentChar);
	while(is != NULL){
		int nextState = IntSet_get_data(is);
		char str[strlen(input)-1];
		strncpy(str, input+1, strlen(input));
		bool result = NFA_execute(nfa, nextState, str);
		if (result){
			return true;
		}
		is = IntSet_get_next(is);
	}
	return false;

}

