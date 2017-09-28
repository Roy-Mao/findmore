/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>
#include <stdio.h>
#include "helpers.h"
#include <stdlib.h>
#include <string.h>
/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    if (n <= 0)
    {
        return false;
    }
    int upper_bound_index = n -1;
    int lower_bound_index = 0;
    while (lower_bound_index <= upper_bound_index)
    {
        int mid_index = (lower_bound_index + upper_bound_index) / 2;
        int guess_value = values[mid_index];
        if (guess_value == value)
        {
            return true;
        }
        if (guess_value > value)
        {
            upper_bound_index = mid_index - 1;
        }
        if (guess_value < value)
        {
            lower_bound_index = mid_index + 1;
        }
    }
    return false;
}


int max_array(int a[], int num_elements)
{
   int i, max=-32000;
   for (i=0; i<num_elements; i++)
   {
	 if (a[i]>max)
	 {
	    max=a[i];
	 }
   }
   return(max);
}



/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an sorting algorithm
    int max_val = max_array(values, n);
    int ind_array_length = max_val + 1;
    int ind_array[ind_array_length];
    int inc_array[ind_array_length];
    int f_array[n];
    memset(ind_array, 0, sizeof ind_array);
    memset(inc_array, 0, sizeof inc_array);
    memset(f_array, 0, sizeof f_array);
    for (int i = 0; i < n; i++ )
    {
        int go_index = values[i];
        ind_array[go_index] += 1;
    }
    for (int i = 0; i < ind_array_length; i++)
    {
        if (i == 0)
        {
            inc_array[0] = ind_array[0];
        }
        else
        {
            inc_array[i] = inc_array[i - 1] + ind_array[i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        int ori_value = values[i];
        inc_array[ori_value] -= 1;
        f_array[inc_array[ori_value]] = ori_value;
    }
    for (int i = 0; i < n; i++)
    {
        values[i] = f_array[i];
    }
    return;
}