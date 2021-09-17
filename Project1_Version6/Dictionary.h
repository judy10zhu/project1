#include "IntSetTransition.h"

typedef struct Dictionary* Dictionary;

extern Dictionary new_dictionary(IntSet is, IntSetTransition ist);
extern Dictionary add_dictionary(Dictionary d, Dictionary added);
//add the Dictionary added to d

extern Dictionary Dictionary_get_next(Dictionary d);
extern IntSet Dictionary_get_currentState(Dictionary d);
extern IntSetTransition Dictionary_get_ist(Dictionary d);

extern void print_dictionary(Dictionary d);
