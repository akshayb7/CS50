#include <cs50.h>
#include <stdio.h>

int main(void)
{
    printf("Enter a number\n");
    int n = get_int();
    if(n>0)
    {
        printf("Positive\n");
    }
    else if(n<0)
    {
        printf("Negative\n");
    }
    else
    {
        printf("Zero\n");
    }
}