#include <stdlib.h>
#include <stdio.h>
#include "unity.h"
#include "../include/edit_distance.h" 
#include "../include/file_utils.h"


// Setup function to initialize resources before each test
void setUp(void) {
    // No setup required for these tests
}

// Teardown function to clean up resources after each test
void tearDown(void) {
    // No teardown required for these tests
}

// Test function for the recursive edit_distance function
void test_edit_distance(void) {
    // Test cases with intentional misspellings
    TEST_ASSERT_EQUAL_INT(2, edit_distance("cinqve", "cinque")); // expected 2 remove v add u
    TEST_ASSERT_EQUAL_INT(1, edit_distance("made", "madre"));    // expected 1 add r
    TEST_ASSERT_EQUAL_INT(3, edit_distance("perpeteva", "ripeteva")); // expected 3remove p, e add i
    TEST_ASSERT_EQUAL_INT(2, edit_distance("selice", "felice")); // expected 2 remove s add f
    TEST_ASSERT_EQUAL_INT(2, edit_distance("squola", "scuola")); // expected 2 remove q add c
    TEST_ASSERT_EQUAL_INT(1, edit_distance("domandrono", "domandarono")); // expected 1 add a
    TEST_ASSERT_EQUAL_INT(1, edit_distance("vuolessi", "volessi")); // expected 1 remove u
    TEST_ASSERT_EQUAL_INT(2, edit_distance("corpito", "compito")); // expected 2 remove r add m
    TEST_ASSERT_EQUAL_INT(2, edit_distance("wita", "vita"));       // expected 2 remove w add v

    printf("All basic edit_distance tests passed !\n");
}

// Test function for the dynamic programming edit_distance_dyn function
void test_edit_distance_dyn(void) {
    // Test cases with intentional misspellings
    TEST_ASSERT_EQUAL_INT(2, edit_distance_dyn("cinqve", "cinque")); // expected 2 remove v add u
    TEST_ASSERT_EQUAL_INT(1, edit_distance_dyn("made", "madre"));    // expected 1 add r
    TEST_ASSERT_EQUAL_INT(3, edit_distance_dyn("perpeteva", "ripeteva")); // expected 3remove p, e add i
    TEST_ASSERT_EQUAL_INT(2, edit_distance_dyn("selice", "felice")); // expected 2 remove s add f
    TEST_ASSERT_EQUAL_INT(2, edit_distance_dyn("squola", "scuola")); // expected 2 remove q add c
    TEST_ASSERT_EQUAL_INT(1, edit_distance_dyn("domandrono", "domandarono")); // expected 1 add a
    TEST_ASSERT_EQUAL_INT(1, edit_distance_dyn("vuolessi", "volessi")); // expected 1 remove u
    TEST_ASSERT_EQUAL_INT(2, edit_distance_dyn("corpito", "compito")); // expected 2 remove r add m
    TEST_ASSERT_EQUAL_INT(2, edit_distance_dyn("wita", "vita"));       // expected 2 remove w add v

    printf("All dynamic edit_distance_dyn tests passed!\n");
}

// Main function to run all tests
int main(void) {
    UNITY_BEGIN();  // Initialize Unity Test Framework
    printf("Edit Distance:\n");
    RUN_TEST(test_edit_distance); // Run tests for the recursive function
    printf("Edit Distance Dyn:\n");
    RUN_TEST(test_edit_distance_dyn); // Run tests for the dynamic programming function
    return UNITY_END();           // Finish Unity Test Framework
}