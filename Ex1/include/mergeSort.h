//header merge sort
#ifndef MERGESORT_H
#define MERGESORT_H

#include <stddef.h>

/**
 * merge_sort - a function to perform merge sort on an array.
 * @base: pointer to the first element of the array to be sorted.
 * @nitems: number of elements in the array to be sorted.
 * @size: size in bytes of each element in the array.
 * @compar: pointer to a function that compares two elements.
 *
 * This function sorts an array in ascending order using the merge sort algorithm.
 */

void merge_sort(void *base, size_t nitems, size_t size, int (*compar)(const void*, const void*));


#endif 