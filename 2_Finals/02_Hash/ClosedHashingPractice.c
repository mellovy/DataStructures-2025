#include <stdio.h>

#define TABLE_SIZE 10
#define EMPTY -1

int hashTable[TABLE_SIZE];

// Function prototypes
void initializeTable();
int hashFunction(int key);
void insert(int key);
int search(int key);
void displayTable();

int main() {
    int choice, key;

    initializeTable();

    do {
        printf("\n--- Student ID Hash Table ---\n");
        printf("1. Insert ID\n");
        printf("2. Search ID\n");
        printf("3. Display Table\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter student ID to insert: ");
                scanf("%d", &key);
                insert(key);
                break;
            case 2:
                printf("Enter student ID to search: ");
                scanf("%d", &key);
                if (search(key) != -1)
                    printf("ID %d found at index %d\n", key, search(key));
                else
                    printf("ID %d not found.\n", key);
                break;
            case 3:
                displayTable();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 4);

    return 0;
}

void initializeTable() {
    // TODO: initialize all slots to EMPTY
    for(int i = 0; i < TABLE_SIZE; i++){
        hashTable[i] = EMPTY;
    }
}

int hash(int key) {
    // TODO: return hash value
    return key % TABLE_SIZE;
}

void insert(int key) {
    // TODO: use linear probing to insert key into table
    int index = hash(key);
    while(hashTable[index]!=EMPTY){
        index = (index+1) % TABLE_SIZE;
    }

    hashTable[index] = key;
}

int search(int key) {
    // TODO: search using same probing sequence
    int index = hash(key);
    while(hashTable[index]!=EMPTY && hashTable[index]!=key){
        index = (index + 1) % TABLE_SIZE;
    }
    return(hashTable[index]!=EMPTY) ? index : -1;
}

void displayTable() {
    // TODO: print all table indexes and their values
    for(int i = 0; i < TABLE_SIZE; i++){
        printf("Index %d : %d\n", i, hashTable[i]);
    }
}