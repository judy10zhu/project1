#include "IntSet.h"

typedef struct IntSetTransition* IntSetTransition;

extern IntSetTransition new_intSetTransition(char c, IntSet dst);
extern void print_intSetTransition(IntSetTransition ist);
