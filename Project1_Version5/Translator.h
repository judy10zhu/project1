#include "NFA.h"
#include "TranslatorHelper.h"

extern TranslatorHelper Translator(NFA nfa, TranslatorHelper tsh);
//tsh has two variables: IntSetNode isn and Dictionary d
//IntSetNode isn stores all the State sets
//Dictionary d stores the IntSet of current State
//and an IntSetTransition(char, IntSet) that stores the result States of char c

extern DFA build_dfa(TranslatorHelper tsh);
//build the NFA using the TranslatorHelper
