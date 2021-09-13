#include <stdbool.h>
#include "Node.h"
typedef struct State* State;

struct State{
	bool accept;
	Node first;
	Node last;
};

State new_state();
State add_transition(State s, char c, int i);
int search_char(State s, char c);
void print_state(State s);
State set_accept(State s, bool b);
bool is_accept(State s);
void free_state(State s);
