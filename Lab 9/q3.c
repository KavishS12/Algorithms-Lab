#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 100

int hashTable[TABLE_SIZE];

void insert(int key) {
    int index = key % TABLE_SIZE;

    while (hashTable[index] != 0) {
        index = (index + 1) % TABLE_SIZE;
    }
    hashTable[index] = key;
}

int search(int key, int* comparisons) {
    int index = key % TABLE_SIZE;
    *comparisons = 1;

    while (hashTable[index] != 0) {
        if (hashTable[index] == key) {
            return 1;
        }
        index = (index + 1) % TABLE_SIZE;
        (*comparisons)++;
    }

    return 0;
}

int main() {
    int n_keys = 4;

    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = 0;
    }

    for (int i = 0; i < n_keys; i++) {
        insert(rand() % n_keys);
    }

    int comparisons_success, comparisons_fail;
    comparisons_success = comparisons_fail = 0;

    for (int i = 0; i < n_keys; i++) {
        int key_to_search = rand() % n_keys;
        if (search(key_to_search, &comparisons_success)) {
        } 
        else {
            comparisons_fail += comparisons_success;
        }
    }

    printf("Number of keys: %d\n", n_keys);
    printf("Average number of comparisons in successful search: %d\n", comparisons_success / n_keys);
    printf("Average number of comparisons in unsuccessful search: %d\n", comparisons_fail / n_keys);

    return 0;
}
