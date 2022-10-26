#ifndef HASH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_H

#define SLOTS 509
#define MAX_WORD_LENGTH 20
#define MAX_TOTAL_LINES 10
#define EMPTY "-----"

typedef struct {
    char word[MAX_WORD_LENGTH + 1];
    int occurrences;
    int lines[MAX_TOTAL_LINES];
} hash;

hash* createHashTable(int);
int hashGenerator(char*);
void insertElement(hash*, char*);
int searchElementIndex(hash*, char*);

#endif