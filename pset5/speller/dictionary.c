/**
 * Implements a dictionary's functionality using the concept of trie.
 * Author: Akshay Bhardwaj
 */

#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "dictionary.h"

#define ALPHA 27

//Defining a struct to store each alphabet in a trie datastructure
typedef struct node
{
    bool is_word;
    struct node *child[ALPHA];
}
node;
//declaring the root node for the dictionary to be loaded into
node *root;

//declaring variable to count the number of words loaded into the dictionary
int wordcount = 0;

bool freenode(node *current);

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{
    //initializing a node to keep track of the current node starting initially from the root node
    node *current = root;
    
    int i = 0, index = 0;
    
    //looping through each letter in the word
    while(word[i]!= '\0')
    {
        char ch = word[i];
        
        //checking if the character is apostrophe
        if(ch == '\'')
        {
            index = ALPHA - 1;
        }
        //assigning index to be checked in trie structure for either of lower or upper cased letter from the word passed
        else
        {
            index = ((int)toupper(ch)) - 65;
        }
        
        //checking if the current character is present in the current node or not
        if(current -> child[index]!= NULL)
        {
            current = current -> child[index];
            i++;
        }
        else
        {
            return false;
        }
    }
    
     //check if the word exists in the dictionary or not
    if(current -> is_word == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary)
{
    //trying to open the dictionary passed to the load function 
    FILE *dic = fopen(dictionary, "r");
    if (dic == NULL)
    {
        printf("Could not open %s.\n", dictionary);
        return false;
    }
    
    //declaring variables to traverse through the dictionary passed and load them into the trie 
    char character;
    int index;
    
    //allocating memory to the root node
    root = (node*)malloc(sizeof(node));
    
    //assigning the pointer arrays to have null values and is_word to have false value by default
    for(int i=0; i<ALPHA; i++) 
    {
        root->child[i] = NULL;
        root->is_word =false;
    }
    
    //initializing a node to keep track of the current node
    node *current = NULL;
    
    //looping through the dictionary till the end of the file
    while ((character = fgetc(dic))!= EOF)
    {
        //setting the current node to root node initially
        current = root;
        
        //going through the character of each word and adding them to the trie 
        for(; character!='\n'; character = fgetc(dic))
        {
            //assigning the array index the character should go to 
            //first checking for the apostrophe character
            if(character == '\'')
            {
                index = ALPHA - 1;
            }
            else
            {
                index = ((int)toupper(character)) - 65;
            }
            
            //checking if the character address is present at the current trie node
            if(current -> child[index] == NULL)
            {
                //creating a new child node at the index and allocating memory for it
                current -> child[index] = (node*)malloc(sizeof(node));
                
                //updating the current node to move to it's child node
                current = current -> child[index];
                
                //assigning the pointer arrays to have null values and is_word to have false as default
                for(int i=0; i<ALPHA; i++) 
                {
                    current -> child[i] = NULL;
                    current -> is_word = false;
                }
            }
            //if the character address is present then going to it
            else
            {
                current = current -> child[index];
            }
        }
        //affirming it as a word once the '\n' character is found
        current -> is_word = true;
        
        //incrementing the number of words loaded
        wordcount++;
    }
    
    //close the dictionary file
    fclose(dic);
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return wordcount;
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
    //passing the location of root to the freenode function 
    if(freenode(root) == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//Implementing a recursive function to free the allocated memory to the dictionary
bool freenode(node *current)
{
    //going through each of the children of the current node to see if they are empty before freeing the current node
    for(int i = 0; i<ALPHA; i++)
    {
        //if the child at i'th location is not free then passing it's location in the same freenode function
        if(current -> child[i] != NULL)
        {
            freenode (current -> child[i]);
        }
    }
    free(current);
    return true;
}