//
//  dfa.c
//  Project1
//
//  Created by Judy on 9/11/21.
//

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dfa.h"
//#include "LinkedList.h"
//#include "state.h"
#include "Node.h"
#include "transition.h"
//#include "table.h"


typedef struct DFA *DFA;
typedef struct State* State;
State new_state(void);
State add_transition(State s, char c, int i);
int search_char(State s, char c);
void free_state(State s);
void print_state(State s);
State set_accept(State s, bool b);
bool is_accept(State s);

struct State{
bool accept;
Node first;
Node last;
};

State new_state(void){
State s = (State)malloc(sizeof(struct State));
s -> accept = false;
s -> first = NULL;
s -> last = NULL;
return s;
}

State add_transition(State s, char c, int i){
Node n = new_node(new_transition(c, i));
set_prev(n,s -> last);
if (s->last != NULL) {
    set_next(s->last, n);
}
s->last = n;
if (s->first == NULL) {
    s->first = n;
}
return s;
}

int search_char(State s, char c){
Node search = s -> first;
while(search != NULL){
    Node n = get_next(search);
    if (get_data(search) == c){
        return get_resultState(search);
    }
    search = n;
    free_node(n);
}
return -1;
}

void print_state(State s){
Node n = s -> first;
while (n != NULL){
    print_node(n);
    n = get_next(n);
}
}

State set_accept(State s, bool b){
s -> accept = b;
return s;
}

bool is_accept(State s){
return s -> accept;
}

void free_state(State s){
Node n = s -> first;
while (n != NULL) {
    Node next = get_next(n);
    //Node next = node -> next;
    free_node(n);
    n = next;
}
free(s);
}

struct DFA{
    int numberOfStates;
    State states[];
};

DFA new_DFA(int nstates){
    DFA dfa = (DFA)malloc(sizeof(struct DFA));
    dfa -> numberOfStates = nstates;
    State s = (State)malloc(sizeof(struct State)*(unsigned long)nstates + 1);
    memcpy(dfa -> states, s, sizeof(struct State)*(unsigned long)nstates + 1);

    for (int i = 0; i < nstates; i ++){
        dfa -> states[i] = new_state();
    }
    return dfa;
}

void DFA_free(DFA dfa){
    for (int i = 0; i < dfa -> numberOfStates; i ++){
        free_state(dfa -> states[i]);
    }
    free(dfa -> states);
    free(dfa);
}

int DFA_get_size(DFA dfa){
    return dfa -> numberOfStates;
}

int DFA_get_transition(DFA dfa, int src, char sym){
    return search_char(dfa ->states[src], sym);
}

void DFA_set_transition(DFA dfa, int src, char sym, int dst){
    add_transition(dfa -> states[src], sym, dst);
}

void DFA_set_transition_all(DFA dfa, int src, int dst){
    char c;
    for (c = 'a'; c <= 'z'; c++){
        DFA_set_transition(dfa, src, c, dst);
    }
    for (c = 'A'; c <= 'Z'; c++){
        DFA_set_transition(dfa, src, c, dst);
    }
}

bool DFA_get_accepting(DFA dfa, int state){
    return is_accept(dfa -> states[state]);
}

//bool DFA_execute(DFA dfa, char *input){
//
//}

void DFA_print(DFA dfa){
    for (int i = 0; i < dfa -> numberOfStates; i ++){
        print_state(dfa -> states[i]);
    }
}
