#include <cs50.h>
#include <stdio.h>

void spaces(int n);
void hashes(int n);

int main(void)
{
    int n;
    do
    {
        printf("Height: ");
        n = get_int();
    }
    while((n<0)||(n>23));
    int j=2;
    for(int i=n-1; i>=0; i--)
    {
        spaces(i);
        hashes(j);
        j++;
        printf("\n");
    }
}

void spaces(int n)
{
    for(int i=0;i<n;i++)
    {
        printf(" ");
    }
}

void hashes(int n)
{
    for(int i=0;i<n;i++)
    {
        printf("#");
    }
}