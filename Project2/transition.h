typedef struct Transition* Transition;


Transition new_transition(char input, int numState);
int get_state(Transition t);
int get_input(Transition t);
void free_transition(Transition t);
void print_transition(Transition t);

