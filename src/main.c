#include "hash.h"

void main() {
    hash* hashTable = createHashTable(SLOTS);
    insertElement(hashTable, "gabriel", 5, SLOTS);
    insertElement(hashTable, "davi", 7, SLOTS);
    printHashTable(hashTable);
}