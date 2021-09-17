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

int main(){
//	IntSet is = new_intSet(0);
//	IntSet is1 = new_intSet(1);
//	IntSet_sorted_addAll(is, is1);
//
//	IntSet is2 = new_intSet(0);
//	IntSet is3 = new_intSet(1);
//	IntSet_sorted_addAll(is2, is3);
//
//	IntSetToInt isti = new_intSetToInt(is, 0);
//	IntSetToInt isti1 = new_intSetToInt(is1, 1);
//	set_nextIntSetToInt(isti, isti1);
//	printf("%d",search_stateIndex(isti, is3));

//	//build the nfa
	NFA nfa = new_nfa(3);
	NFA_set_transition_all(nfa, 0, 0);
	NFA_set_transition(nfa, 0, 'e', 1);
	NFA_set_transition(nfa, 1, 'd', 2);
	NFA_set_acceptingState(nfa, 2);

	TranslatorHelper tsh = new_translatorHelper();
	tsh = Translator(nfa, tsh);
	DFA d = build_dfa(tsh);
	DFA_print(d);
//	print_translatorHelper(tsh);//print the translator table

}

//int main() {
//	//DFA for exactly "computer"
//	DFA d = new_dfa(9);
//	DFA_set_transition(d, 0, 'c', 1);
//	DFA_set_transition(d, 1, 'o', 2);
//	DFA_set_transition(d, 2, 'm', 3);
//	DFA_set_transition(d, 3, 'p', 4);
//	DFA_set_transition(d, 4, 'u', 5);
//	DFA_set_transition(d, 5, 't', 6);
//	DFA_set_transition(d, 6, 'e', 7);
//	DFA_set_transition(d, 7, 'r', 8);
//	DFA_set_acceptingState(d, 8);
//
//	printf("Testing DFA that recognizes exactly 'computer' ... \n");
//	char userInput[256];
//	while(1){
//		printf("Enter an input ('quit' to quit):  ");
//		fflush( stdout );//only for eclipse
//		scanf("%s", userInput);
//		if(strcmp(userInput, "quit")== 0){
//			printf("\n");
//			break;
//		}else{
//			printf("Result for input '%s' : %s \n", userInput, DFA_execute(d, userInput) ? "true \n" : "false \n");
//		}
//	}
//
//	//DFA for Any string that starts with 123
//	DFA sec = new_dfa(4);
//	DFA_set_transition(sec, 0, '1', 1);
//	DFA_set_transition(sec, 1, '2', 2);
//	DFA_set_transition(sec, 2, '3', 3);
//	DFA_set_transition_all(sec, 3, 3);
//	DFA_set_acceptingState(sec, 3);
//
//	printf("Testing DFA that recognizes string that starts with '123' ... \n");
//	char userInput_sec[256];
//
//	while(1){
//		printf("Enter an input ('quit' to quit):  ");
//		fflush( stdout );//only for eclipse
//		scanf("%s", userInput_sec);
//		if(strcmp(userInput_sec, "quit")== 0){
//			printf("\n");
//			break;
//		}else{
//			printf("Result for input '%s' : %s \n", userInput_sec, DFA_execute(sec, userInput_sec) ? "true \n" : "false \n");
//		}
//	}
//
//
//
//	//DNA for any string that starts with either two 2's or three 3's
//	DFA third = new_dfa(6);
//	DFA_set_transition(third, 0, '2', 1);
//	DFA_set_transition(third, 1, '2', 2);
//	DFA_set_transition(third, 0, '3', 3);
//	DFA_set_transition(third, 3, '3', 4);
//	DFA_set_transition(third, 4, '3', 5);
//	DFA_set_transition_all(third, 5, 5);
//	DFA_set_transition_all(third, 2, 2);
//	DFA_set_acceptingState(third, 2);
//	DFA_set_acceptingState(third, 5);
//
//	printf("Testing DFA that recognizes string that starts with either two 2's or three 3's ... \n");
//	char userInput_third[256];
//
//	while(1){
//		printf("Enter an input ('quit' to quit):  ");
//		fflush( stdout );//only for eclipse
//		scanf("%s", userInput_third);
//		if(strcmp(userInput_third, "quit")== 0){
//			printf("\n");
//			break;
//		}else{
//			printf("Result for input '%s' : %s \n", userInput_third, DFA_execute(third, userInput_third) ? "true \n" : "false \n");
//		}
//	}
//
//	//DFA for Binary input with an even number of 0¡¯s and an even number of 1¡¯s
//	DFA forth = new_dfa(4);
//	DFA_set_transition(forth, 0, '0', 1);
//	DFA_set_transition(forth, 1, '1', 2);
//	DFA_set_transition(forth, 2, '0', 3);
//	DFA_set_transition(forth, 3, '1', 0);
//	DFA_set_transition(forth, 0, '1', 3);
//	DFA_set_transition(forth, 1, '0', 0);
//	DFA_set_transition(forth, 2, '1', 1);
//	DFA_set_transition(forth, 3, '0', 2);
//	DFA_set_acceptingState(forth, 0);
//
//	printf("Testing DFA that recognizes Binary input with an even number of 0¡¯s and an even number of 1¡¯s... \n");
//
//	char userInput_forth[256];
//
//	while(1){
//		printf("Enter an input ('quit' to quit):  ");
//		fflush( stdout );//only for eclipse
//		scanf("%s", userInput_forth);
//		if(strcmp(userInput_forth, "quit")== 0){
//			printf("\n");
//			break;
//		}else{
//			printf("Result for input '%s' : %s \n", userInput_forth, DFA_execute(forth, userInput_forth) ? "true \n" : "false \n");
//		}
//	}
//
//	//Interesting Pattern: DFA for string which ends with 'ed'
//	DFA fifth = new_dfa(3);
//	DFA_set_transition(fifth, 0, 'i', 1);
//	DFA_set_transition(fifth, 1, 'n', 2);
//	DFA_set_transition(fifth, 0, 'e', 1);
//	DFA_set_transition(fifth, 1, 'd', 2);
//	DFA_set_transition(fifth, 2, 'i', 1);
//	DFA_set_transition(fifth, 2, 'e', 1);
//	DFA_set_transition_all(sec, 0, 0);
//	DFA_set_acceptingState(fifth, 2);
//
//	printf("Testing DFA that recognizes for string which ends with 'ed' or 'in'... \n");
//	char userInput_fifth[256];
//
//	while(1){
//		printf("Enter an input ('quit' to quit):  ");
//		fflush( stdout );//only for eclipse
//		scanf("%s", userInput_fifth);
//		if(strcmp(userInput_fifth, "quit")== 0){
//			printf("\n");
//			break;
//		}else{
//			printf("Result for input '%s' : %s \n", userInput_fifth, DFA_execute(fifth, userInput_fifth) ? "true \n" : "false \n");
//		}
//	}
//
//	//NFA Strings ending in "ter"
//	//	NFA n = new_nfa(4);
//	//	NFA_set_transition_all(n, 0, 0);
//	//	NFA_set_transition(n, 0, 't', 1);
//	//	NFA_set_transition(n, 1, 'e', 2);
//	//	NFA_set_transition(n, 2, 'r', 3);
//	//	NFA_set_acceptingState(n, 3);
//
//	//NFA Strings contain "ter"
//	//	NFA n = new_nfa(4);
//	//	NFA_set_transition_all(n, 0, 0);
//	//	NFA_set_transition_all(n, 3, 3);
//	//	NFA_set_transition(n, 0, 't', 1);
//	//	NFA_set_transition(n, 1, 'e', 2);
//	//	NFA_set_transition(n, 2, 'r', 3);
//	//	NFA_set_acceptingState(n, 3);
//
//	//NFA3
//	//Strings with more than one a, g, i, o, t, or u, or more than two c¡¯s or n¡¯s
//	NFA n3 = new_nfa(19);
//	NFA_set_transition_all(n3, 0, 0);
//	NFA_set_transition(n3, 0, 'a', 1);
//	// everything but a transition all
//	NFA_set_transition_all_remove (n3, 1, 'a', 1);
//
//	NFA_set_transition(n3, 1, 'a', 2);
//
//	NFA_set_transition(n3, 0, 'g', 3);
//	// everything but g transition all
//	NFA_set_transition_all_remove (n3, 3, 'g', 3);
//	NFA_set_transition(n3, 3, 'g', 4);
//
//	NFA_set_transition(n3, 0, 'i', 5);
//	// everything but i transition all
//	NFA_set_transition_all_remove (n3, 5, 'i', 5);
//	NFA_set_transition(n3, 5, 'i', 6);
//
//	NFA_set_transition(n3, 0, 'u', 7);
//	// everything but u transition all
//	NFA_set_transition_all_remove (n3, 7, 'u', 7);
//	NFA_set_transition(n3, 7, 'u', 8);
//
//	NFA_set_transition(n3, 0, 'o', 9);
//	// everything but o transition all
//	NFA_set_transition_all_remove (n3, 9, 'a', 9);
//	NFA_set_transition(n3, 9, 'o', 10);
//
//	NFA_set_transition(n3, 0, 't', 11);
//	// everything but t transition all
//	NFA_set_transition_all_remove (n3, 11, 't', 11);
//	NFA_set_transition(n3, 11, 't', 12);
//
//	NFA_set_transition(n3, 0, 'c', 13);
//	// everything but c transition all
//	NFA_set_transition_all_remove (n3, 13, 'c', 13);
//	NFA_set_transition(n3, 13, 'c', 14);
//	// everything but c transition all
//	NFA_set_transition_all_remove (n3, 14, 'c', 14);
//	NFA_set_transition(n3, 14, 'c', 15);
//
//	NFA_set_transition(n3, 0, 'n', 16);
//	// everything but n transition all
//	NFA_set_transition_all_remove (n3, 16, 'n', 16);
//	NFA_set_transition(n3, 16, 'n', 17);
//	// everything but n transition all
//	NFA_set_transition_all_remove (n3, 17, 'n', 17);
//	NFA_set_transition(n3, 17, 'n', 18);
//
//	NFA_set_acceptingState(n3, 2);
//	NFA_set_acceptingState(n3, 4);
//	NFA_set_acceptingState(n3, 6);
//	NFA_set_acceptingState(n3, 8);
//	NFA_set_acceptingState(n3, 10);
//	NFA_set_acceptingState(n3, 12);
//	NFA_set_acceptingState(n3, 15);
//	NFA_set_acceptingState(n3, 18);
//
//	NFA_set_transition_all(n3, 2, 2);
//	NFA_set_transition_all(n3, 4, 4);
//	NFA_set_transition_all(n3, 6, 6);
//	NFA_set_transition_all(n3, 8, 8);
//	NFA_set_transition_all(n3, 10, 10);
//	NFA_set_transition_all(n3, 12, 12);
//	NFA_set_transition_all(n3, 15, 15);
//	NFA_set_transition_all(n3, 18, 18);
//	//Strings with more than one a, g, i, o, t, or u, or more than two c¡¯s or n¡¯s
//	printf("Testing NFA for strings with more than one a, g, i, o, t, or u, or more than two c¡¯s or n¡¯s ... \n");
//	char userInput_n3[256];
//
//	while(1){
//		printf("Enter an input ('quit' to quit):  ");
//		fflush( stdout );//only for eclipse
//		scanf("%s", userInput_n3);
//		if(strcmp(userInput_n3, "quit")== 0){
//			printf("\n");
//			break;
//		}else{
//			printf("Result for input '%s' : %s \n", userInput_n3, NFA_execute(n3, 0, userInput_n3) ? "true \n" : "false \n");
//		}
//	}
//
//}
//int main() {
//	NFA n = new_nfa(4);
//	NFA_set_transition_all(n, 0, 0);
//	//NFA_set_transition_all(n, 3, 3);
//	NFA_set_transition(n, 0, 't', 1);
//	NFA_set_transition(n, 1, 'e', 2);
//	NFA_set_transition(n, 2, 'r', 3);
//	NFA_set_acceptingState(n, 3);
//
//	printf("%d", NFA_execute(n, 0, "aterte"));
//////
//	NFA_print(n);
//
////	IntSet is = NFA_get_transition(n, 1, 'c');
////	print_IntSet(is);
////	IntSet next = IntSet_get_next(is);
////	while(next != NULL){
////		print_IntSet(next);
////		next = IntSet_get_next(next);
////	}
//	//print_state();
////	IntSet is = NFA_search_char(NFA_find_state(n, 1), 'a');
////	print_IntSet(is);
//
//
//
//
////	IntSet is = new_intSet(0);
////	print_IntSet(is);
////	IntSet_set_next(is, new_intSet(1));
////	print_IntSet(IntSet_get_next(is));
//
//
//
//
//////	NFA_set_acceptingState(n, 2);
////	print_state(NFA_find_state(n, 1));
////	//printf("%d", NFA_get_size(n));
//
//
//
//
//
//
//
////	//DFA for "computer"
////	DFA d = new_dfa(9);
////	DFA_set_transition(d, 0, 'c', 1);
////	DFA_set_transition(d, 1, 'o', 2);
////	DFA_set_transition(d, 2, 'm', 3);
////	DFA_set_transition(d, 3, 'p', 4);
////	DFA_set_transition(d, 4, 'u', 5);
////	DFA_set_transition(d, 5, 't', 6);
////	DFA_set_transition(d, 6, 'e', 7);
////	DFA_set_transition(d, 7, 'r', 8);
////	DFA_set_acceptingState(d, 8);
////////	//DFA_print(d);
//////
////	bool result = DFA_execute(d, "1512656");
////	printf("%d", result);
//
////	//DFA for starting with "123"
////	DFA d = new_dfa(4);
////	DFA_set_transition(d, 0, '1', 1);
////	DFA_set_transition(d, 1, '2', 2);
////	DFA_set_transition(d, 2, '3', 3);
////	DFA_set_transition_all(d, 3, 3);
////	DFA_set_acceptingState(d, 3);
////
////	bool result = DFA_execute(d, "266");
////	printf("%d", result);
//
//	//starts with either two 2¡¯s or three 3¡¯s//wrong
////	DFA d = new_dfa(5);
////	DFA_set_transition(d, 0, '2', 1);
////	DFA_set_transition(d, 1, '2', 2);
////	DFA_set_transition_all(d, 2, 2);
////	DFA_set_transition(d, 0, '3', 3);
////	DFA_set_transition(d, 3, '3', 4);
////	DFA_set_transition_all(d, 4, 4);
////	DFA_set_acceptingState(d, 2);
////	DFA_set_acceptingState(d, 4);
////
////	bool result = DFA_execute(d, "22432522");
////	printf("%d", result);
//
////	//an even number of 0¡¯s and an even number of 1¡¯s
////	DFA d = new_dfa(5);
////	DFA_set_transition(d, 0, '0', 1);
////	DFA_set_transition(d, 0, '1', 2);
////	DFA_set_transition(d, 1, '0', 0);
////	DFA_set_transition(d, 1, '1', 3);
////	DFA_set_transition(d, 2, '0', 4);
////	DFA_set_transition(d, 2, '1', 0);
////	DFA_set_transition(d, 3, '0', 2);
////	DFA_set_transition(d, 3, '1', 1);
////	DFA_set_transition(d, 4, '0', 2);
////	DFA_set_transition(d, 4, '1', 1);
////	DFA_set_acceptingState(d, 0);
////
////	bool result = DFA_execute(d, "0101");
////	printf("%d", result);
//
//	//printf("%d", DFA_get_accepting(d, 4));
//	//print_state(get_nextState(DFA_get_initialState(d)));
//	//print_state(DFA_find_state(d, 1));
//
//
////
//	//printf("%d", DFA_get_size(d));
////	State s1 = new_state(0);
////	add_transition(s1, 'c', 1);
////	print_state(s1);
////
////	State s2 = new_state(1);
////	add_transition(s2, 'o', 2);
////	set_nextState(s1, s2);
////
////	State s3 = new_state(2);
////	add_transition(s3, 'm', 3);
////	set_nextState(s2, s3);
////
////	State s4 = new_state(3);
////	add_transition(s4, 'p', 4);
////	set_nextState(s3, s4);
////
////	State s5 = new_state(4);
////	add_transition(s5, 'u', 5);
////	set_nextState(s4, s5);
////
////	State s6 = new_state(5);
////	add_transition(s6, 't', 6);
////	set_nextState(s5, s6);
////
////	State s7 = new_state(6);
////	add_transition(s7, 'e', 7);
////	set_nextState(s6, s7);
////
////	State s8 = new_state(7);
////	set_accept(s8, true);
////	add_transition(s8, 'r', 8);
////	set_nextState(s7, s8);
////
////	State s = get_nextState(s1);
////	while(s != NULL){
////		print_state(s);
////		s = get_nextState(s);
////	}
//
//
////	printf("%d", search_char(s1, 'o'));
////	free_state(s1);
//
//	//    DFA d = new_DFA(9);g
//	//
//	//    printf("%d \n",DFA_get_size(d));
//	//    DFA_set_transition(d, 0, 'c', 1);
//	//    DFA_set_transition(d, 1, 'o', 2);
//	//    DFA_set_transition(d, 2, 'm', 3);
//	//    DFA_set_transition(d, 3, 'p', 4);
//	//    DFA_set_transition(d, 4, 'u', 5);
//	//    DFA_set_transition(d, 5, 't', 6);
//	//    DFA_set_transition(d, 6, 'e', 7);
//	//    DFA_set_transition(d, 7, 'r', 8);
//	//
//	//    printf("done \n");
//	//
//	//    DFA_print(d);
//
//}
