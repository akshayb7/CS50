#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    //Ask for an input
    string s = get_string();
    //check if string is not null
    if(s != NULL)
    {
        //iterate through the characters of the string
        for(int i=0, n = strlen(s); i<n; i++)
        {
            //print the i'th character of the string
            printf("%c\n", s[i]);
        }
    }
}