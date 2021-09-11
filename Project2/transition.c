#include <stdio.h>
#include <stdlib.h>


typedef struct Transition* Transition;

struct Transition{
	char input;
	int resultState;
};

Transition new_transition(char input, int numState){
	Transition this = (Transition)malloc(sizeof(struct Transition));
	this -> input = input;
	this -> resultState = numState;
	return this;
}

int get_state(Transition t){
	return t -> resultState;
}

char get_input(Transition t){
	return t -> input;
}

void free_transition(Transition t){
	free(t);
}

void print_transition(Transition t){
	printf("<%c, %d>\n", t-> input, t -> resultState);
}
