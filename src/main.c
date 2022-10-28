#include <ctype.h>

#include "hash.h"

#define MAX_CHAR_PER_LINE 100

// Function to remove \n char in end of line
void removeNewLine(char* string) {
    strtok(string, "\n");
}

// Function to standardize a string (lowercase)
void toLowerCaseString(char string[MAX_WORD_LENGTH + 1]) {
    for (int i = 0; i < strlen(string); i++) {
        string[i] = tolower(string[i]);
    }
}

/*
**  INSERT WORDS FROM FILE
**  - Open the file
**  - Read line-by-line
**  - Split words
**  - Add each word to hashTable
*/
void insertWordsFromFile(hash* hashTable, char* fileName) {
    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
        printf("\nERROR - Input file not found\n\n");
        exit(1);
    }

    char lineString[MAX_CHAR_PER_LINE];
    const char* delimiters = " .,!?";

    int line = 1;
    while (fgets(lineString, MAX_CHAR_PER_LINE - 1, file) != NULL) {
        removeNewLine(lineString);

        char* singleWord = strtok(lineString, delimiters);
        while (singleWord != NULL) {
            if (strlen(singleWord) >= 2) {  // Ignore single-letter words
                toLowerCaseString(singleWord);
                insertElement(hashTable, singleWord, line);
            }
            singleWord = strtok(NULL, delimiters);
        }

        line++;
    }
}

/*
**  PRINT OCCURRENCES FROM FILE
**  - Open the file
**  - Read line-by-line and get words
**  - Print word occurrences in hashTable
*/
void printOccurrencesFromFile(hash* hashTable, char* fileName) {
    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
        printf("\nERROR - Words file not found\n\n");
        exit(1);
    }

    char lineString[MAX_WORD_LENGTH + 1];
    int isFirst = 1;

    while (fgets(lineString, MAX_WORD_LENGTH, file) != NULL) {
        if (isFirst) {
            isFirst = 0;
            continue;  // Ignores first line
        }

        removeNewLine(lineString);
        toLowerCaseString(lineString);
        printOccurrences(hashTable, lineString);
    }
}

void main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("\nERROR - Type correctly the directory of input and words files\n\n");
        exit(1);
    }

    hash* hashTable = createHashTable();

    insertWordsFromFile(hashTable, argv[1]);
    printOccurrencesFromFile(hashTable, argv[2]);
}