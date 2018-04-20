#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void upper(char c, int k);
void lower(char c, int k);

int main(int argc, string argv[])
{
    //checking if a key is provided correctly or not
    if(argc != 2)
    {
        printf("Error! Please pass a correct key\n");
        return 1;
    }
    //Converting string to int type
    int key = atoi(argv[1]);
    printf("plaintext:");
    string plaintext = get_string();
    printf("ciphertext:");
    //iterating through the characters of the string
    for(int i=0, n=strlen(plaintext); i<n; i++)
    {
        //checking if the character is in upper case
        if(isupper(plaintext[i]))
        {
            upper(plaintext[i], key);
        }
        //checking if the character is in lowe case
        else if(islower(plaintext[i]))
        {
            lower(plaintext[i], key);
        }
        //if the character is not an alphabet, printing it as it is
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
    //return 0 if the program executes
    return 0;
}
void upper(char c, int k)
{
    printf("%c", ((c + k - 65) % 26) + 65);
}
void lower(char c, int k)
{
    printf("%c", ((c + k - 97) % 26) + 97);
}