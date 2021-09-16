#include "IntSetTransition.h"

typedef struct Dictionary* Dictionary;

extern Dictionary new_dictionary(IntSet is, IntSetTransition ist);
extern Dictionary add_dictionary(Dictionary d, Dictionary added);
//add the Dictionary added to d

extern void print_dictionary(Dictionary d);
