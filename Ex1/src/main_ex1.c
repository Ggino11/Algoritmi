#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include "../include/quickSort.h"
#include "../include/comparator.h"
#include "../include/mergeSort.h"
#include "../include/sort_records.h"

int main(int argc, char *argv[])
{
    // check if correct number of arguments is provided
    if (argc != 3) {
        fprintf(stderr, "ERROR: Use correct number of argument.\n Usage: %s <field_used>, <alghoritm>", argv[0]);
        return EXIT_FAILURE;
    }

    // assign arguments to variables
    char *inputFilePath = "../data/records.csv";
    char *outputFilePath = "../data/sorted_records.csv";
    int fieldToSortBy = atoi(argv[1]); // convert to integer
    int algorithm = atoi(argv[2]);     // convert to integer

    // check correct arguments for field input and algorithm
    if (fieldToSortBy < 1 || fieldToSortBy > 3)  {
        fprintf(stderr, "ERROR:  Wrong field input.\n");
        return EXIT_FAILURE;
    }

    if (algorithm < 1 || algorithm > 2)  {
        fprintf(stderr, "ERROR: Wrong algorithm input. \n");
        return EXIT_FAILURE;
    }

    // Open the input file
    FILE *unsorted_csv = fopen(inputFilePath, "r");
    if (unsorted_csv == NULL) {
       fprintf(stderr, "ERROR: Unable to open input file '%s'\n", inputFilePath);
        return EXIT_FAILURE;
    }

    // Open/Write output file
    FILE *sorted_csv = fopen(outputFilePath, "w");
    if (sorted_csv == NULL) {
        fprintf(stderr, "Error: Unable to create/open output file '%s'\n", outputFilePath);
        fclose(unsorted_csv);
        return EXIT_FAILURE;
    }
    //Measure the start time
     clock_t start = clock();

    //run the sortimng funciton
    sort_records(unsorted_csv, sorted_csv, fieldToSortBy, algorithm);

    // Measure the end time and calculate execution time
    clock_t end = clock();
    double execTime = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Print execution time
    printf("Execution time: %f seconds\n", execTime);

    // Cleanup: Close the files
    fclose(unsorted_csv);
    fclose(sorted_csv);

    return EXIT_SUCCESS;
}