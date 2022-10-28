#ifndef HASH_H

#define HASH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SLOTS 509
#define MAX_WORD_LENGTH 20

typedef struct occurrence {
    int line;
    struct occurrence* p_prox;
} occurrence_t;

typedef struct {
    char word[MAX_WORD_LENGTH + 1];
    int quantity;
    occurrence_t* first;
} hash;

hash* createHashTable();
void insertElement(hash*, char*, int);
void printOccurrences(hash*, char*);

#endif