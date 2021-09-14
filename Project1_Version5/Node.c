#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Transition.h"
#include "Node.h"

typedef struct Node* Node;

struct Node {
    Transition data;
    Node next;
};


Node new_node(Transition data){
    Node n = (Node)malloc(sizeof(struct Node));
    n -> data = data;
    n -> next = NULL;

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

Node get_next(Node n){
    return n-> next;
}

char get_data(Node n){
    return get_input(n-> data);
}

 int get_result(Node n){
    return get_resultState(n-> data);
}

 void free_node(Node n){
    free_transition(n -> data);
    free(n);
}

void print_node(Node n){
    print_transition(n -> data);
}
