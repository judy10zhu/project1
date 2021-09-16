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

IntSet IntSet_sorted_add(IntSet is, IntSet next){
	int data = next -> data;
	if (data < is -> data){
		next -> next = is;
		return next;
	}
	IntSet search = is;
	while (search != NULL){
		if (search -> next == NULL){
					search -> next = next;
						return is;
				}
		if (data < search -> next -> data){
			next -> next = search -> next;
			search -> next = next;
			return is;
		}
		search = search -> next;
	}
	return NULL;
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

void print_intSet(IntSet is){
    while (is != NULL){
    	printf("<%d>", is -> data);
    	is = is -> next;
    }
}
