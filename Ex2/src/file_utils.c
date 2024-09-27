#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "../include/edit_distance.h"
#include "../include/file_utils.h"
#define MAXCHAR 100
#define MAXCHARWORDS 50000

void words_correction() {
    /*
    ** The function searches, for each of the correctme file's words,
    ** the words in the dictionary with the smallest edit_distance using edit_distance_dyn.
    */

    FILE *dictionaryFile = fopen("../data/dictionary.txt", "r");
    FILE *correctmeFile = fopen("../data/correctme.txt", "r");

    if (!dictionaryFile || !correctmeFile) {
        perror("Error opening file");
        exit(EXIT_FAILURE);        
    }

    char currentWord[MAXCHAR];
    char dictionaryWord[MAXCHAR];

    // Process each word from the correctme file
    while (fscanf(correctmeFile, "%s", currentWord) != EOF)
    {
        fseek(dictionaryFile, 0, SEEK_SET); // Rewind dictionary file for each new word

        int lowestDistance = INT_MAX;
        char closestWords[MAXCHARWORDS] = ""; // Store the closest words

        while (fgets(dictionaryWord, sizeof(dictionaryWord), dictionaryFile))
        {
            dictionaryWord[strcspn(dictionaryWord, "\n")] = '\0'; // Remove newline character

            int tmpEditDistance = edit_distance_dyn(dictionaryWord, currentWord); // Use the dynamic version
            if (tmpEditDistance < lowestDistance)
            {
                // Smaller edit distance found, update closest words
                lowestDistance = tmpEditDistance;
                strcpy(closestWords, dictionaryWord);

                if (tmpEditDistance == 0)
                {
                    // Exact match found, no need to continue
                    break;
                }
            }
            else if (tmpEditDistance == lowestDistance)
            {
                // Same distance, add to the list
                strcat(closestWords, ", ");
                strcat(closestWords, dictionaryWord);
            }
        }

        // Print the results for the current word
        printf("%s (ED: %d): %s\n", currentWord, lowestDistance, closestWords);
    }

    fclose(dictionaryFile);
    fclose(correctmeFile);
}