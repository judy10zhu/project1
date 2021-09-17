#include "IntSet.h"

typedef struct IntSetTransition* IntSetTransition;

extern char IntSetTransition_get_c(IntSetTransition ist);
extern IntSet IntSetTransition_get_dst(IntSetTransition ist);

extern IntSetTransition new_intSetTransition(char c, IntSet dst);
extern void print_intSetTransition(IntSetTransition ist);
