#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "transition.h"


typedef struct Node* Node;

struct Node {
	Transition data;
	Node next;
	Node prev;
};

Node new_node(Transition data){
	Node n = (Node)malloc(sizeof(struct Node));
	n -> data = data;
	n -> next = NULL;
	n -> prev = NULL;
	return n;
}

Node set_data(Node n, Transition data){
	n -> data = data;
	return n;
}

Node set_next(Node n, Node next){
	n -> next = next;
	return n;
}

Node set_prev(Node n, Node prev){
	n -> prev = prev;
	return n;
}

Node get_prev(Node n){
	return n-> prev;
}

Node get_next(Node n){
	return n-> next;
}

char get_data(Node n){
	return get_input(n-> data);
}

int get_resultState(Node n){
	return get_state(n-> data);
}

void free_node(Node n){
	free_transition(n -> data);
	free(n);
}

void print_node(Node n){
	print_transition(n -> data);
}
