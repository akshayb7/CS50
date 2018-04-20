#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float n;
    printf("O hai! ");
    do
    {
        printf("How much change is owed?\n");
        n = get_float();
    }
    while(n<0);
    n=n*100;
    int cents=(int)roundf(n);
    int coins=0;
    while(cents>=25)
    {
        cents-=25;
        coins++;
    }
    while(cents>=10)
    {
        cents-=10;
        coins++;
    }
    while(cents>=5)
    {
        cents-=5;
        coins++;
    }
    coins = coins + cents;
    printf("%i\n", coins);
}