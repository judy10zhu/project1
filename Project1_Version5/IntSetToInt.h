#include "IntSet.h"

typedef struct IntSetToInt* IntSetToInt;

extern IntSetToInt new_intSetToInt(IntSet is, int i);

extern IntSetToInt set_nextIntSetToInt(IntSetToInt this, IntSetToInt added);
extern IntSet get_stateIntSet(IntSetToInt isti);
extern int get_stateIndex(IntSetToInt isti);

extern int search_stateIndex(IntSetToInt isti, IntSet is);
extern void print_intSetToInt(IntSetToInt isti);
