typedef struct Transition* Transition;


extern Transition new_transition(char input, int numState);
extern int get_result(Transition t);
extern int get_input(Transition t);
extern void free_transition(Transition t);
extern void print_transition(Transition t);

