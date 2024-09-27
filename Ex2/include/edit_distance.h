//edit_distance.h
#ifndef EDIT_DISTANCE_H
#define EDIT_DISTANCE_H

/**
 * Computes the edit distance between two strings using a recursive approach.
 * 
 * The edit distance is the minimum number of operations (insertions or deletions)
 * required to transform one string into the other.
 * 
 * @param s1 The target string (string to be transformed into).
 * @param s2 The source string (string to be transformed).
 * @return The minimum number of operations required to transform s2 into s1.
 */
int edit_distance(const char *s1, const char *s2);

/**
 * Computes the edit distance between two strings using dynamic programming.
 * 
 * @param s1 The target string (string to be transformed into).
 * @param s2 The source string (string to be transformed).
 * @return The minimum number of operations required to transform s2 into s1.
 */
int edit_distance_dyn(const char *s1, const char* s2);

#endif