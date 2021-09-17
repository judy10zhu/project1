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

IntSet IntSet_sorted_add(IntSet is, IntSet added){
	if (is == NULL){
		return added;
	}
	if (IntSet_if_contains(is, added)){
		return is;
	}
	int data = added -> data;
	if (data < is -> data){
		added -> next = is;
		return added;
	}
	IntSet search = is;
	while (search != NULL){
		if (search -> next == NULL){
			search -> next = added;
			return is;
		}
		if (data < search -> next -> data){
			added -> next = search -> next;
			search -> next = added;
			return is;
		}
		search = search -> next;
	}
	return NULL;
}

IntSet IntSet_sorted_addAll(IntSet is, IntSet added){
	IntSet search = added;
	while (search != NULL){
		IntSet guard = search -> next;
		is = IntSet_sorted_add(is, search);
		search = guard;
	}
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

void print_intSet(IntSet is){
	while (is != NULL){
		printf("<%d>", is -> data);
		is = is -> next;
	}
}

bool isSame_intSet(IntSet is1, IntSet is2){
	while (is1 != NULL && is2 != NULL){
		if (is1 -> data != is2 -> data){
			return false;
		}
		is1 = is1 -> next;
		is2 = is2 -> next;
		if (is1 == NULL || is2 == NULL){
			if (is1 == NULL && is2 == NULL){
				return true;
			}
			return false;
		}
	}
	return false;
}

bool IntSet_if_contains(IntSet is, IntSet added){
	IntSet search = is;
	while(search != NULL){
		if (search -> data == added -> data){
			return true;
		}
		search = search -> next;
	}
	return false;
}

