#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include "../include/edit_distance.h"
#include "../include/file_utils.h"

int main(){
    // declare variables for measuring execution time 
    clock_t start, end;
    double execution_time;

    // record start time
    start = clock();

    // call words correction func to perform correction of correctme.txt
    words_correction();


    // record end time
    end = clock();

    //calclate the execution time in seconds
    execution_time = ((double)(end - start)/ CLOCKS_PER_SEC);

    printf("Execution time: %f seconds\n", execution_time);

    
}   