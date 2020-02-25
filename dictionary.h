// Declares a dictionary's functionality                                           //cd is current directory.

#ifndef DICTIONARY_H
#define DICTIONARY_H                             //#include this file, clang will only compile speller.c and dictionary.c

#include <stdbool.h>                             //file in which bool itself is defined.

// Maximum length for a word
// (e.g., pneumonoultramicroscopicsilicovolcanoconiosis)
#define LENGTH 45                                //#define is a preprocessor directive which define a constant called LENGTH that has value 45. (it is not a variable just a find and replace trick).

// Prototypes
bool check(const char *word);                    //Returns true if word is in dictionary else false      //const means the value cannot be changed.
unsigned int hash(const char *word);             // const is one of those strings, when passed in as arguments, must remain constant; you won’t be able to change them, accidentally or otherwise!
bool load(const char *dictionary);              //Loads dictionary into memory.
unsigned int size(void);                        //Returns number of words in dictionary if loaded else 0 if not yet loaded
bool unload(void);                              //Unloads dictionary from memory.  Returns true if successful else false

#endif // DICTIONARY_H
