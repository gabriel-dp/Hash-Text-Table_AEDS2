#include "hash.h"
#include <ctype.h>

#define MAX_CHAR_PER_LINE 100

void removeNewLine (char string[MAX_WORD_LENGTH + 1]) {
    if (string[strlen(string)-1] == '\n') string[strlen(string)-1] = '\0';
}

void toLowerCaseString(char string[MAX_WORD_LENGTH + 1]) {
    for (int i = 0; i < strlen(string); i++) {
        string[i] = tolower(string[i]);
    }
}

void insertWordsFromFile(hash* hashTable, char* fileName){
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        printf("\nFile does not exist\n\n");
        return;
    }

    char lineString[MAX_CHAR_PER_LINE];
    const char* separation = " .,!?";

    int line = 0;
    while (fgets(lineString, MAX_CHAR_PER_LINE-1, file) != NULL) {
        line++;
        removeNewLine(lineString);

        char* token;
        char* res = NULL;

        for (token = strtok_r(lineString, separation, &res); 
            token != NULL; 
            token = strtok_r(NULL, separation, &res)) {   
            toLowerCaseString(token);
            insertElement(hashTable, token, line);
        }
    }
}

void printOccurrencesFromFile(hash* hashTable, char* fileName){
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        printf("\nFile does not exist\n\n");
        return;
    }

    char lineString[MAX_WORD_LENGTH+1];
    int isFirst = 1;

    while (fgets(lineString, MAX_WORD_LENGTH, file) != NULL){
        if(isFirst){
            isFirst = 0;
            continue;
        }

        removeNewLine(lineString);
        toLowerCaseString(lineString);
        printOccurrences(hashTable, lineString);
    }
}

void main() {
    hash* hashTable = createHashTable(SLOTS);

    insertWordsFromFile(hashTable, "./data/input.txt");
    printOccurrencesFromFile(hashTable, "./data/words.txt");
}