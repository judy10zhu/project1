#include <stdbool.h>
#include "Transition.h"
typedef struct Node* Node;


extern Node new_node(Transition data);
extern Node set_data(Node n, Transition data);
extern Node set_next(Node n, Node next);
extern Node set_prev(Node n, Node prev);
//Node set_accept(Node n, bool b);
extern Node get_prev(Node n);
extern Node get_next(Node n);
extern char get_data(Node n);
extern int get_resultState(Node n);
extern void free_node(Node n);
extern void print_node(Node n);

