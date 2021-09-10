#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "transition.h"

typedef struct Table *Table;

//this is an array of transition, the total number of transition is required in building a new table.
struct Table{
	bool accept;
	int numOfTransitions;
	Transition transitionTable[];
};

Table new_table(int numOfTransitions){
	Table this = (Table)malloc(sizeof(struct Table));
	this -> accept = false;
	this -> numOfTransitions = numOfTransitions;
	Transition transition = (Transition)malloc(sizeof(struct Transition)*numOfTransitions + 1);
	memcpy(this -> transitionTable, transition, sizeof(struct Transition)*numOfTransitions + 1);

	for (int i = 0; i < numOfTransitions; i ++){
		this -> transitionTable[i] = NULL;
	}
	return this;
}

Table set_accept(Table t, bool b){
	t -> accept = b;
	return t;
}

Table add_transition(Table t, Transition trans){
	int test = t -> numOfTransitions;
	printf("%i", test);
	for (int i = 0; i < t -> numOfTransitions; i ++){
		if(t -> transitionTable[i] != NULL){
			t -> transitionTable[i] = trans;
			return t;
		}
	}
	printf("error in add_transition");
	return NULL;
}

//if found, return the state; else return -1
int search_char(Table t, char c){
	for (int i = 0; i < t -> numOfTransitions; i ++){
			if(get_input(t -> transitionTable[i]) == c){
				return get_state(t -> transitionTable[i]);
			}
	}
	return -1;
}

void free_table(Table t){
	for (int i = 0; i < t -> numOfTransitions; i ++){
		free_transition(t -> transitionTable[i]);
	}
	free(t -> transitionTable);
	free(t);
}

bool is_accept(Table t){
	if (t -> accept)
		return true;
	else
		return false;
}

void print_table(Table t){
	for (int i = 0; i < t -> numOfTransitions; i ++){
		print_transition(t -> transitionTable[i]);
		}
	printf("\n");
}
