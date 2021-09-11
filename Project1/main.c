#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "dfa.h"
#include "transition.h"
#include "dfa.h"

int main(int argc, char *argv[]) {
	DFA d = new_DFA(9);
	DFA_set_transition(d, 0, 'c', 1);
	DFA_set_transition(d, 1, 'o', 2);
	DFA_set_transition(d, 2, 'm', 3);
	DFA_set_transition(d, 3, 'p', 4);
	DFA_set_transition(d, 4, 'u', 5);
	DFA_set_transition(d, 5, 't', 6);
	DFA_set_transition(d, 6, 'e', 7);
	DFA_set_transition(d, 7, 'r', 8);
	State s = get_states(d,7);
	//set_accept(s[7], true);
//	DFA_print(d);

}
