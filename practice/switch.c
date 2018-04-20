#include <cs50.h>
#include <stdio.h>

int main(void)
{
    printf("Enter a character\n");
    char c = get_char();
    switch(c)
    {
        case 'y':
        case 'Y':
            printf("Yes\n");
            break;
        case 'n':
        case 'N':
            printf("No\n");
            break;
        default:
            printf("Error\n");
    }
}