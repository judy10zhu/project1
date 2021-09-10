typedef struct Table* Table;
struct Table{
	bool accept;
	int numOfTransitions;
	Transition transitionTable[];
};

Table new_table(int numOfTransitions);
Table add_transition(Table t, Transition trans);
int search_char(Table t, char c);
void free_table(Table t);
bool is_accept(Table t);
void print_table(Table t);
Table set_accept(Table t, bool b);
