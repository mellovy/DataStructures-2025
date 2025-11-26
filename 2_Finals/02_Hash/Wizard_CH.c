#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 7
#define EMPTY -1

int hashTable[TABLE_SIZE];

int hashFunction(int key){ return key % TABLE_SIZE;}

void insertSpell(int key){
    int index = hashFunction(key);

    while(hashTable[index]!=EMPTY){
        index = (index + 1) % TABLE_SIZE;
    }

    hashTable[index] = key;
}

int searchSpell(int key){
    int index = hashFunction(key);

    while(hashTable[index]!=EMPTY && hashTable[index]!=key){
        index = (index + 1) % TABLE_SIZE; 
    }

    return(hashTable[index]!=EMPTY) ? 1 : -1;
}

void displaySpells(){
    for(int i = 0; i < TABLE_SIZE; i++){
        printf("[%d] = %d\n", i, hashTable[i]);
    }
}

int main() {
    // Initialize table
    for (int i = 0; i < TABLE_SIZE; i++) hashTable[i] = EMPTY;

    insertSpell(13);   // goes to 13 % 7 = 6
    insertSpell(20);   // 20 % 7 = 6 → collision! → probe to 0
    insertSpell(27);   // 27 % 7 = 6 → collision → probe to 1
    insertSpell(5);    // 5 % 7 = 5 → goes directly

    printf("Current Spell Table:\n");
    displaySpells();

    printf("\nSearching for spell 20... %s\n",
           searchSpell(20) != -1 ? "Found!" : "Not Found!");

    printf("Searching for spell 10... %s\n",
           searchSpell(10) != -1 ? "Found!" : "Not Found!");

    return 0;
}
