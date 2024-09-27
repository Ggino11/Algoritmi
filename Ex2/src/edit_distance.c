#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <limits.h>
#include "../include/edit_distance.h"

int edit_distance(const char *s1, const char *s2) {

    //string length 
    int len1 = strlen(s1), len2 = strlen(s2); 

    // base cases 
    if (len1 == 0) return len2; // --> all deletions
    if (len2 == 0) return len1; // --> all insertions

    //if pointer to fist char in s1 is equal to pointer to first char of s2 call recursively edit_distance otherwise set distance no operation to max int meaning to ignore this option because it represents an invalid path
    int d_no_op = (s1[0] == s2[0]) ? edit_distance(s1 + 1, s2 + 1) : INT_MAX;

    //if pointer to second char of s1 and s2 are !=
    //call edit distance for s1 unchanged and for s2 deleting first char of s2 and adding one to the result of the operation
    int d_canc = 1 + edit_distance(s1, s2 + 1);
    //same process but add char to s1 instead of deleting 
    int d_ins = 1 + edit_distance(s1 + 1, s2);
       
    //if valueTrue compare d_no_op and d_ins and return min value, else compare d_canc and d_ins and return min value
    return (d_no_op < d_canc) ? ((d_no_op < d_ins) ? d_no_op : d_ins) : ((d_canc < d_ins) ? d_canc : d_ins);
}

// Recoursive func to calculate 
int edit_distance_memo(const char *s1, const char* s2, int len1, int len2, int **matrix) {
    // Check if the result for this subproblem (s1 of length len1, s2 of length len2) is already computed.
    // If the value is not -1, it means it has been computed before and can be reused.
    if (matrix[len1][len2] != -1) return matrix[len1][len2];

    // Base case: If the first string (s1) is empty, the only option is to insert all characters of s2.
    if (len1 == 0) return matrix[len1][len2] = len2;

    // Base case: If the second string (s2) is empty, the only option is to insert all characters of s1.
    if (len2 == 0) return matrix[len1][len2] = len1;

    // Recursive case: Calculate the cost if no operation is needed, i.e., if the first characters of s1 and s2 are the same.
    // Otherwise, set it to a very high value (INT_MAX) to invalidate this path.
    int d_no_op = (s1[0] == s2[0]) ? edit_distance_memo(s1 + 1, s2 + 1, len1 - 1, len2 - 1, matrix) : INT_MAX;

    // Recursive case: Calculate the cost if we delete the first character of s2.
    int d_canc = 1 + edit_distance_memo(s1, s2 + 1, len1, len2 - 1, matrix);

    // Recursive case: Calculate the cost if we insert a character into s1.
    int d_ins = 1 + edit_distance_memo(s1 + 1, s2, len1 - 1, len2, matrix);

    // Store the minimum value among the three calculated distances in the matrix to avoid recalculations.
    // This value represents the minimum edit distance between the first len1 characters of s1 and the first len2 characters of s2.
    return matrix[len1][len2] = (d_no_op < d_canc) ? ((d_no_op < d_ins) ? d_no_op : d_ins) : ((d_canc < d_ins) ? d_canc : d_ins);
}

int edit_distance_dyn(const char *s1, const char *s2) {
    // Get the lengths of the two strings.
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    
    // Allocate memory for the matrix to store the results of subproblems.
    // The matrix is sized (len1+1) x (len2+1) because we consider the cases where one of the strings is empty.
    int **matrix = (int **)malloc((len1 + 1) * sizeof(int *));

    // Initialize each row of the matrix.
    for (int i = 0; i <= len1; i++) {
        matrix[i] = (int *)malloc((len2 + 1) * sizeof(int));
        // Set all elements to -1 initially, indicating that these subproblems haven't been solved yet.
        for (int j = 0; j <= len2; j++) {
            matrix[i][j] = -1;
        }
    }

    // Start the recursive computation with memoization.
    // The result is the edit distance between the full strings s1 and s2.
    int distance = edit_distance_memo(s1, s2, len1, len2, matrix);

    // free allocated memory
    for (int i = 0; i <= len1; i++) {
        free(matrix[i]);
    }

    free(matrix);
    
    // Return the computed edit distance.
    return distance;
}
