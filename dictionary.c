#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100

// Define a struct for a key-value pair
typedef struct {
    char *key;
    char *value;
} KeyValuePair;

// Define a struct for a node in the linked list
typedef struct Node {
    KeyValuePair data;
    struct Node *next;
} Node;

// Hash table array
Node *hashTable[TABLE_SIZE];

// Hash function
unsigned int hash(const char *key) {
    unsigned long int hashval = 0;
    int i = 0;

    // Convert string to an integer
    while (hashval < ULONG_MAX && i < strlen(key)) {
        hashval = hashval << 8;
        hashval += key[i];
        i++;
    }

    return hashval % TABLE_SIZE;
}

// Initialize the hash table
void initHashTable() {
    int i;
    for (i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }
}

// Insert key-value pair into the hash table
void insert(const char *key, const char *value) {
    unsigned int slot = hash(key);

    // Create a new node
    Node *newNode = malloc(sizeof(Node));
    newNode->data.key = strdup(key);
    newNode->data.value = strdup(value);
    newNode->next = NULL;

    // Insert into the list at the proper slot
    if (hashTable[slot] == NULL) {
        hashTable[slot] = newNode;
    } else {
        Node *current = hashTable[slot];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Look up value by key in the hash table
char *lookup(const char *key) {
    unsigned int slot = hash(key);
    Node *current = hashTable[slot];

    while (current != NULL) {
        if (strcmp(current->data.key, key) == 0) {
            return current->data.value;
        }
        current = current->next;
    }

    return NULL; // Key not found
}

// Delete key-value pair from the hash table
void delete(const char *key) {
    unsigned int slot = hash(key);
    Node *current = hashTable[slot];
    Node *previous = NULL;

    while (current != NULL && strcmp(current->data.key, key) != 0) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        return;
    }

    if (previous == NULL) {
        hashTable[slot] = current->next;
    } else {
        previous->next = current->next;
    }

    free(current->data.key);
    free(current->data.value);
    free(current);
}

// Main function
int main() {
    initHashTable();

    // Insert key-value pairs into the dictionary
    insert("name", "Alice");
    insert("age", "30");
    insert("city", "Wonderland");

    // Look up values by key
    printf("name: %s\n", lookup("name"));
    printf("age: %s\n", lookup("age"));
    printf("city: %s\n", lookup("city"));

    // Delete a key-value pair
    delete("age");
    printf("age after deletion: %s\n", lookup("age"));

    return 0;
}

