#include <stdio.h>
#include <stdlib.h>
#include "IntSet.h"
#include "IntSetNode.h"
#include "Dictionary.h"
#include "TranslatorHelper.h"

typedef struct TranslatorHelper* TranslatorHelper;

struct TranslatorHelper{
	IntSetNode isn;
	Dictionary d;
};

TranslatorHelper new_translatorHelper(){
	TranslatorHelper tsh = (TranslatorHelper)malloc(sizeof(struct TranslatorHelper));
	IntSet is = new_intSet(0);
	tsh -> isn = new_intSetNode(is);
	tsh -> d = NULL;
	return tsh;
}

void set_intSetNode(TranslatorHelper tsh, IntSetNode isn){
    tsh -> isn = isn;
}

void set_dictionary(TranslatorHelper tsh, Dictionary d){
    tsh -> d = d;
}

IntSetNode get_intSetNode(TranslatorHelper tsh){
    return tsh -> isn;
}

Dictionary get_dictionary(TranslatorHelper tsh){
    return tsh -> d;
}

void free_translatorHelper(TranslatorHelper tsh){
    free(tsh);
}

void print_translatorHelper(TranslatorHelper tsh){
    printf("IntSetNode: ");
    print_intSetNode(tsh -> isn);
    printf("Dictionary: \n");
    print_dictionary(tsh -> d);
    printf("\n");
}
