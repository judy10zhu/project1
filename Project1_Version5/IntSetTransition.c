#include <stdio.h>
#include <stdlib.h>
#include "IntSet.h"
#include "IntSetTransition.h"

typedef struct IntSetTransition* IntSetTransition;

struct IntSetTransition {
	char c;
	IntSet dst;
};

IntSetTransition new_intSetTransition(char c, IntSet dst){
	IntSetTransition this = (IntSetTransition)malloc(sizeof(struct IntSetTransition));
	this -> c = c;
	this -> dst = dst;
	return this;
}

void print_intSetTransition(IntSetTransition ist){
	printf("(%c: ", ist -> c);
	print_intSet(ist -> dst);
	printf(")\n");
}
