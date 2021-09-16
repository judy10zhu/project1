#include "IntSet.h"
#include "IntSetNode.h"
#include "IntSetTransition.h"
#include "Dictionary.h"
#include "NFA.h"
#include "Translator.h"
#include "TranslatorHelper.h"

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
//		while (currentStateSet != NULL){
//			int currentState = IntSet_get_data(currentStateSet);
//
//			//			for (unsigned char c = 0; c < 128; c++){
//			//				IntSet resultStates = NFA_get_transition(nfa, currentState, c);
//			//				if (resultStates != NULL){
//			//					if (if_contains(get_intSetNode(tsh), resultStates)){
//			//					}else{
//			//						IntSetNode added = new_intSetNode(resultStates);
//			//						IntSetNode temp = add_intSetNode(get_intSetNode(tsh), added);
//			//						set_intSetNode(tsh, temp);
//			//					}
//			//					IntSetTransition ist = new_intSetTransition(c, resultStates);
//			//					Dictionary nd = new_dictionary(currentStateSet, ist);
//			//					Dictionary d = add_dictionary(get_dictionary(tsh), nd);
//			//					set_dictionary(tsh, d);
//			//				}
//			//			}
//			currentStateSet = IntSet_get_next(currentStateSet);
//		}
		current = IntSetNode_get_next(current);
	}
	return tsh;
}
