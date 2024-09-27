#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/sort_records.h"
#include "../include/mergeSort.h"
#include "../include/quickSort.h"
#include "../include/comparator.h"

#define MAXCHAR 1000
#define MAXRECORDS 20000002
//20000002


//read fields, order fields, write fields 
//define struct for records --> every record will be an instance --> allocate memory for the dyncamic array  
//struct for record of records.csv 
typedef struct {
    int id;
    char *field1; // string
    int field2; // int
    float field3; // float
} Record;
//wrapper functions to work directly with Record, access directly the fields and pass them to the general compareFunc implemented in comparator.h

//Compares two 'Record' structures based on the 'field1', which contains strings.
int compare_field1(const void *record1, const void *record2) {
// cast the void pointers to 'Record*' to work with 'Record' structures
    const Record *r1 = (const Record *)record1;
    const Record *r2 = (const Record *)record2;
//remove this comment: i can directly pass r1->field1, r2->field2 because these fields are already of type char*, which is a kind of void*
    return compare_string(&r1->field1, &r2->field1);
}

//Compares two 'Record' structures based on the 'field2', which contains ints.
int compare_field2(const void *record1, const void *record2) {
    const Record *r1 = (const Record *)record1;
    const Record *r2 = (const Record *)record2;
    return compare_int(&r1->field2, &r2->field2);
}


//Compares two 'Record' structures based on the 'field3', which contains flaots.
int compare_field3(const void *record1, const void *record2) {
    const Record *r1 = (const Record *)record1;
    const Record *r2 = (const Record *)record2;
    return compare_float(&r1->field3, &r2->field3);
}

void sort_records(FILE *infile, FILE *outfile, size_t field, size_t algo) {
    if (field < 1 || field > 3) {
        fprintf(stderr, "ERROR: Invalid field value: %zu.\n", field);
        exit(EXIT_FAILURE);
    }
    
    if (algo < 1 || algo > 2) {
        fprintf(stderr, "ERROR: Invalid algo value: %zu.\n", algo);
        exit(EXIT_FAILURE);
    }
    
    Record *records = malloc(MAXRECORDS * sizeof(Record));
    if (!records) {
        fprintf(stderr, "ERROR: Failed to allocate memory for records.\n");
        exit(EXIT_FAILURE);
    }

//Reads the input file line by line , parses each line, and stores the parsed data into the records array

    //temporary store each line read from the input file before it is parsed and processed.
    char buffer[MAXCHAR];
    size_t numRecords = 0;

    while (fgets(buffer, MAXCHAR, infile) != NULL && numRecords < MAXRECORDS) {
        //declaration of temporary variables to store the parsed fields
        int tmpId;
        char tmpField1[MAXCHAR];
        int tmpField2;
        float tmpField3;

        //parse the line read from the file into the respective fields if reads from buffer correctly (if reads  an int, a string an int and a float so if the count is equal to 4 assigne the parsed value to the record)
        if (sscanf(buffer, "%d,%[^,],%d,%f", &tmpId, tmpField1, &tmpField2, &tmpField3) == 4) {
            
            //assign parsed values to the record
            records[numRecords].id = tmpId;
            records[numRecords].field1 = strdup(tmpField1); // dubplicate the string to allocate jsut enough memory
            if (!records[numRecords].field1) {
                fprintf(stderr, "ERROR: Failed to allocate memory for field1.\n");
                exit(EXIT_FAILURE);
            }
            records[numRecords].field2 = tmpField2;
            records[numRecords].field3 = tmpField3;
            numRecords++;
        } else {
            fprintf(stderr, "ERROR: Failed to parse line: %s\n", buffer);
        }
    }

    // void (*sort_func)(void *, size_t, size_t, int (*)(const void *, const void *)) = NULL;
    comparFunc compare_func = NULL;
    switch (field) {
        case 1: compare_func = compare_field1; break;
        case 2: compare_func = compare_field2; break;
        case 3: compare_func = compare_field3; break;
    }

    if (algo == 1) {
        // sort_func = merge_sort;
        merge_sort(records, numRecords, sizeof(Record), compare_func);
    } else if (algo == 2) {
        // sort_func = quick_sort;
        quick_sort(records, numRecords, sizeof(Record), compare_func);
    }


    // if (sort_func && compare_func) {
    //     sort_func(records, numRecords, sizeof(Record), compare_func);
    // }

    // Debug print to check the records after sorting
    for (size_t i = 0; i < 10; i++) {
        printf("Record %zu: %d, %s, %d, %f\n", i, records[i].id, records[i].field1, records[i].field2, records[i].field3);
    }

    for (size_t i = 0; i < numRecords; i++) {
        fprintf(outfile, "%d,%s,%d,%f\n", records[i].id, records[i].field1, records[i].field2, records[i].field3);
        free(records[i].field1); // Free the allocated memory for field1
    }

    free(records);
}