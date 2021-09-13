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

	//ask user for input
    char userInput[256];
    printf("Enter your input: ");
    scanf("%s", &userInput);
	bool result = DFA_execute(d, userInput);
	printf("%d", result);

	//DFA for Any string that starts with 123
	DFA d = new_dfa(4);
	DFA_set_transition(d, 0, '1', 1);
	DFA_set_transition(d, 1, '2', 2);
	DFA_set_transition(d, 2, '3', 3);
	DFA_set_transition_all(d, 3, 3);
	DFA_set_acceptingState(d, 3);

	//ask user for input
	char userInput[256];
	printf("Enter your input: ");
	scanf("%s", &userInput);
	bool result = DFA_execute(d, userInput);
	printf("%d", result);

	//DFA for Binary input with an even number of 0’s and an even number of 1’s
	DFA d = new_dfa(4);
	DFA_set_transition(d, 0, '0', 1);
	DFA_set_transition(d, 1, '1', 2);
	DFA_set_transition(d, 2, '0', 3);
	DFA_set_transition(d, 3, '1', 0);
	DFA_set_transition(d, 0, '1', 3);
	DFA_set_transition(d, 1, '0', 0);
	DFA_set_transition(d, 2, '1', 1);
	DFA_set_transition(d, 3, '0', 2);
	DFA_set_acceptingState(d, 0);

	//ask user for input
	char userInput[256];
	printf("Enter your input: ");
	scanf("%s", &userInput);
	bool result = DFA_execute(d, userInput);
	printf("%d", result);

}
