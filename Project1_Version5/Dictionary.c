#include <stdio.h>
#include <stdlib.h>
#include "IntSet.h"
#include "IntSetTransition.h"
#include "Dictionary.h"

typedef struct Dictionary* Dictionary;

struct Dictionary{
	IntSet currentState;
	IntSetTransition ist;
	Dictionary next;
};

Dictionary new_dictionary(IntSet is, IntSetTransition ist){
	Dictionary d = (Dictionary)malloc(sizeof(struct Dictionary));
	d -> currentState = is;
	d -> ist = ist;
	d -> next = NULL;
	return d;
}

void print_dictionary(Dictionary d){
	while (d != NULL){
		printf("currentState: ");
		print_intSet(d -> currentState);
		printf("; IntSetTransition: ");
		print_intSetTransition(d -> ist);
		d = d -> next;
	}
}

Dictionary add_dictionary(Dictionary d, Dictionary added){
	if (d == NULL){
		d = added;
		return d;
	}
	Dictionary search = d;
	while(search -> next != NULL){
		search = search -> next;
	}
	search -> next = added;
	return d;
}
