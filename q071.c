/*
Day 71: Hash Table Using Quadratic Probing

Problem:
Implement a hash table using quadratic probing with formula:

h(k, i) = (h(k) + i*i) % m

Input:
- Table size
- Number of operations
- Commands: INSERT key / SEARCH key

Output:
- Result of SEARCH operations
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initializeTable(int table[], int size) {
    for (int i = 0; i < size; i++) {
        table[i] = -1;
    }
}

void insert(int table[], int size, int key) {
    int h = key % size;
    int i = 0;

    while (i < size) {
        int index = (h + i * i) % size;

        if (table[index] == -1 || table[index] == key) {
            table[index] = key;
            return;
        }
        i++;
    }
}

int search(int table[], int size, int key) {
    int h = key % size;

    for (int i = 0; i < size; i++) {
        int index = (h + i * i) % size;

        if (table[index] == key) {
            return 1;
        }

        if (table[index] == -1) {
            return 0;
        }
    }

    return 0;
}

int main() {
    int size;
    int operations;

    printf("Enter hash table size: ");
    scanf("%d", &size);

    int* table = (int*)malloc(size * sizeof(int));
    initializeTable(table, size);

    printf("Enter number of operations: ");
    scanf("%d", &operations);

    printf("Enter %d operations (INSERT key / SEARCH key):\n", operations);
    for (int i = 0; i < operations; i++) {
        char command[20];
        int key;

        scanf("%s %d", command, &key);

        if (strcmp(command, "INSERT") == 0) {
            insert(table, size, key);
        } else if (strcmp(command, "SEARCH") == 0) {
            if (search(table, size, key)) {
                printf("FOUND\n");
            } else {
                printf("NOT FOUND\n");
            }
        }
    }

    free(table);
    return 0;
}
