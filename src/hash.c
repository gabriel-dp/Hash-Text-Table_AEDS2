#include "hash.h"

hash* createHashTable(int length) {
    hash* newHashTable = (hash*)(malloc(length * sizeof(hash)));
    for (int i = 0; i < length; i++) {
        strcpy(newHashTable[i].word, EMPTY);
    }
    return newHashTable;
}

int hashGenerator(char* string) {
    unsigned int key;
    for (int i = 0; i < strlen(string); i++) {
        key += ((i + 1) * string[i]);
    }
    int index = key % SLOTS;
    return index;
}