#include <stdio.h>
#include <stdlib.h>
#include "IntSet.h"
#include "IntSetTransition.h"

typedef struct IntSetTransition* IntSetTransition;

struct IntSetTransition {
	char c;
	IntSet dst;
};

char IntSetTransition_get_c(IntSetTransition ist){
	return ist -> c;
}

IntSet IntSetTransition_get_dst(IntSetTransition ist){
	return ist -> dst;
}

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
