// Implements a dictionary's functionality

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];



// Returns true if word is in dictionary else false
bool check(const char *word)
{

    int h = hash(word);

    node *tmp = table[h];                                    // create a temperoray node to point in the right table

    while(tmp != NULL)                                       //loop to check each node in the table.
    {
         int words = strcmp(word, tmp->word);            //compare the two string and move to next node
         tmp = tmp->next;

         if(words == 0)
         {
             return false;
         }
    }

    return true;
}


// Hashes word to a number
unsigned int hash(const char *word)
{
    int letter = (word[0])-'a';
    return letter;
}

int number_of_nodes = 0;                                //counter for the amount of nodes

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    for(int i=0; i<N; i++)                                     //initialize HASH TABLE
    {
        table[i] = NULL;                                      //in case the we are out of memory.
    }

    FILE *file = fopen(dictionary, "r");                      //open the dictionary using file pointer fopen.

    if(file == NULL)
    {
        unload();
        return false;
    }

    char word[LENGTH + 1];

    while (fscanf(file, "%s", word) != EOF)                    //Fscanf keeps track of how far it's read So it will automatically go to the next line
    {

    node *n = malloc(sizeof(node));                            //new node allocates a new memory thanks to malloc
        if (n == NULL)
        {
            unload();
            return false;
        }

    strcpy(n -> word, word);                                   // copy the string into new node

    int h = hash(word);                                        //saves the array number into int(hash into an int)

    for (int i=0; i<N; i++)
        {
            if (i == h)
            {
                n->next = table[i];                                 //Point from the new node to where the table was pointing
                table[i] = n;                                   //Point the table to where the new node is
            }
        }
    }

    fclose(file);                                               //close dictionary

    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    int total = 0;

    for(int i=0; i<N; i++)
    {
        node *tmp = table[i];                              //create a temperoray node that points towards table node

        while(tmp != NULL)                                 //loop through all hashtable
        {
            total++;                                           //total++
            tmp = tmp->next;
        }
    }

    return total;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for(int i=0; i<N; i++)
    {
        node *tmp = table[i];                             //*tmp node we are freeing

         while (tmp != NULL)                              //loop through each individual node to free them
        {
            node *temp = tmp;                              // define the next node and the node you are freeing
            tmp = tmp->next;                               //point the initial node to the next node
            free(temp);                                     //freeing the first node
        }

        free(tmp);                                        //free the pointing node at
    }

    return true;
}


