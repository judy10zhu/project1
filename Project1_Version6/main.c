#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "Transition.h"
#include "Node.h"
#include "State.h"
#include "DFA.h"
#include "NFA.h"
#include "IntSet.h"
#include "IntSetNode.h"
#include "IntSetTransition.h"
#include "Dictionary.h"
#include "Translator.h"
#include "TranslatorHelper.h"
#include "IntSetToInt.h"

int main() {
	//DFA for exactly "computer"
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

	printf("Testing DFA that recognizes exactly 'computer' ... \n");
	char userInput[256];
	while(1){
		printf("Enter an input ('quit' to quit):  ");
		fflush( stdout );//only for eclipse
		scanf("%s", userInput);
		if(strcmp(userInput, "quit")== 0){
			printf("\n");
			break;
		}else{
			printf("Result for input '%s' : %s \n", userInput, DFA_execute(d, userInput) ? "true \n" : "false \n");
		}
	}

	//DFA for Any string that starts with 123
	DFA sec = new_dfa(4);
	DFA_set_transition(sec, 0, '1', 1);
	DFA_set_transition(sec, 1, '2', 2);
	DFA_set_transition(sec, 2, '3', 3);
	DFA_set_transition_all(sec, 3, 3);
	DFA_set_acceptingState(sec, 3);

	printf("Testing DFA that recognizes string that starts with '123' ... \n");
	char userInput_sec[256];

	while(1){
		printf("Enter an input ('quit' to quit):  ");
		fflush( stdout );//only for eclipse
		scanf("%s", userInput_sec);
		if(strcmp(userInput_sec, "quit")== 0){
			printf("\n");
			break;
		}else{
			printf("Result for input '%s' : %s \n", userInput_sec, DFA_execute(sec, userInput_sec) ? "true \n" : "false \n");
		}
	}



	//DNA for any string that starts with either two 2's or three 3's
	DFA third = new_dfa(6);
	DFA_set_transition(third, 0, '2', 1);
	DFA_set_transition(third, 1, '2', 2);
	DFA_set_transition(third, 0, '3', 3);
	DFA_set_transition(third, 3, '3', 4);
	DFA_set_transition(third, 4, '3', 5);
	DFA_set_transition_all(third, 5, 5);
	DFA_set_transition_all(third, 2, 2);
	DFA_set_acceptingState(third, 2);
	DFA_set_acceptingState(third, 5);

	printf("Testing DFA that recognizes string that starts with either two 2's or three 3's ... \n");
	char userInput_third[256];

	while(1){
		printf("Enter an input ('quit' to quit):  ");
		fflush( stdout );//only for eclipse
		scanf("%s", userInput_third);
		if(strcmp(userInput_third, "quit")== 0){
			printf("\n");
			break;
		}else{
			printf("Result for input '%s' : %s \n", userInput_third, DFA_execute(third, userInput_third) ? "true \n" : "false \n");
		}
	}

	//DFA for Binary input with an even number of 0s and an even number of 1s
	DFA forth = new_dfa(4);
	DFA_set_transition(forth, 0, '0', 1);
	DFA_set_transition(forth, 1, '1', 2);
	DFA_set_transition(forth, 2, '0', 3);
	DFA_set_transition(forth, 3, '1', 0);
	DFA_set_transition(forth, 0, '1', 3);
	DFA_set_transition(forth, 1, '0', 0);
	DFA_set_transition(forth, 2, '1', 1);
	DFA_set_transition(forth, 3, '0', 2);
	DFA_set_acceptingState(forth, 0);

	printf("Testing DFA that recognizes Binary input with an even number of 0s and an even number of 1s... \n");

	char userInput_forth[256];

	while(1){
		printf("Enter an input ('quit' to quit):  ");
		fflush( stdout );//only for eclipse
		scanf("%s", userInput_forth);
		//fgets(userInput_forth, 256, stdin);
		if(strcmp(userInput_forth, "quit")== 0){
			printf("\n");
			break;
		}else{
			printf("Result for input '%s' : %s \n", userInput_forth, DFA_execute(forth, userInput_forth) ? "true \n" : "false \n");
		}
	}

	//Interesting Pattern: DFA for string which starts with 'hi'
	DFA fifth = new_dfa(3);
	DFA_set_transition(fifth, 0, 'h', 1);
	DFA_set_transition(fifth, 1, 'i', 2);
	DFA_set_transition_all(fifth, 2, 2);
	DFA_set_acceptingState(fifth, 2);

	printf("Testing DFA that recognizes for string which starts with 'hi'\n");
	char userInput_fifth[256];

	while(1){
		printf("Enter an input ('quit' to quit):  ");
		fflush( stdout );//only for eclipse
		scanf("%s", userInput_fifth);
		if(strcmp(userInput_fifth, "quit")== 0){
			printf("\n");
			break;
		}else{
			printf("Result for input '%s' : %s \n", userInput_fifth, DFA_execute(fifth, userInput_fifth) ? "true \n" : "false \n");
		}
	}

	//NFA Strings ending in "ter"
	NFA n1 = new_nfa(4);
	NFA_set_transition_all(n1, 0, 0);
	NFA_set_transition(n1, 0, 't', 1);
	NFA_set_transition(n1, 1, 'e', 2);
	NFA_set_transition(n1, 2, 'r', 3);
	NFA_set_acceptingState(n1, 3);
	printf("Testing NFA for strings ending in 'ter' ... \n");
	char userInput_n1[256];

	while(1){
		printf("Enter an input ('quit' to quit):  ");
		fflush( stdout );//only for eclipse
		scanf("%s", userInput_n1);
		if(strcmp(userInput_n1, "quit")== 0){
			printf("\n");
			break;
		}else{
			printf("Result for input '%s' : %s \n", userInput_n1, NFA_execute(n1, 0, userInput_n1) ? "true \n" : "false \n");
		}
	}

	//NFA Strings contain "ter"
	NFA n2 = new_nfa(4);
	NFA_set_transition_all(n2, 0, 0);
	NFA_set_transition_all(n2, 3, 3);
	NFA_set_transition(n2, 0, 't', 1);
	NFA_set_transition(n2, 1, 'e', 2);
	NFA_set_transition(n2, 2, 'r', 3);
	NFA_set_acceptingState(n2, 3);
	printf("Testing NFA for strings containing 'ter' ... \n");
	char userInput_n2[256];

	while(1){
		printf("Enter an input ('quit' to quit):  ");
		fflush( stdout );//only for eclipse
		scanf("%s", userInput_n2);
		if(strcmp(userInput_n2, "quit")== 0){
			printf("\n");
			break;
		}else{
			printf("Result for input '%s' : %s \n", userInput_n2, NFA_execute(n2, 0, userInput_n2) ? "true \n" : "false \n");
		}
	}

	//NFA3
	//Strings with more than one a, g, i, o, t, or u, or more than two cs or ns
	NFA n3 = new_nfa(19);
	NFA_set_transition_all(n3, 0, 0);
	NFA_set_transition(n3, 0, 'a', 1);
	// everything but a transition all
	NFA_set_transition_all_remove (n3, 1, 'a', 1);
	NFA_set_transition(n3, 1, 'a', 2);

	NFA_set_transition(n3, 0, 'g', 3);
	// everything but g transition all
	NFA_set_transition_all_remove (n3, 3, 'g', 3);
	NFA_set_transition(n3, 3, 'g', 4);

	NFA_set_transition(n3, 0, 'i', 5);
	// everything but i transition all
	NFA_set_transition_all_remove (n3, 5, 'i', 5);
	NFA_set_transition(n3, 5, 'i', 6);

	NFA_set_transition(n3, 0, 'u', 7);
	// everything but u transition all
	NFA_set_transition_all_remove (n3, 7, 'u', 7);
	NFA_set_transition(n3, 7, 'u', 8);

	NFA_set_transition(n3, 0, 'o', 9);
	// everything but o transition all
	NFA_set_transition_all_remove (n3, 9, 'a', 9);
	NFA_set_transition(n3, 9, 'o', 10);

	NFA_set_transition(n3, 0, 't', 11);
	// everything but t transition all
	NFA_set_transition_all_remove (n3, 11, 't', 11);
	NFA_set_transition(n3, 11, 't', 12);

	NFA_set_transition(n3, 0, 'c', 13);
	// everything but c transition all
	NFA_set_transition_all_remove (n3, 13, 'c', 13);
	NFA_set_transition(n3, 13, 'c', 14);
	// everything but c transition all
	NFA_set_transition_all_remove (n3, 14, 'c', 14);
	NFA_set_transition(n3, 14, 'c', 15);

	NFA_set_transition(n3, 0, 'n', 16);
	// everything but n transition all
	NFA_set_transition_all_remove (n3, 16, 'n', 16);
	NFA_set_transition(n3, 16, 'n', 17);
	// everything but n transition all
	NFA_set_transition_all_remove (n3, 17, 'n', 17);
	NFA_set_transition(n3, 17, 'n', 18);

	NFA_set_acceptingState(n3, 2);
	NFA_set_acceptingState(n3, 4);
	NFA_set_acceptingState(n3, 6);
	NFA_set_acceptingState(n3, 8);
	NFA_set_acceptingState(n3, 10);
	NFA_set_acceptingState(n3, 12);
	NFA_set_acceptingState(n3, 15);
	NFA_set_acceptingState(n3, 18);

	NFA_set_transition_all(n3, 2, 2);
	NFA_set_transition_all(n3, 4, 4);
	NFA_set_transition_all(n3, 6, 6);
	NFA_set_transition_all(n3, 8, 8);
	NFA_set_transition_all(n3, 10, 10);
	NFA_set_transition_all(n3, 12, 12);
	NFA_set_transition_all(n3, 15, 15);
	NFA_set_transition_all(n3, 18, 18);
	//Strings with more than one a, g, i, o, t, or u, or more than two cs or ns
	printf("Testing NFA for strings with more than one a, g, i, o, t, or u, or more than two cs or ns ... \n");
	char userInput_n3[256];

	while(1){
		printf("Enter an input ('quit' to quit):  ");
		fflush( stdout );//only for eclipse
		scanf("%s", userInput_n3);
		if(strcmp(userInput_n3, "quit")== 0){
			printf("\n");
			break;
		}else{
			printf("Result for input '%s' : %s \n", userInput_n3, NFA_execute(n3, 0, userInput_n3) ? "true \n" : "false \n");
		}
	}

	//NFA 4 interesting automaton
	NFA n_thx = new_nfa(4);
	NFA_set_transition_all(n_thx, 0, 0);
	NFA_set_transition(n_thx, 0, 't', 1);
	NFA_set_transition(n_thx, 1, 'h', 2);
	NFA_set_transition(n_thx, 2, 'x', 3);
	NFA_set_acceptingState(n_thx, 3);
	printf("Testing NFA for strings ending in 'thx'\n");
	char userInput_thx[256];

	while(1){
		printf("Enter an input ('quit' to quit):  ");
		fflush( stdout );//only for eclipse
		scanf("%s", userInput_thx);
		if(strcmp(userInput_thx, "quit")== 0){
			printf("\n");
			break;
		}else{
			printf("Result for input '%s' : %s \n", userInput_thx, NFA_execute(n_thx, 0, userInput_thx) ? "true \n" : "false \n");
		}
	}


	//Translator
	//nfa 1
	IntSet acceptingStates1 = NFA_get_all_acceptingStates(n1);
	TranslatorHelper tsh1 = new_translatorHelper();
	tsh1 = Translator(n1, tsh1);
	DFA d1 = build_dfa(tsh1, acceptingStates1);
	printf("Translating NFA which recognizes Strings ending in 'ter' to DFA ... \n");
	printf("The translated DFA has %d States.\n", DFA_get_size(d1));
	char userInput_d1[256];
	while(1){
		printf("Enter an input ('quit' to quit):  ");
		fflush( stdout );//only for eclipse
		scanf("%s", userInput_d1);
		if(strcmp(userInput_d1, "quit")== 0){
			printf("\n");
			break;
		}else{
			printf("Result for input '%s' : %s \n", userInput_d1, DFA_execute(d1, userInput_d1) ? "true \n" : "false \n");
		}
	}

	//nfa 2
	IntSet acceptingStates2 = NFA_get_all_acceptingStates(n2);
	TranslatorHelper tsh2 = new_translatorHelper();
	tsh2 = Translator(n2, tsh2);
	DFA d2 = build_dfa(tsh2, acceptingStates2);
	printf("Translating NFA which recognizes Strings containing 'ter' to DFA ... \n");
	printf("The translated DFA has %d States.\n", DFA_get_size(d2));
	char userInput_nTod2[256];
	while(1){
		printf("Enter an input ('quit' to quit):  ");
		fflush( stdout );//only for eclipse
		scanf("%s", userInput_nTod2);
		if(strcmp(userInput_nTod2, "quit")== 0){
			printf("\n");
			break;
		}else{
			printf("Result for input '%s' : %s \n", userInput_nTod2, DFA_execute(d2, userInput_nTod2) ? "true \n" : "false \n");
		}
	}


	//nfa 3
//	IntSet acceptingStates3 = NFA_get_all_acceptingStates(n3);
//	TranslatorHelper tsh3 = new_translatorHelper();
//	tsh3 = Translator(n3, tsh3);
//	DFA d3 = build_dfa(tsh3, acceptingStates3);
//	printf("Translating NFA which recognizes Strings with more than one a, g, i, o, t, or u, or more than two cs or ns... \n");
//	printf("The translated DFA has %d States.\n", DFA_get_size(d3));
//	char userInput_nTod3[256];
//	while(1){
//		printf("Enter an input ('quit' to quit):  ");
//		fflush( stdout );//only for eclipse
//		scanf("%s", userInput_nTod3);
//		if(strcmp(userInput_nTod3, "quit")== 0){
//			printf("\n");
//			break;
//		}else{
//			printf("Result for input '%s' : %s \n", userInput_nTod3, DFA_execute(d3, userInput_nTod3) ? "true \n" : "false \n");
//		}
//	}


}
