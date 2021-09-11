#include <stdbool.h>
#include "transition.h"
typedef struct Node* Node;

//void print_node(Node n);
Node new_node(Transition data);
Node set_data(Node n, Transition data);
Node set_next(Node n, Node next);
Node set_prev(Node n, Node prev);
//Node set_accept(Node n, bool b);
Node get_prev(Node n);
Node get_next(Node n);
char get_data(Node n);
int get_resultState(Node n);
void free_node(Node n);
void print_node(Node n);
