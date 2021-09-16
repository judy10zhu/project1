#include <stdbool.h>
#include "Transition.h"

typedef struct Node* Node;

extern Node new_node(Transition data);//only contains a Transition data and a Node next

extern Node set_data(Node n, Transition data);
extern Node set_next(Node n, Node next);

extern Node get_next(Node n);
extern char get_data(Node n);//return the Node's Transition's input
extern int get_result(Node n);//return the Node's Transition's resultState
//resultState is the index of the result state of this input

extern void free_node(Node n);
extern void print_node(Node n);
