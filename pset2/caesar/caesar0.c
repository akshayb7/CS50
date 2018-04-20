#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void upper(char c, int key);
void lower(char c, int key);

int main(int argc, string argv[])
{
    if(argc != 2)
    {
        printf("Error! Please pass a correct key\n");
        return 1;
    }
    int k = atoi(argv[1]);
    k = k%26;
    printf("plaintext:");
    string plaintext = get_string();
    printf("ciphertext:");
    for(int i=0, n=strlen(plaintext); i<n;i++)
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
    if((c+key)>'Z')
    {
        key = key - 'Z' -1;
        printf("%c", 'A'+key);
    }
    else
    {
        printf("%c", c+key);
    }
}
void lower(char c, int key)
{
    if((c+key)>'z')
    {
        key = key - 'z' -1;
        printf("%c", 'a'+key);
    }
    else
    {
        printf("%c", c+key);
    }
}