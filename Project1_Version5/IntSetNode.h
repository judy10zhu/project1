#include <stdbool.h>
#include "IntSet.h"

typedef struct IntSetNode* IntSetNode;

extern IntSetNode new_intSetNode(IntSet data);

extern IntSet IntSetNode_get_data(IntSetNode isn);
extern IntSetNode IntSetNode_get_next(IntSetNode isn);

extern int IntSetNode_count(IntSetNode isn);
extern IntSetNode add_intSetNode(IntSetNode isn, IntSetNode added);
extern bool if_contains(IntSetNode isn, IntSet is);
//return true if isn contains a IntSet that has the same ints with is

extern void print_intSetNode(IntSetNode isn);
