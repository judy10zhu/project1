typedef struct Transition* Transition;

extern Transition new_transition(char input, int resultState);//Transition contains a char and an int
//resultState is the index of the result state of this input
extern char get_input(Transition t);//return the input
extern int get_resultState(Transition t);//return the numState

extern void free_transition(Transition t);
extern void print_transition(Transition t);
