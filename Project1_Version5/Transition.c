#include <stdio.h>
#include <stdlib.h>
#include "Transition.h"

typedef struct Transition* Transition;

struct Transition{
    char input;
    int resultState;
};

Transition new_transition(char input, int resultState){
    Transition t = (Transition)malloc(sizeof(struct Transition));
    t -> input = input;
    t -> resultState = resultState;
    return t;
}

int get_resultState(Transition t){
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
