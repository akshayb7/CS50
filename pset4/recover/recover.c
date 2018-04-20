#include <stdio.h>
#include <stdlib.h>

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

    //Open input file
    FILE* inptr = fopen(argv[1], "r");
    //Checking if able to open the input file
    if(inptr==NULL)
    {
        fprintf(stderr, "Unable to open/find the input file\n");
        return 2;
    }
    
    //defining a char pointer to heap for temporary storage
    unsigned char *buffer = malloc(BUFFERSIZE);
    
    //counting the number of files recovered
    int count = 0;
    
    //variable to keep track of new file start
    int track = 0;
    
    //declaring a pointer for output file so that it is usable inside the scope of the loop as follows
    FILE* outptr = NULL;
    
    //Loop to quit if End of File is reached
    while(fread(buffer, BUFFERSIZE, 1, inptr) != 0)
    {
        if((buffer[0] == 0xff)&&(buffer[1] == 0xd8)&&(buffer[2] == 0xff)&&((buffer[3] & 0xf0) == 0xe0))
        {
            //close the current file if new start of file detected
            if(track == 1)
            {
                fclose(outptr);
            }
            else
            {
                track = 1;
            }
            //naming of file stored via the sprintf function
            char str[8]; //To store the three digits, .jpg characters and /0 character denoting the end of the string name
            sprintf(str, "%03i.jpg", count);
            //open a new file for the start of new recovery image
            outptr = fopen(str, "a");
            count++; //so that the name of next file is the next integer
        }
        if(track == 1)
        {
            fwrite(buffer, BUFFERSIZE, 1, outptr);
        }
    }
    //freeing up dynamically allocated memory
    free(buffer);
    
    //closing the open files
    fclose(inptr);
    fclose(outptr);
    
    return 0;
}