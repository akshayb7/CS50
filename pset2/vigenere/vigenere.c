#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void upper(char c, int k);
void lower(char c, int k);
int shift(char c);

int main(int argc, string argv[])
{
    //checking if correct number of command line arguments are entered
    if(argc!=2)
    {
        printf("Usage: ./vigenere k\n");
        return 1;
    }
    string key = argv[1];
    int keylength = strlen(key);
    //checking if the key entered is containing any characters other than alphabets
    for(int i=0; i<keylength; i++)
    {
        if(!(isalpha(key[i])))
        {
            printf("Key can only contain alphabets\n");
            return 1;
        }
    }
    printf("plaintext:");
    string plaintext = get_string();
    printf("ciphertext:");
    int num = 0;
    int current_key;
    //iterating through the characters of the string
    for(int i=0, n=strlen(plaintext); i<n; i++)
    {
        //printing directly if the current character is not an alphabet
        if(!isalpha(plaintext[i]))
        {
            printf("%c", plaintext[i]);
        }
        //checking for uppercase letters
        else if(isupper(plaintext[i]))
        {
            //getting the key value by which to shift the current character of the input
            if(num<keylength)
            {
                current_key = shift(key[num]);
                num++;
            }
            //if all the letters of the key is used up, starting from the beginning
            else
            {
                num = 0;
                current_key = shift(key[num]);
                num++;
            }
            //calling function to shift and print the current character
            upper(plaintext[i], current_key);
        }
        else
        {
            //getting the value by which to shift the current character of the input
            if(num<keylength)
            {
                current_key = shift(key[num]);
                num++;
            }
            //if all the letters of the key is used up, starting from the beginning
            else
            {
                num = 0;
                current_key = shift(key[num]);
                num++;
            }
            //calling function to shift and print the current character
            lower(plaintext[i], current_key);
        }
    }
    printf("\n");
    //return 0 if the program executes
    return 0;
}
//function to cipher uppercase letters
void upper(char c, int k)
{
    printf("%c", ((c + k - 65) % 26) + 65);
}
//function to cipher lowercase letters
void lower(char c, int k)
{
        printf("%c", ((c + k - 97) % 26) + 97);
}
//function to get the shift value for a particular key character
int shift(char c)
{
    return (tolower(c)-'a');
}