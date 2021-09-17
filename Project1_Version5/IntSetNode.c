#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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

IntSet IntSetNode_get_data(IntSetNode isn){
	return isn -> data;
}

IntSetNode IntSetNode_get_next(IntSetNode isn){
	return isn -> next;
}

void print_intSetNode(IntSetNode isn){
	while(isn != NULL){
		print_intSet(isn -> data);
		printf("\n");
		isn = isn -> next;
	}
}

IntSetNode add_intSetNode(IntSetNode isn, IntSetNode added){
	IntSetNode search = isn;
	while(search -> next != NULL){
		search = search -> next;
	}
	search -> next = added;
	return isn;
}

bool if_contains(IntSetNode isn, IntSet is){
	while(isn != NULL){
		if (isSame_intSet(isn -> data, is)){
			return true;
		}
		isn = isn -> next;
	}
	return false;
}

int IntSetNode_count(IntSetNode isn){
	IntSetNode search = isn;
	int count = 0;
	while(search != NULL){
		count += 1;
		search = search -> next;
	}
	return count;
}

