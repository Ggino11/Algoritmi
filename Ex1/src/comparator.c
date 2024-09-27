// comparators.c

#include "../include/comparator.h"
#include <string.h>

// Define a type for the comparison function pointers for clarity and ease of use.
typedef int(*comparFunc)(const void *, const void *);

//Define wrapper function for comparison functions, to allow use of different fucntions
int comparator(const void *param1, const void *param2, comparFunc func){
    //takes the comparison functions and the 2 parameters that are going to be compared and returns the value of the compareFunc result
    return func(param1, param2);
}

// Compare two integers.
int compare_int(const void *param1, const void *param2){
    // Handle NULL pointers upfront, simplifying the logic and reducing repetition.
    if(param1 == param2) return 0;
    if(param1 == NULL) return -1;
    if(param2 == NULL) return 1;

    const int *n1 = (const int *)param1;
    const int *n2 = (const int *)param2; 

    // subtracking expression to see which number is greater.
    // If *num1 is greater than *num2, the first expression is 1, and the second is 0, so the result is 1 - 0 = 1.
    // If *num1 is less than *num2, the first expression is 0, and the second is 1, so the result is 0 - 1 = -1.
    // If *num1 is equal to *num2, both expressions are 0, so the result is 0 - 0 = 0.
    return (*n1 > *n2) - (*n1 < *n2);

}

int compare_float(const void *param1, const void *param2){
    if(param1 == param2) return 0;
    if(param1 == NULL) return -1;
    if(param2 == NULL) return 1;

    const float *f1 = (const float *)param1;
    const float *f2 = (const float *)param2;

    //comparing float by calculating the difference and compare with 0
    float diff = *f1 - *f2; //result
    if (diff > 0) return 1;
    if (diff < 0) return -1;
    return 0; //if Diff = 0
    
}

int compare_string(const void *param1, const void *param2){
    if(param1 == param2) return 0;
    if(param1 == NULL) return -1;
    if(param2 == NULL) return 1;

    //param1,2 are const void* pointers pointing to the element being compared, since we are assuming an array of string. Param1,2 are actually  char* pointers. 
    //Cast them into correct type --> pointer to pointer char
    const char *s1 = *(const char **)param1;
    const char *s2 = *(const char **)param2;

    //Use strcmp for string comparison,
    return strcmp(s1, s2);

}