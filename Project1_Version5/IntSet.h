#include <stdbool.h>
typedef struct IntSet* IntSet;

extern IntSet new_intSet(int data);//a node whose data type is int

extern IntSet IntSet_set_data(IntSet is, int data);
extern IntSet IntSet_set_next(IntSet is, IntSet next);
extern IntSet IntSet_get_next(IntSet is);
extern int IntSet_get_data(IntSet is);

extern bool IntSet_if_contains(IntSet is, IntSet added);
//return true if is contains an int that is equal to i
extern IntSet IntSet_sorted_add(IntSet is, IntSet next);
//could only add next to is, if next has IntSet next, next.next will not be added
//if is does not contain the next
//add next to is in sorted order, data sorted from small to large
//must assign the return variable to the original variable
//e.g.adding is1 to is: is = IntSet_sorted_add(is, is1);
extern IntSet IntSet_sorted_addAll(IntSet is, IntSet added);
//add all the IntSets in added to is
//added.next will be added, and all of the added.next.next...will be added

extern bool isSame_intSet(IntSet is1, IntSet is2);
//return true if is1 and is2 have the same int set
//maybe this function has never been used, will check it out later

extern void free_intSet(IntSet is);
extern void print_intSet(IntSet is);
