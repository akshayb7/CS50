#include <cs50.h>
#include <stdio.h>

int main(void)
{
    printf("bool is %lu\n", sizeof(bool));
    printf("char is %lu\n", sizeof(char));
    printf("int is %lu\n", sizeof(int));
    printf("double is %lu\n", sizeof(double));
    printf("float is %lu\n", sizeof(float));
    printf("long long is %lu\n", sizeof(long long));
    printf("string is %lu\n", sizeof(string));
}