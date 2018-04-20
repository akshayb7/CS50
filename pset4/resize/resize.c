#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    //ensure proper command-line arguments
    if(argc!=4)
    {
        fprintf(stderr, "Usage ./resize n infile outfile\n");
        return 1;
    }
    
    int n = atoi(argv[1]);
    
    //checking if the value of n is a positive integer less than or equal to 100
    if((n<0)||(n>100))
    {
        fprintf(stderr, "The value of n should be a positive integer less than or equal to 100\n");
        return 1;
    }
    
    //remember file names
    char* infile = argv[2];
    char* outfile = argv[3];
    
    //open input file
    FILE *inptr = fopen(infile, "r");
    if(inptr == NULL)
    {
        fprintf(stderr,"Could not open %s. \n", infile);
        return 1;
    }
    
    //open output file
    FILE *outptr = fopen(outfile, "w");
    if(outptr == NULL)
    {
        fprintf(stderr,"Could not create %s. \n", outfile);
        return 1;
    }
    
    //read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);
    
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);
    
    // determine padding for scanlines in infile
    int padding_infile = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    //changing the BITMAPFILEHEADER and BITMAPINFOHEADER values as per the resize factor
    int in_biWidth = abs(bi.biWidth);
    bi.biWidth = bi.biWidth * n;
    int in_biHeight = abs(bi.biHeight);
    bi.biHeight = bi.biHeight * n;
    
    // determine padding for scanlines in outfile
    int padding_outfile = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    //output Imagesize calculation
    bi.biSizeImage = abs(bi.biHeight)*((bi.biWidth*(sizeof(RGBTRIPLE)))+padding_outfile);
    
    //output FileSize calculation
    bf.bfSize = bi.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
    
    //write output file's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);
    
    //write output file's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);
    
    //assigning memory on heap to store each row 
    RGBTRIPLE *row = malloc(sizeof(RGBTRIPLE)*(bi.biWidth));
    
    //iterate over infile's scanline
    for(int i=0; i< in_biHeight; i++)
    {
        int pointer = 0;
        //iterate over each pixel in the scanline
        for(int j=0; j< in_biWidth; j++)
        {
            //temporary variable to store the current pixel
            RGBTRIPLE triple;
                
            //read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
            
            //writing each pixel n times to the row memory
            for(int k=0; k<n; k++)
            {
                //write RGB triple to row
                *(row+pointer) = triple;
                pointer++;
            }
        }
        
        //skip over padding if present in infile
        fseek(inptr, padding_infile, SEEK_CUR);
        
        //writing each row to the outfile n times
        for(int l=0; l<n; l++)
        {
            //writing each row to the outfile
            fwrite(row, (sizeof(RGBTRIPLE)*bi.biWidth), 1, outptr);
            //adding padding to each row in the outfile
            for(int m=0; m<padding_outfile; m++)
            {
                fputc(0x00, outptr);
            }
        }
    }
    
    //free memory on heap
    free(row);
    
    //close infile
    fclose(inptr);
    
    //close outfile
    fclose(outptr);
    
    return 0;
}