/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    //return false if array length is negative
    if(n<0)
    {
        return false;
    }
    //implementing binary search method
    int start = 0;
    int end = n-1;
    int middle;
    
    while(start<=end) //search till the start value is less than or equal to the end value
    {
        if (n%2==0)
            {
                middle = n/2;
            }    
        else
            {
                middle = (n+1)/2;
            }
        if(values[middle]==value)
        {
            return true; //return true if value is found
        }
        else if(values[middle]>value)
        {
            end = middle-1;
        }
        else
        {
            end = middle+1;
        }
    }
    return false; //return false if value is not found after the binary search
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    int temp;
    // Implementing Bubble sort technique
    for (int i=0; i<n-1; i++)
    {
        for (int j=0; j<n-1-i; j++) //As at the i'th iteration of previous loop, i elemnts at the end would be sorted already
        {
            if(values[j]>values[j+1]) //checking if the next element is smaller than the current one
            {
                //exchanging the smaller element with the larger one
                temp = values[j];
                values[j] = values[j+1];
                values[j+1] = temp;
            }
        }
    }
    return;
}
