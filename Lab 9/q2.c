#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

struct Node {
    int key;
    struct Node* next;
};

struct HashTable {
    struct Node* table[TABLE_SIZE];
};

void initializeHashTable(struct HashTable* hashtable) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashtable->table[i] = NULL;
    }
}

int calculateHash(int key) {
    return key % TABLE_SIZE;
}

void insertKey(struct HashTable* hashtable, int key) {
    int index = calculateHash(key);
    
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->next = NULL;
    
    // Insert the new node into the hash table
    if (hashtable->table[index] == NULL) {
        hashtable->table[index] = newNode;
    } else {
        struct Node* curr = hashtable->table[index];
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
}

struct Node* searchKey(struct HashTable* hashtable, int key, int* comparisons) {
    int index = calculateHash(key);

    struct Node* curr = hashtable->table[index];
    while (curr != NULL) {
        (*comparisons)++;
        if (curr->key == key) {
            return curr;
        }
        curr = curr->next;
    }
    
    return NULL; 
}

void deleteKey(struct HashTable* hashtable, int key) {
    int index = calculateHash(key);

    struct Node* curr = hashtable->table[index];
    struct Node* prev = NULL;
    
    while (curr != NULL) {
        if (curr->key == key) {
            if (prev == NULL) {
                hashtable->table[index] = curr->next;
            } else {
                prev->next = curr->next;
            }
            free(curr);
            printf("Key %d deleted from the hash table.\n", key);
            return;
        }
        
        prev = curr;
        curr = curr->next;
    }
    
    printf("Key %d not found in the hash table.\n", key);
}

void displayHashTable(struct HashTable* hashtable) {
    printf("Hash Table Contents:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Index %d: ", i);
        
        struct Node* curr = hashtable->table[i];
        while (curr != NULL) {
            printf("%d ", curr->key);
            curr = curr->next;
        }
        
        printf("\n");
    }
}

int main() {
    struct HashTable hashtable;
    initializeHashTable(&hashtable);
    
    int choice, key;
    
    do {
        printf("\n--- Menu ---\n");
        printf("1. Insert Key\n");
        printf("2. Search Key\n");
        printf("3. Delete Key\n");
        printf("4. Display Hash Table\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the key to insert: ");
                scanf("%d", &key);
                insertKey(&hashtable, key);
                break;
                
            case 2:
                printf("Enter the key to search: ");
                scanf("%d", &key);
                int comparisons = 0;
                struct Node* result = searchKey(&hashtable, key, &comparisons);
                if (result != NULL) {
                    printf("Key %d found in the hash table.\n", key);
                } else {
                    printf("Key %d not found in the hash table.\n", key);
                }
                printf("Number of key comparisons made: %d\n", comparisons);
                break;
                
            case 3:
                printf("Enter the key to delete: ");
                scanf("%d", &key);
                deleteKey(&hashtable, key);
                break;
                
            case 4:
                displayHashTable(&hashtable);
                break;
                
            case 5:
                printf("Exiting...\n");
                break;
                
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
    
    return 0;
}
