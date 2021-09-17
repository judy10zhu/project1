#include "IntSet.h"
#include "IntSetNode.h"
#include "IntSetTransition.h"
#include "Dictionary.h"
#include "NFA.h"
#include "DFA.h"
#include "Translator.h"
#include "TranslatorHelper.h"
#include "IntSetToInt.h"

TranslatorHelper Translator(NFA nfa, TranslatorHelper tsh){
	IntSetNode current = get_intSetNode(tsh);
	while (current != NULL){
		for (unsigned char c = 0; c < 128; c++){
			IntSet currentStateSet = IntSetNode_get_data(current);
			IntSet resultStates = NULL;

			while (currentStateSet != NULL){
				int currentState = IntSet_get_data(currentStateSet);
				IntSet currentResultStates = NFA_get_transition(nfa, currentState, c);
				if (currentResultStates != NULL){
					resultStates = IntSet_sorted_addAll(resultStates, currentResultStates);
				}
				currentStateSet = IntSet_get_next(currentStateSet);
			}

			if (resultStates != NULL){
				if (if_contains(get_intSetNode(tsh), resultStates)){
				}else{
					IntSetNode added = new_intSetNode(resultStates);
					IntSetNode temp = add_intSetNode(get_intSetNode(tsh), added);
					set_intSetNode(tsh, temp);
				}
				IntSetTransition ist = new_intSetTransition(c, resultStates);
				Dictionary nd = new_dictionary(IntSetNode_get_data(current), ist);
				set_dictionary(tsh, add_dictionary(get_dictionary(tsh), nd));
			}

		}
		current = IntSetNode_get_next(current);
	}
	return tsh;
}

DFA build_dfa(TranslatorHelper tsh, IntSet acceptingStates){
	int totalNumOfStates = IntSetNode_count(get_intSetNode(tsh));
	//build the IntSet to int LinkedList
	IntSetToInt isti = NULL;
	IntSetNode search = get_intSetNode(tsh);
	for (int i =0; i < totalNumOfStates; i ++){
		IntSetToInt temp = new_intSetToInt(IntSetNode_get_data(search), i);
		isti = set_nextIntSetToInt(isti, temp);
		search = IntSetNode_get_next(search);
	}
	DFA dfa = new_dfa(totalNumOfStates);
	Dictionary d = get_dictionary(tsh);
	while (d != NULL){
		int currentState = search_stateIndex(isti,  Dictionary_get_currentState(d));
		IntSetTransition ist = Dictionary_get_ist(d);
		char c = IntSetTransition_get_c(ist);
		int resultState = search_stateIndex(isti, IntSetTransition_get_dst(ist));
		DFA_set_transition(dfa, currentState, c, resultState);
		d = Dictionary_get_next(d);
	}

	//set the accepting States
	IntSet is = acceptingStates;
	while (is != NULL){
		IntSet guard = IntSet_get_next(is);
		IntSetToInt istisearching = isti;
		while (istisearching != NULL){
			IntSet data = get_stateIntSet(istisearching);
			if (IntSet_if_contains(data, is)){
				DFA_set_acceptingState(dfa, get_stateIndex(istisearching));
			}
			istisearching = get_nextIntSetToInt(istisearching);
		}
		is = guard;
	}
	return dfa;
}
