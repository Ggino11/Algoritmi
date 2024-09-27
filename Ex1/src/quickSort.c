#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../include/quickSort.h"
#include "../include/comparator.h"

//implementation for quickSort
/**
 * Swaps two elements in an array.
 *
 * @param a Pointer to the first element.
 * @param b Pointer to the second element.
 * @param size Size of each element in bytes.
 */
void swap(void *a, void *b, size_t size){
    
    // allocate memory for temporary buffer to hold contents of the first element
    char *temp = malloc(size);

    if (temp == NULL)
    {
        fprintf(stderr, "ERROR: Failed to allocate memory.\n");
        exit(EXIT_FAILURE);
    }
    
    // copy content of the first element into temp
    memcpy(temp, a, size);
    // copy content of the second element into a (first element)
    memcpy(a, b, size);
    // copy content of temp into b (second element)
    memcpy(b, temp, size);
    
    // free memory allocated for temp 
    free(temp);
}

/**
 * Partitions the array segment around a pivot such that all elements on the left
 * are less than or equal to the pivot, and all elements on the right are greater.
 *
 * @param base Pointer to the start of the array.
 * @param size Size of each element in bytes.
 * @param compar Comparison function that determines the order of elements.
 * @param nitems Number of elements in the array to be sorted
 * @return The index where the pivot element finally resides.
 */
size_t partition(void *base, size_t nitems, size_t size, int (*compar)(const void*, const void*)) {
    char *pivot = (char *)base + (nitems - 1) * size; // Choose the last element of the array
     // Initializing index of the smaller element to the element before the array. Initialized to -1, it ensures thar if the first element in position 0 needs to be swapped, it swaps correctly because we swap the element at index + 1
    size_t index = - 1;

    // Look through all elements, compare each with the pivot, and swap as needed.
    for (size_t j = 0; j < nitems - 1; j++) {
        // If the current element is less than or equal to pivot, swap it with the element at index.
        // *size to ensure that we reach the j-th element correctly
        if (compar((char *)base + j * size, pivot) <= 0) {
            index++; // Increment the index of the smaller element.
            swap((char *)base + index * size, (char *)base + j * size, size);
        }
    }  

    // Swap the pivot with the element at index +1, so it is now in the correct position.
    swap((char *)base + (index + 1) * size, pivot, size);
    return (index + 1); // Return the index of the pivot.
}

// recursive implementation of Quick Sort that uses the rightmost(last) element as the pivot.

void quick_sort(void *base, size_t nitems, size_t size, int (*compar)(const void*, const void*)){
 if (nitems > 1) {
    // index of the pivot 
    size_t pivotIndex = partition(base, nitems, size, compar);

    // sorting the elements before the pivot, pivotIndex indicates the number of element in this part of the array
    quick_sort(base, pivotIndex, size, compar);

    //sorting element after the pivot 
    quick_sort((char *)base + (pivotIndex + 1) * size, nitems - pivotIndex - 1, size, compar);
 
 }
}
