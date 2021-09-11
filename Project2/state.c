#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "LinkedList.h"
#include "Node.h"

typedef struct State* State;

struct State{
	bool accept;
	Node first;
	Node last;
};

State new_state(){
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

