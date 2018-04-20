#include <cs50.h>
#include <stdio.h>

int main(void)
{
    printf("Enter a character\n");
    char c = get_char();
    if(c == 'y' || c == 'Y')
    {
        printf("Yes\n");
    }
    else if (c == 'n'|| c == 'N')
    {
        printf("No\n");
    }
    else
    {
        printf("Error\n");
    }
}