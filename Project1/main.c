#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "dfa.h"
#include "LinkedList.h"
#include "transition.h"
#include "table.h"
#include "dfa.h"

int main(int argc, char *argv[]) {
	printf("0");
	DFA d = new_DFA(9);

	printf("%d",DFA_get_size(d));
	printf("1");
	DFA_set_transition(d, 0, 'c', 1);
	printf("2");
//	DFA_set_transition(d, 1, 'o', 2);
//	printf("3");
//	DFA_set_transition(d, 2, 'm', 3);
//	printf("4");
//	DFA_set_transition(d, 3, 'p', 4);
//	DFA_set_transition(d, 4, 'u', 5);
//	DFA_set_transition(d, 5, 't', 6);
//	DFA_set_transition(d, 6, 'e', 7);
//	DFA_set_transition(d, 7, 'r', 8);
//
//	DFA_print(d);

}
