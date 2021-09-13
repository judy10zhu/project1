#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Node.h"
#include "State.h"
#include "IntSet.h"

typedef struct State* State;

struct State{
	bool accept;
	int stateNum;
	State nextState;
	Node first;
	Node last;
};

State new_state(int stateNum){
	State s = (State)malloc(sizeof(struct State));
	s -> accept = false;
	s -> nextState = NULL;
	s -> first = NULL;
	s -> last = NULL;
	s -> stateNum = stateNum;
	return s;
}

State set_accept(State s, bool b){
	s -> accept = b;
	return s;
}

State set_nextState(State s, State next){
	s -> nextState = next;
	return s;
}

bool is_accept(State s){
	return s -> accept;
}

int get_stateNum(State s){
	return s -> stateNum;
}

State get_nextState(State s){
	return s -> nextState;
}

Node get_first(State s){
	return s -> first;
}

State add_transition(State s, char c, int i){
	Node n = new_node(new_transition(c, i));
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
	Node n;
	while(search != NULL){
		n = get_next(search);
		if (get_data(search) == c){
			return get_result(search);
		}
		search = n;
	}
	return -1;
}

IntSet NFA_search_char(State s, char c){
	IntSet is = NULL;
	IntSet current = NULL;
	Node search = s -> first;
	Node n;

	while(search != NULL){
		n = get_next(search);
		if (get_data(search) == c){
			if (is == NULL){
				is = new_intSet(get_result(search));
				current = is;
			}else{
				IntSet next = new_intSet(get_result(search));
				IntSet_set_next(current, next);
				current = next;
			}
		}
		search = n;
	}
	return is;

}

void print_state(State s){
	printf("State: %d; accepting? %d\n", s -> stateNum, s -> accept);
	Node n = s -> first;
	while (n != NULL){
		print_node(n);
		n = get_next(n);
	}
}

void free_state(State s){
	Node n = s -> first;
	while (n != NULL) {
		Node next = get_next(n);
		free_node(n);
		n = next;
	}
	free(s);
}
