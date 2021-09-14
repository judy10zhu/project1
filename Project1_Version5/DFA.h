#include <stdbool.h>


typedef struct DFA *DFA;

extern DFA new_dfa(int nstates);
//nstate is the total number of States

extern State DFA_find_state(DFA dfa, int src);//find the State in the DFA linkedlist that has an index of src
extern void DFA_set_transition(DFA dfa, int src, char sym, int dst);//build the Transition using sym and dst, set the Transition for State src
extern void DFA_set_transition_all(DFA dfa, int src, int dst);//build the Transitions for all the letters
extern DFA DFA_set_acceptingState(DFA dfa, int indexOfState);//set the State of index indexOfState as the accepting state

extern int DFA_get_size(DFA dfa);//return the total number of States
extern State DFA_get_initialState(DFA dfa);
extern int DFA_get_transition(DFA dfa, int src, char sym);//find the result state of this char sym, return -1 if not find
extern bool DFA_get_accepting(DFA dfa, int state);///return true if this State is the accepting state

extern bool DFA_execute(DFA dfa, char input[]);

extern void DFA_print(DFA dfa);
extern void DFA_free(DFA dfa);









