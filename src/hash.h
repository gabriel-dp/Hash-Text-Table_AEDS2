#ifndef HASH_H
#define HASH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SLOTS 512
#define MAX_CHAR_PER_LINE 80
#define MAX_CHAR_PER_WORD 20
#define DELIMITERS " ,.;:!?()"

typedef struct occurrence {
    int line;
    struct occurrence* p_prox;
} occurrence_t;

typedef struct {
    char word[MAX_CHAR_PER_WORD + 1];
    int quantity;
    occurrence_t* first;
} hash;

hash* createHashTable();
void insertElement(hash*, char*, int, int*);
void printOccurrences(hash*, char*);

#endif