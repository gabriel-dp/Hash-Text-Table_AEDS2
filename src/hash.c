#include "hash.h"

#define EMPTY "-----"
#define INDEX_NOT_FOUND -1

hash* createHashTable(int length) {
    hash* newHashTable = (hash*)(malloc(length * sizeof(hash)));
    for (int i = 0; i < length; i++) {
        strcpy(newHashTable[i].word, EMPTY);
        newHashTable[i].first = NULL;
    }
    return newHashTable;
}

int hashGenerator(char* string) {
    int key = 0;
    for (int i = 0; i < strlen(string); i++) {
        key += ((i + 1) * string[i]);
    }
    int index = key % SLOTS;
    return index;
}

occurrence_t* createOccurrence(int line) {
    occurrence_t* newOccurrence = (occurrence_t*)malloc(sizeof(occurrence_t));
    newOccurrence->line = line;
    newOccurrence->p_prox = NULL;
    return newOccurrence;
}

void addOccurrence(hash* hashCell, int line) {
    occurrence_t** aux = &hashCell->first;

    if (*aux == NULL) {
        *aux = createOccurrence(line);
        hashCell->quantity = 1;
    } else {
        while ((*aux)->p_prox != NULL) {
            aux = &((*aux)->p_prox);  // NAVIGATE LIST
        }
        if (line != (*aux)->line) (*aux)->p_prox = createOccurrence(line);
        hashCell->quantity++;
    }
}

void insertElement(hash* hashTable, char* string, int line) {
    int index = hashGenerator(string);

    int counter = 0;
    while (counter < SLOTS) {
        if (strcmp(hashTable[index].word, EMPTY) == 0) {
            strcpy(hashTable[index].word, string);
            addOccurrence(&hashTable[index], line);
            return;
        }
        if (strcmp(hashTable[index].word, string) == 0) {
            addOccurrence(&hashTable[index], line);
            return;
        }
        counter++;
        index = ++index % SLOTS;
    }
    printf("ERROR - HASH COMPLETE");
    exit(1);
}

int searchElementIndex(hash* hashTable, char* string){

    int index = hashGenerator(string);
    int counter = 0;
    while (counter < SLOTS){
        if (strcmp(hashTable[index].word, EMPTY) == 0){
            return INDEX_NOT_FOUND;
        }
        if (strcmp(hashTable[index].word, string) == 0){
            return index;
        }

        counter++;
        index = ++index % SLOTS;
    }
    return INDEX_NOT_FOUND;
    
}

void printOccurrences(hash* hashTable, char* string){
    int index = searchElementIndex(hashTable, string);
    if (index == INDEX_NOT_FOUND){
        printf("ERROR");
        return;
    }

    printf("%d %s", hashTable[index].quantity, hashTable[index].word);

    occurrence_t** aux = &(hashTable[index].first);
    do{
        printf(" %d", (*aux)->line);
        aux = &((*aux)->p_prox);
    }while((*aux) != NULL);

    printf("\n");
}

void printHashTable(hash* hashTable) {
    printf("\n======\n");
    for (int i = 0; i < SLOTS; i++) {
        printf("%3d |%s|\n", i, hashTable[i].word);
    }
    printf("======\n");
}