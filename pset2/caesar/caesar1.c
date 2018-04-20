#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void upper(char c, int k);
void lower(char c, int k);

int main(int argc, string argv[])
{
    if(argc != 2)
    {
        printf("Error! Please pass a correct key\n");
        return 1;
    }
    int key = atoi(argv[1]);
    printf("plaintext:");
    string plaintext = get_string();
    printf("ciphertext:");
    //iterating through the characters of the string
    for(int i=0, n=strlen(plaintext); i<n; i++)
    {
        if(isalpha(plaintext[i])==false)
        {
            printf("%c", plaintext[i]);
        }
        else if(isupper(plaintext[i])==true)
        {
            upper(plaintext[i], k);
        }
        else
        {
            lower(plaintext[i], k);
        }
    }
    printf("\n");
    return 0;
}
void upper(char c, int key)
{
    printf("%c", ((c + k - 65) % 26) + 65));
}
void lower(char c, int key)
{
    printf("%c", (((c + k - 65) % 26) + 65));
}