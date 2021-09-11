#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "dfa.h"

#include "transition.h"
#include "dfa.h"
#include "Node.h"
#include "state.h"

void print_node(Node n);
void free_node(Node n);
int get_resultState(Node n);
char get_data(Node n);
Node get_next(Node n);
Node get_prev(Node n);
Node set_prev(Node n, Node prev);
Node set_next(Node n, Node next);
Node set_data(Node n, Transition data);
Node new_node(Transition data);

State new_state(void);
State add_transition(State s, char c, int i);
int search_char(State s, char c);
void free_state(State s);
void print_state(State s);
State set_accept(State s, bool b);
bool is_accept(State s);

int main() {
    printf("0");
    DFA d = new_DFA(9);

    printf("%d \n",DFA_get_size(d));
    DFA_set_transition(d, 0, 'c', 1);
    DFA_set_transition(d, 1, 'o', 2);
    DFA_set_transition(d, 2, 'm', 3);
    DFA_set_transition(d, 3, 'p', 4);
    DFA_set_transition(d, 4, 'u', 5);
    DFA_set_transition(d, 5, 't', 6);
    DFA_set_transition(d, 6, 'e', 7);
    DFA_set_transition(d, 7, 'r', 8);
    
    printf("done \n");

    DFA_print(d);

}
