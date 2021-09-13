typedef struct IntSet* IntSet;

extern IntSet new_intSet(int data);//a node whose data type is int

extern IntSet IntSet_set_data(IntSet is, int data);
extern IntSet IntSet_set_next(IntSet is, IntSet next);
extern IntSet IntSet_get_next(IntSet is);
extern int IntSet_get_data(IntSet is);

extern void free_intSet(IntSet is);
extern void print_IntSet(IntSet is);
