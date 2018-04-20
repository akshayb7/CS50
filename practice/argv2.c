#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(int argc, string argv[])
{
    //iterate over string in argv
    for(int i = 0; i < argc; i++)
    {
        //iterate over charcters in current string
        for(int j = 0, n = strlen(argv[i]); j < n; j++)
        {
            //print the j'th character of the i'th string
            printf("%c\n", argv[i][j]);
        }
    }
}