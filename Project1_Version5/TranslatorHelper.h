typedef struct TranslatorHelper* TranslatorHelper;

extern TranslatorHelper new_translatorHelper();
//used to store two variables: IntSetNode isn and Dictionary d

extern void set_intSetNode(TranslatorHelper tsh, IntSetNode isn);
extern void set_dictionary(TranslatorHelper tsh, Dictionary d);
extern IntSetNode get_intSetNode(TranslatorHelper tsh);
extern Dictionary get_dictionary(TranslatorHelper tsh);

extern void free_translatorHelper(TranslatorHelper tsh);
extern void print_translatorHelper(TranslatorHelper tsh);
