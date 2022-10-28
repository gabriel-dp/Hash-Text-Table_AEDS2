#include "hash.h"

#define EMPTY "-----"
#define INDEX_NOT_FOUND -1

// Create hashTable and assign EMPTY for all words
hash* createHashTable() {
    hash* newHashTable = (hash*)(malloc(SLOTS * sizeof(hash)));
    for (int i = 0; i < SLOTS; i++) {
        strcpy(newHashTable[i].word, EMPTY);
        newHashTable[i].first = NULL;
    }
    return newHashTable;
}

// Generate hash based on each char value (ASCII) and position
int hashGenerator(char* string) {
    int key = 0;
    for (int i = 0; i < strlen(string); i++) {
        key += ((i + 1) * string[i]);
    }
    int index = key % SLOTS;
    return index;
}

// Create a new occurrence by new line
occurrence_t* createOccurrence(int line) {
    occurrence_t* newOccurrence = (occurrence_t*)malloc(sizeof(occurrence_t));
    newOccurrence->line = line;
    newOccurrence->p_prox = NULL;
    return newOccurrence;
}

// Add new occurrence to hashCell (same line or another)
void addOccurrence(hash* hashCell, int line) {
    occurrence_t** aux = &hashCell->first;

    if (*aux == NULL) {  // First occurrence is NULL
        *aux = createOccurrence(line);
        hashCell->quantity = 1;
    } else {
        while ((*aux)->p_prox != NULL) {
            aux = &((*aux)->p_prox);  // Browse the list until find the last occurrence
        }
        if (line != (*aux)->line) (*aux)->p_prox = createOccurrence(line);
        hashCell->quantity++;
    }
}

// Insert the string in hashTable by hash
void insertElement(hash* hashTable, char* string, int line) {
    int index = hashGenerator(string);

    int counter = 0;
    while (counter < SLOTS) {
        // Slot is EMPTY, can assign the string and add new occurrence
        if (strcmp(hashTable[index].word, EMPTY) == 0) {
            strcpy(hashTable[index].word, string);
            addOccurrence(&hashTable[index], line);
            return;
        }

        // Slot has the same string, add line occurrence
        if (strcmp(hashTable[index].word, string) == 0) {
            addOccurrence(&hashTable[index], line);
            return;
        }

        counter++;
        index = ++index % SLOTS;
    }

    printf("\nERROR - HashTable full (more than %d different words)\n\n", SLOTS);
    exit(1);
}

// Search string in hashTable by hash
int searchElementIndex(hash* hashTable, char* string) {
    int index = hashGenerator(string);
    int counter = 0;
    while (counter < SLOTS) {
        // Slot is EMPTY, string was not found
        if (strcmp(hashTable[index].word, EMPTY) == 0) {
            return INDEX_NOT_FOUND;
        }

        // Slot has the string, return index
        if (strcmp(hashTable[index].word, string) == 0) {
            return index;
        }

        counter++;
        index = ++index % SLOTS;
    }

    // Seached in all slots but did not found
    return INDEX_NOT_FOUND;
}

// Print "quantity" + "word" + occurrences of a string in the hashTable
void printOccurrences(hash* hashTable, char* string) {
    int index = searchElementIndex(hashTable, string);
    if (index == INDEX_NOT_FOUND) {
        printf("0 %s\n", string);
        return;
    }

    printf("%d %s", hashTable[index].quantity, hashTable[index].word);

    // Browse the list printing the line
    occurrence_t** aux = &(hashTable[index].first);
    do {
        printf(" %d", (*aux)->line);
        aux = &((*aux)->p_prox);
    } while ((*aux) != NULL);

    printf("\n");
}