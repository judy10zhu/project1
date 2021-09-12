#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "Transition.h"
#include "Node.h"
#include "State.h"
#include "DFA.h"


int main() {
	//DFA for "computer"
	DFA d = new_dfa(9);
	DFA_set_transition(d, 0, 'c', 1);
	DFA_set_transition(d, 1, 'o', 2);
	DFA_set_transition(d, 2, 'm', 3);
	DFA_set_transition(d, 3, 'p', 4);
	DFA_set_transition(d, 4, 'u', 5);
	DFA_set_transition(d, 5, 't', 6);
	DFA_set_transition(d, 6, 'e', 7);
	DFA_set_transition(d, 7, 'r', 8);
	DFA_set_acceptingState(d, 8);

	DFA_print(d);
	DFA_free(d);
	//printf("%d", DFA_get_accepting(d, 4));
	//print_state(get_nextState(DFA_get_initialState(d)));
	//print_state(DFA_find_state(d, 1));


//
	//printf("%d", DFA_get_size(d));
//	State s1 = new_state(0);
//	add_transition(s1, 'c', 1);
//	print_state(s1);
//
//	State s2 = new_state(1);
//	add_transition(s2, 'o', 2);
//	set_nextState(s1, s2);
//
//	State s3 = new_state(2);
//	add_transition(s3, 'm', 3);
//	set_nextState(s2, s3);
//
//	State s4 = new_state(3);
//	add_transition(s4, 'p', 4);
//	set_nextState(s3, s4);
//
//	State s5 = new_state(4);
//	add_transition(s5, 'u', 5);
//	set_nextState(s4, s5);
//
//	State s6 = new_state(5);
//	add_transition(s6, 't', 6);
//	set_nextState(s5, s6);
//
//	State s7 = new_state(6);
//	add_transition(s7, 'e', 7);
//	set_nextState(s6, s7);
//
//	State s8 = new_state(7);
//	set_accept(s8, true);
//	add_transition(s8, 'r', 8);
//	set_nextState(s7, s8);
//
//	State s = get_nextState(s1);
//	while(s != NULL){
//		print_state(s);
//		s = get_nextState(s);
//	}


//	printf("%d", search_char(s1, 'o'));
//	free_state(s1);

	//    DFA d = new_DFA(9);g
	//
	//    printf("%d \n",DFA_get_size(d));
	//    DFA_set_transition(d, 0, 'c', 1);
	//    DFA_set_transition(d, 1, 'o', 2);
	//    DFA_set_transition(d, 2, 'm', 3);
	//    DFA_set_transition(d, 3, 'p', 4);
	//    DFA_set_transition(d, 4, 'u', 5);
	//    DFA_set_transition(d, 5, 't', 6);
	//    DFA_set_transition(d, 6, 'e', 7);
	//    DFA_set_transition(d, 7, 'r', 8);
	//
	//    printf("done \n");
	//
	//    DFA_print(d);

}
