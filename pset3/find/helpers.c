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
    
  
    while(end>=start)
    {
        int middle=(start+end)/2;
        if(values[middle]==value)
        {
            return true; //return true if value is found
        }
        else if(values[middle]>value)
        {
            end = middle-1;
        }
        else if(values[middle]<value)
        {
            start = middle+1;
        }
        else
        {
            return false;
        }
    }
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    int temp;
    bool check = true;
    // Implementing Bubble sort technique
    while(check)
    {
        check = false;
        for (int i=0; i<n-1; i++) 
        {
            if(values[i]>values[i+1]) //checking if the next element is smaller than the current one
            {
                //exchanging the smaller element with the larger one
                temp = values[i];
                values[i] = values[i+1];
                values[i+1] = temp;
                check = true; //continue the checking as atleast one element needed to be sorted
            }
        }
    }
    return;
}
