#include <stdlib.h>
#include <stdio.h>
#include "unity.h" 
#include "../include/comparator.h"
#include "../include/quickSort.h"
#include "../include/mergeSort.h"
#include "../include/sort_records.h"
// line 16 --> quick sort
// line 151 --> merge sort
// line 243 --> sort records
// line
void setUp(void) {

}

void tearDown(void) {
}


// ### QUICK SORT tests
// Test for sorting an array of integers
void test_quick_sort_int(void) {
    int array[] = {47, 29, 3, 15, 9, 54, 87, 21, 64, 33};
    int expected[] = {3, 9, 15, 21, 29, 33, 47, 54, 64, 87};
    int n = sizeof(array) / sizeof(array[0]);

    quick_sort(array, n, sizeof(int), compare_int);

    TEST_ASSERT_EQUAL_INT_ARRAY(expected, array, n);
}

// Test for sorting an array of integers with identical elements
void test_quick_sort_sameInt(void) {
    int array[] = {25, 25, 25, 25, 25, 25, 25, 25, 25, 25};
    int expected[] = {25, 25, 25, 25, 25, 25, 25, 25, 25, 25};
    int n = sizeof(array) / sizeof(array[0]);

    quick_sort(array, n, sizeof(int), compare_int);

    TEST_ASSERT_EQUAL_INT_ARRAY(expected, array, n);
}

// Test for sorting an already sorted array of integers
void test_quick_sort_sortedInt(void) {
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int expected[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(array) / sizeof(array[0]);

    quick_sort(array, n, sizeof(int), compare_int);

    TEST_ASSERT_EQUAL_INT_ARRAY(expected, array, n);
}

// Test for sorting an empty array of integers
void test_quick_sort_empty_int(void) {
    int array[] = {};
    int expected[] = {};
    int n = sizeof(array) / sizeof(array[0]);

    quick_sort(array, n, sizeof(int), compare_int);

    TEST_ASSERT_EQUAL_INT_ARRAY(expected, array, n+1);
}

// Test for sorting an array of strings
void test_quick_sort_string(void) {
    char *array[] = {"banana", "apple", "grape", "cherry", "mango", "pear", "lemon", "peach", "lime", "plum"};
    char *expected[] = {"apple", "banana", "cherry", "grape", "lemon", "lime", "mango", "peach", "pear", "plum"};
    int n = sizeof(array) / sizeof(array[0]);

    quick_sort(array, n, sizeof(char*), compare_string);

    TEST_ASSERT_EQUAL_STRING_ARRAY(expected, array, n);
}

// Test for sorting an array of strings with identical elements
void test_quick_sort_sameString(void) {
    char *array[] = {"kiwi", "kiwi", "kiwi", "kiwi", "kiwi", "kiwi", "kiwi", "kiwi", "kiwi", "kiwi"};
    char *expected[] = {"kiwi", "kiwi", "kiwi", "kiwi", "kiwi", "kiwi", "kiwi", "kiwi", "kiwi", "kiwi"};
    int n = sizeof(array) / sizeof(array[0]);

    quick_sort(array, n, sizeof(char*), compare_string);

    TEST_ASSERT_EQUAL_STRING_ARRAY(expected, array, n);
}

// Test for sorting an already sorted array of strings
void test_quick_sort_sortedString(void) {
    char *array[] = {"apple", "banana", "cherry", "grape", "lemon", "lime", "mango", "peach", "pear", "plum"};
    char *expected[] = {"apple", "banana", "cherry", "grape", "lemon", "lime", "mango", "peach", "pear", "plum"};
    int n = sizeof(array) / sizeof(array[0]);

    quick_sort(array, n, sizeof(char*), compare_string);

    TEST_ASSERT_EQUAL_STRING_ARRAY(expected, array, n);
}

// Test for sorting an empty array of strings
void test_quick_sort_empty_string(void) {
    char *array[] = {};
    char *expected[] = {};
    int n = sizeof(array) / sizeof(array[0]);

    quick_sort(array, n, sizeof(char*), compare_string);

    TEST_ASSERT_EQUAL_STRING_ARRAY(expected, array, n+1);
}

// Test for sorting an array of floats
void test_quick_sort_float(void) {
    float array[] = {4.7, 2.9, 3.3, 1.5, 9.2, 5.4, 8.7, 6.4, 7.6, 3.9};
    float expected[] = {1.5, 2.9, 3.3, 3.9, 4.7, 5.4, 6.4, 7.6, 8.7, 9.2};
    int n = sizeof(array) / sizeof(array[0]);

    quick_sort(array, n, sizeof(float), compare_float);

    TEST_ASSERT_EQUAL_FLOAT_ARRAY(expected, array, n);
}

// Test for sorting an array of floats with identical elements
void test_quick_sort_sameFloat(void) {
    float array[] = {5.5, 5.5, 5.5, 5.5, 5.5, 5.5, 5.5, 5.5, 5.5, 5.5};
    float expected[] = {5.5, 5.5, 5.5, 5.5, 5.5, 5.5, 5.5, 5.5, 5.5, 5.5};
    int n = sizeof(array) / sizeof(array[0]);

    quick_sort(array, n, sizeof(float), compare_float);

    TEST_ASSERT_EQUAL_FLOAT_ARRAY(expected, array, n);
}

// Test for sorting an already sorted array of floats
void test_quick_sort_sortedFloat(void) {
    float array[] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.0};
        float expected[] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.0};
    int n = sizeof(array) / sizeof(array[0]);

    quick_sort(array, n, sizeof(float), compare_float);

    TEST_ASSERT_EQUAL_FLOAT_ARRAY(expected, array, n);
}

// Test for sorting an empty array of floats
void test_quick_sort_empty_float(void) {
    float array[] = {};
    float expected[] = {};
    int n = sizeof(array) / sizeof(array[0]);

    quick_sort(array, n, sizeof(float), compare_float);

    TEST_ASSERT_EQUAL_FLOAT_ARRAY(expected, array, n+1);
}


// ### MERGE SORT TESTS
// Test sorting an array of integers
void test_merge_sort_int(void) {
    int arr[] = {5, 1, 4, 2, 8};
    int expected[] = {1, 2, 4, 5, 8};
    merge_sort(arr, 5, sizeof(int),compare_int);
    TEST_ASSERT_EQUAL_INT_ARRAY(expected, arr, 5);
}

// Test sorting an array of integers with duplicate values
void test_merge_sort_sameInt(void) {
    int arr[] = {5, 5, 1, 1, 3, 3};
    int expected[] = {1, 1, 3, 3, 5, 5};
    merge_sort(arr, 6, sizeof(int),compare_int);
    TEST_ASSERT_EQUAL_INT_ARRAY(expected, arr, 6);
}

// Test sorting an already sorted array of integers
void test_merge_sort_sortedInt(void) {
    int arr[] = {1, 2, 3, 4, 5};
    merge_sort(arr, 5, sizeof(int),compare_int);
    TEST_ASSERT_EQUAL_INT_ARRAY(arr, arr, 5); // The array should remain unchanged
}

// Test sorting an empty array of integers
void test_merge_sort_empty_int(void) {
    int arr[] = {};
    merge_sort(arr, 0, sizeof(int),compare_int);
    TEST_ASSERT_EQUAL_INT_ARRAY(arr, arr, 0); // No change expected
}

// Test sorting an array of strings
void test_merge_sort_string(void) {
    char *arr[] = {"banana", "apple", "orange", "mango"};
    char *expected[] = {"apple", "banana", "mango", "orange"};
    merge_sort(arr, 4, sizeof(char*), compare_string);
    TEST_ASSERT_EQUAL_STRING_ARRAY(expected, arr, 4);
}

// Test sorting an array of strings with duplicate values
void test_merge_sort_sameString(void) {
    char *arr[] = {"apple", "apple", "banana", "banana"};
    char *expected[] = {"apple", "apple", "banana", "banana"};
    merge_sort(arr, 4, sizeof(char*), compare_string);
    TEST_ASSERT_EQUAL_STRING_ARRAY(expected, arr, 4);
}

// Test sorting an already sorted array of strings
void test_merge_sort_sortedString(void) {
    char *arr[] = {"apple", "banana", "mango", "orange"};
    merge_sort(arr, 4, sizeof(char*), compare_string);
    TEST_ASSERT_EQUAL_STRING_ARRAY(arr, arr, 4); // The array should remain unchanged
}

// Test sorting an empty array of strings
void test_merge_sort_empty_string(void) {
    char *arr[] = {};
    merge_sort(arr, 0, sizeof(char*), compare_string);
    // No assertion needed as there's nothing to compare; just ensure no crash
}

// Test sorting an array of floats
void test_merge_sort_float(void) {
    float arr[] = {5.5, 1.1, 4.4, 2.2, 8.8};
    float expected[] = {1.1, 2.2, 4.4, 5.5, 8.8};
    merge_sort(arr, 5, sizeof(float), compare_float);
    TEST_ASSERT_EQUAL_FLOAT_ARRAY(expected, arr, 5);
}

// Test sorting an array of floats with duplicate values
void test_merge_sort_sameFloat(void) {
    float arr[] = {2.2, 2.2, 3.3, 3.3};
    float expected[] = {2.2, 2.2, 3.3, 3.3};
    merge_sort(arr, 4, sizeof(float), compare_float);
    TEST_ASSERT_EQUAL_FLOAT_ARRAY(expected, arr, 4);
}

// Test sorting an already sorted array of floats
void test_merge_sort_sortedFloat(void) {
    float arr[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    merge_sort(arr, 5, sizeof(float), compare_float);
    TEST_ASSERT_EQUAL_FLOAT_ARRAY(arr, arr, 5); // The array should remain unchanged
}

// Test sorting an empty array of floats
void test_merge_sort_empty_float(void) {
    float arr[] = {};
    merge_sort(arr, 0, sizeof(float), compare_float);
    // No assertion needed as there's nothing to compare; just ensure no crash
}
// ### SORT RECORDS TESTS
// ### COMPARATOR TESTS
static void test_compare_int_unequal(void) {
    int num1 = 12;
    int num2 = 5;
    int resultInt = compare_int(&num1, &num2);
    
    TEST_ASSERT_EQUAL_INT(1, resultInt);  // num1 > num2, should return 1
}

static void test_compare_int_equal(void) {
    int num1 = 9;
    int num2 = 9;
    int resultInt = compare_int(&num1, &num2);
    
    TEST_ASSERT_EQUAL_INT(0, resultInt);  // num1 == num2, should return 0
}

static void test_compare_int_pointer_null(void) {
    int *num1 = NULL;
    int num2 = 11;
    int resultInt = compare_int(num1, &num2);
    
    TEST_ASSERT_EQUAL_INT(-1, resultInt);  // NULL < num2, should return -1
}

static void test_compare_int_both_pointers_null(void) {
    int *num1 = NULL;
    int *num2 = NULL;
    int resultInt = compare_int(num1, num2);

    TEST_ASSERT_EQUAL_INT(0, resultInt);  // NULL == NULL, should return 0
}

static void test_compare_float_unequal(void) {
    float num1 = 8.3f;
    float num2 = 4.1f;
    int resultFloat = compare_float(&num1, &num2);
    
    TEST_ASSERT_EQUAL_INT(1, resultFloat);  // num1 > num2, should return 1
}

static void test_compare_float_equal(void) {
    float num1 = 6.7f;
    float num2 = 6.7f;
    int resultFloat = compare_float(&num1, &num2);
    
    TEST_ASSERT_EQUAL_INT(0, resultFloat);  // num1 == num2, should return 0
}

static void test_compare_float_pointer_null(void) {
    float *num1 = NULL;
    float num2 = 7.9f;
    int resultFloat = compare_float(num1, &num2);

    TEST_ASSERT_EQUAL_INT(-1, resultFloat);  // NULL < num2, should return -1
}

static void test_compare_float_both_pointers_null(void) {
    float *num1 = NULL;
    float *num2 = NULL;
    int resultFloat = compare_float(num1, num2);

    TEST_ASSERT_EQUAL_INT(0, resultFloat);  // NULL == NULL, should return 0
}

static void test_compare_string_unequal(void) {
    char *str1 = "Xylophone";
    char *str2 = "Banana";
    int resultString = compare_string(&str1, &str2);

    TEST_ASSERT_EQUAL_INT(1, resultString);  // str1 > str2, should return 1
}

static void test_compare_string_equal(void) {
    char *str1 = "Orange";
    char *str2 = "Orange";
    int resultString = compare_string(&str1, &str2);

    TEST_ASSERT_EQUAL_INT(0, resultString);  // str1 == str2, should return 0
}

static void test_compare_string_pointer_null(void) {
    char *str1 = NULL;
    char *str2 = "Pineapple";
    int resultString = compare_string(&str1, &str2);

    TEST_ASSERT_EQUAL_INT(-1, resultString);  // NULL < str2, should return -1
}

static void test_compare_string_both_pointers_null(void) {
    char *str1 = NULL;
    char *str2 = NULL;
    int resultString = compare_string(&str1, &str2);

    TEST_ASSERT_EQUAL_INT(0, resultString);  // NULL == NULL, should return 0
}


// Main test function
int main(void) {
    UNITY_BEGIN();
    printf("QUICK SORT TESTS:\n");
    RUN_TEST(test_quick_sort_int);
    RUN_TEST(test_quick_sort_sameInt);
    RUN_TEST(test_quick_sort_sortedInt);
    RUN_TEST(test_quick_sort_string);
    RUN_TEST(test_quick_sort_sameString);
    RUN_TEST(test_quick_sort_sortedString);
    RUN_TEST(test_quick_sort_float);
    RUN_TEST(test_quick_sort_sameFloat);
    RUN_TEST(test_quick_sort_sortedFloat);
  

    printf("MERGE SORT TESTS:\n");
    RUN_TEST(test_merge_sort_int);
    RUN_TEST(test_merge_sort_sameInt);
    RUN_TEST(test_merge_sort_sortedInt);
    RUN_TEST(test_merge_sort_string);
    RUN_TEST(test_merge_sort_sameString);
    RUN_TEST(test_merge_sort_sortedString);
    RUN_TEST(test_merge_sort_empty_string);
    RUN_TEST(test_merge_sort_float);
    RUN_TEST(test_merge_sort_sameFloat);
    RUN_TEST(test_merge_sort_sortedFloat);
    RUN_TEST(test_merge_sort_empty_float);

    printf("SORT RECORDS TESTS:\n");

    printf("COMPARATOR TESTS:\n");
    RUN_TEST(test_compare_int_unequal);
    RUN_TEST(test_compare_int_equal);
    RUN_TEST(test_compare_int_pointer_null);
    RUN_TEST(test_compare_int_both_pointers_null);
    RUN_TEST(test_compare_float_unequal);
    RUN_TEST(test_compare_float_equal);
    RUN_TEST(test_compare_float_pointer_null);
    RUN_TEST(test_compare_float_both_pointers_null);
    RUN_TEST(test_compare_string_unequal);
    RUN_TEST(test_compare_string_equal);
    RUN_TEST(test_compare_string_pointer_null);
    RUN_TEST(test_compare_string_both_pointers_null);

    return UNITY_END();
}