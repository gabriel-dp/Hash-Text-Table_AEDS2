#include "hash.h"

void main() {
    hash* hashTable = createHashTable(SLOTS);
    insertElement(hashTable, "gabriel", 5);
    insertElement(hashTable, "davi", 7);
    insertElement(hashTable, "gabriel", 3);
    insertElement(hashTable, "davi", 2);
    insertElement(hashTable, "gabriel", 1);
    insertElement(hashTable, "davi", 4);
    printOccurrences(hashTable, "davi");
    printOccurrences(hashTable, "gabriel");
}