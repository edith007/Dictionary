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

    node *tmp = table[h];                                    

    while(tmp != NULL)                                       
    {
         int words = strcmp(word, tmp->word);            
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

int number_of_nodes = 0;                                

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    for(int i=0; i<N; i++)                              
    {
        table[i] = NULL;                                
    }

    FILE *file = fopen(dictionary, "r");                

    if(file == NULL)
    {
        unload();
        return false;
    }

    char word[LENGTH + 1];

    while (fscanf(file, "%s", word) != EOF)             
    {

    node *n = malloc(sizeof(node));                    
        if (n == NULL)
        {
            unload();
            return false;
        }

    strcpy(n -> word, word);                            

    int h = hash(word);                                 

    for (int i=0; i<N; i++)
        {
            if (i == h)
            {
                n->next = table[i];                     
                table[i] = n;                           
            }
        }
    }

    fclose(file);                                       

    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    int total = 0;

    for(int i=0; i<N; i++)
    {
        node *tmp = table[i];                           

        while(tmp != NULL)                              
        {
            total++;                                    
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
        node *tmp = table[i];                           

         while (tmp != NULL)                            
        {
            node *temp = tmp;                           
            tmp = tmp->next;                            
            free(temp);                                 
        }

        free(tmp);                                      
    }

    return true;
}


