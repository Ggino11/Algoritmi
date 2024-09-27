// FILE_UTILS_H
#ifndef FILE_UTILS_H
#define FILE_UTILS_H

/**
 * @brief Corrects words from a file using a dictionary.
 * 
 * The `text_correction` function reads words from a file named `correctme.txt` and checks each word
 * against a dictionary loaded from `dictionary.txt`. For each word in `correctme.txt`, it finds the
 * closest matches in the dictionary using the edit distance algorithm, specifically the dynamic
 * programming version `edit_distance_dyn`. The function outputs the best match or matches for each word.
 * 
 * This function does not return any value, but it prints suggestions to the standard output for words
 * that do not exactly match any dictionary entries. If a word is found in the dictionary with an
 * edit distance of zero, it is considered an exact match and no further processing is done for that word.
 * 
 * The function handles file opening and closing internally and provides error handling for cases where
 * the files cannot be opened.
 *
 * @param None
 * 
 * @return None
 */
void words_correction();

#endif 
