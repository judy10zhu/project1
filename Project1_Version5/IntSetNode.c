#include <stdio.h>
#include <stdlib.h>
#include "IntSet.h"
#include "IntSetNode.h"

typedef struct IntSetNode* IntSetNode;

struct IntSetNode {
	IntSet data;
	IntSetNode next;
};

IntSetNode new_intSetNode(IntSet data){
	IntSetNode this = (IntSetNode)malloc(sizeof(struct IntSetNode));
	this -> data = data;
	this -> next = NULL;
	return this;
}

void print_intSetNode(IntSetNode isn){
	while(isn != NULL){
		print_intSet(isn -> data);
		printf("\n");
		isn = isn -> next;
	}
}
