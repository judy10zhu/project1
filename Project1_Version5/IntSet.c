#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "IntSet.h"

typedef struct IntSet* IntSet;

struct IntSet {
	int data;
	IntSet next;
};


IntSet new_intSet(int data){
	IntSet is = (IntSet)malloc(sizeof(struct IntSet));
	is -> data = data;
	is -> next = NULL;

    return is;
}

IntSet IntSet_set_data(IntSet is, int data){
	is -> data = data;
    return is;
}

IntSet IntSet_set_next(IntSet is, IntSet next){
    is -> next = next;
    return is;
}

IntSet IntSet_get_next(IntSet is){
    return is-> next;
}

int IntSet_get_data(IntSet is){
    return is -> data;
}

 void free_intSet(IntSet is){
    free(is);
}

void print_IntSet(IntSet is){
    printf("<%d>", is -> data);
}
