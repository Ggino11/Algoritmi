//compator.h
#ifndef COMPARATOR_H
#define COMPARATOR_H

// Defines a type for function pointers to comparison functions.
typedef int(*comparFunc)(const void *, const void *);

/**
 * Compares two records by field1 which is a string, field2 which is a integer nad by field3 which is a floating-point number.
 * 
 * @param a Pointer to the first record to compare.
 * @param b Pointer to the second record to compare.
 * @return Negative if first is less than second, 0 if equal, positive if first is greater.
 */

// Comparison function for field1
int compare_string(const void *a, const void *b);

// Comparison function for field2
int compare_int(const void* a, const void* b);

// Comparison function for field3
int compare_float(const void* a, const void* b);


#endif