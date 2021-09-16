typedef struct IntSet* IntSet;

extern IntSet new_intSet(int data);//a node whose data type is int

extern IntSet IntSet_set_data(IntSet is, int data);
extern IntSet IntSet_set_next(IntSet is, IntSet next);
extern IntSet IntSet_get_next(IntSet is);
extern int IntSet_get_data(IntSet is);

extern IntSet IntSet_sorted_add(IntSet is, IntSet next);
//add next to is in sorted order, data sorted from small to large

extern void free_intSet(IntSet is);
extern void print_intSet(IntSet is);
