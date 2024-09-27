#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../include/mergeSort.h"
#include "../include/comparator.h"
// This function merges two subarrays of base[]. The first subarray is base[0..leftLength-1] and the second subarray is base[leftLength..nitems-1].
void merge(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void *))
{
    // Initializing indices for iterating over the left and right subarrays
    size_t mid = nitems / 2;
    size_t left_size = mid, right_size = nitems - mid;

    //allocate memory for temporary subarrays 
    char *leftSub = malloc(left_size * size);
    char *rightSub = malloc(right_size * size);

    //control memory allocation
    if (!leftSub || !rightSub)
    {
        fprintf(stderr,"ERROR: Failed to allocate memory for temporary array.\n");
        exit(EXIT_FAILURE);
    }

    //copy data from original array to temporary
    // void *memcpy(void *dest, const void * src, size_t n)
    memcpy(leftSub, base, left_size * size);
    // (char *)base + mid * size, right_size * size) to calculate the offset to start at the correct position
    memcpy(rightSub, (char *)base + mid * size, right_size * size);

    // indeces to go through array: i for left, j for right, k for base.
    size_t i = 0, j = 0, k = 0;

    //merge subarrays into the original one in the right position, comparing items with the comparison function
    while (i < left_size && j < right_size)
    {
        //if element in left sub is less or equal then the element in the right sub, copy the left element in the base array at the right position
        if (compar((char *)leftSub + i * size, (char *)rightSub + j * size) <= 0) {
            memcpy((char *)base + k * size, (char *)leftSub + i * size, size);
            i++;
        } else {
        // copy the element from the right sub into the base array at the riht position
        memcpy  ((char *)base + k * size, (char *)rightSub + j * size, size);
        j++; 
        }
        k++;
    }
    //if one of the two array is smaller copy the remainig elements
    while (i < left_size) {
        memcpy((char *)base + k * size, (char *)leftSub + i * size, size);
        i++;
        k++;
    }

    while(j < right_size) {
        memcpy  ((char *)base + k * size, (char *)rightSub + j * size, size);
        j++;
        k++; 
    }

    //free the allocated memory for both sub arrays
    free(leftSub);
    free(rightSub);
}

void merge_sort(void *base, size_t nitems, size_t size, int(*compar)(const void *, const void *)){
    // Base case of recursion: if the array has 0 or 1 element, it is already sorted
    if (nitems > 1) {
        // Calculate the midpoint of the array to divide it into two halves
        size_t mid = nitems / 2;

        // Recursively sort the first half of the array
        merge_sort(base, mid, size, compar);

        // Recursively sort the second half of the array
        // The starting point of the second half is calculated by adding 'mid * size' bytes to the base pointer
        merge_sort((char *)base + mid * size, nitems - mid, size, compar);

        // Merge the two sorted halves back together
        merge(base, nitems, size, compar);
    }
 
}