#include <stdbool.h>
#include "Transition.h"
typedef struct Node* Node;


Node new_node(Transition data);
Node set_data(Node n, Transition data);
Node set_next(Node n, Node next);
Node set_prev(Node n, Node prev);
//Node set_accept(Node n, bool b);
Node get_next(Node n);
char get_data(Node n);
int get_resultState(Node n);
void free_node(Node n);
void print_node(Node n);

