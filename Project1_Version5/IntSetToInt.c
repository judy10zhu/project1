#include <stdio.h>
#include <stdlib.h>
#include "IntSet.h"
#include "IntSetToInt.h"

typedef struct IntSetToInt* IntSetToInt;

struct IntSetToInt{
	IntSet stateIntSet;
	int stateIndex;
	IntSetToInt next;
};

IntSetToInt new_intSetToInt(IntSet is, int i){
	IntSetToInt this = (IntSetToInt)malloc(sizeof(struct IntSetToInt));
	this -> stateIntSet = is;
	this -> stateIndex = i;
	this -> next = NULL;
	return this;
}

IntSetToInt set_nextIntSetToInt(IntSetToInt this, IntSetToInt added){
	if (this == NULL){
		this = added;
		return this;
	}
	IntSetToInt search = this;
	while (search -> next != NULL){
		search = search -> next;
	}
	search -> next = added;
	return this;
}

IntSet get_stateIntSet(IntSetToInt isti){
	return isti -> stateIntSet;
}

int get_stateIndex(IntSetToInt isti){
	return isti -> stateIndex;
}

void print_intSetToInt(IntSetToInt isti){
	IntSetToInt search = isti;
	while (search != NULL){
		printf("StateIntSet: ");
		print_intSet(search -> stateIntSet);
		printf("--Index: %d\n", search -> stateIndex);
		search = search -> next;
	}
}

int search_stateIndex(IntSetToInt isti, IntSet is){
	IntSetToInt search = isti;
	while (search != NULL){
		IntSet this = search -> stateIntSet;
		if (isSame_intSet(this, is)){
			return search -> stateIndex;
		}
		search = search -> next;
	}
	return -1;
}
