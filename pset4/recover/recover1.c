#include <stdio.h>
#include <stdlib.h>

#include "dat.h"
//constant to define the size of a buffer character array for temporary storage
#define BUFFERSIZE 512

int main(int argc, char *argv[])
{
    //Checking for number of command-line arguments
    if(argc!=2)
    {
        fprintf(stderr, "Usage: ./recover filename\n");
        return 1;
    }
    
    char* inputfile = argv[1];
    //Open input file
    FILE* inptr = fopen(inputfile, "r");
    //Checking if able to open the input file
    if(inptr==NULL)
    {
        fprintf(stderr, "Unable to open/find the input file\n");
        return 2;
    }
    