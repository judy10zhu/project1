#include <stdbool.h>
#include "Node.h"
#include "IntSet.h"

typedef struct State* State;

//State: a linkedlist of Nodes
//State's variables
//bool accept; indicating whether this is the accepting state.
//int stateNum; the index of this State, NOT the total number of the states.
//State nextState; pointer to the State of the next Index. If the State's stateNum is 0, this nextState will point to the State whose stateNum is 1
//Node first; the first Node of this State
//Node last; the last Node of this State. haven't been used yet.
extern State new_state(int stateNum);
//stateNum is the index of this state, not the total number of the states.
//a stateNum should start from 0

extern State set_accept(State s, bool b);//set true if this is the accepting state
extern State set_nextState(State s, State next);

extern bool is_accept(State s);//return true if this is the accepting state
extern int get_stateNum(State s);//return the index of this State (start from 0)
extern State get_nextState(State s);
extern Node get_first(State s);

extern State add_transition(State s, char c, int i);//create a new Transition using c as the input and i as the resultState
//then use this Transition to create a Node and add the Node to this State
extern State remove_transition(State s, char c);//remove the char c from s's Transitions
extern int search_char(State s, char c);//search if the State contains a Node whose Transition's input is c
//return -1 if not find the char c
extern IntSet NFA_search_char(State s, char c);//search char function for NFA
//return NULL if not find the char c , else return an IntSet of result States

extern void free_state(State s);
extern void print_state(State s);//print each node



