// quick sort header file 
#ifndef QUICK_SORT_H
#define QUICK_SORT_H

// Include for size_t type used for nitems and size parameters
#include <stddef.h> 

/**
 * quick_sort - function to perform quick sort on an array.
 * @base: pointer to the first element of the array to be sorted.
 * @nitems: number of elements in the array to be sorted.
 * @size: size in bytes of each element in the array.
 * @compar: pointer to a function that compares two elements --> implemented function for comparison in comparator.c
 * This function sorts an array in ascending order using the quick sort algorithm.
*/

void quick_sort(void *base, size_t nitems, size_t size, int (*compar)(const void*, const void*));

#endif