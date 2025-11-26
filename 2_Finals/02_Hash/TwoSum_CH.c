#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX 0XA // max is 10

// You are asked to solve the classic Two Sum problem using CLOSED HASHING.
// Given an array of unique integers and a target sum, find the indices of the two elements whose values add up to the target.

// Requirements:
// - The solution must run in linear time O(n).
// - You must use the provided Dictionary data type for inserting and retrieving elements.
// - If a valid pair is found, return their indices. If no pair exists, return NULL and set the result size to 0.

// CONSTRAINTS:
// - There is ALWAYS two numbers that add up to the target sum.
// - Numbers in the array are UNIQUE.
// - Only 2 numbers add up to the target sum
// - Indices must be arranged in ascending order

/*********************************/
/*    USER-DEFINED DATA TYPES    */
/*********************************/
typedef struct {
    int key;
    int value;
} KeyValuePair;

typedef KeyValuePair Dictionary[MAX];

typedef enum {
    EMPTY = -999999,
    DELETED = -1000000
} DictStatus;

/*********************************/
/*       HELPER FUNCTIONS        */
/*********************************/
void initDict(Dictionary D);
int hash(int key);

/*********************************/
/*          YOUR TASKS           */
/*********************************/
int* twoSum(int sum, int arr[], int size, int *retSize);
void insert(Dictionary D, int key, int value);
int getValue(Dictionary D, int key);

int main() {
    int size;
    printf("Enter size: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter elements in the array (unique): ");
    for (int i = 0; i < size; i++) scanf("%d", arr + i);

    int sum;
    printf("Enter sum: ");
    scanf("%d", &sum);

    int retSize;
    int *sumIndices = twoSum(sum, arr, size, &retSize);
    printf("Indices of elements adding up to %d are: ", sum);

    for (int i = 0; i < retSize; i++) printf("%d%s", sumIndices[i], (i + 1 == retSize) ? "" : " & ");

    return 0;
}

/*********************************/
/*       HELPER FUNCTIONS        */
/*********************************/
void initDict(Dictionary D) {
    for(int i = 0; i < MAX; i++) {
        D[i].key = EMPTY;
    }
}

int hash(int key) {
    return abs(key) % MAX;
}


/*********************************/
/*          YOUR TASKS           */
/*********************************/


// Function that returns indices of 
// two numbers that add up to `sum`
int* twoSum(int sum, int arr[], int size, int *retSize) {
    Dictionary d;
    initDict(d);
    // Implementation here...

    for(int i = 0; i < size; i++){
        int complement = sum - arr[i];
        int foundI = getValue(d, complement);
        if(foundI!=-1){
            int*result = malloc(2*sizeof(int));
            result[0] = foundI < i ? foundI : i;
            result[1] = foundI > i ? foundI : 1;
            *retSize = 2;
            return result;
        }
        insert(d, arr[i], i);
    }

    *retSize = 0;
    return NULL;
}

// Function that inserts a key-value
// pair into the Dictionary
void insert(Dictionary D, int key, int value) {
    // Implementation here...
    int index = hash(key);
    while(D[index].key!=EMPTY && D[index].key!=DELETED){
        index = (index + 1) % MAX;
    }
    D[index].key = key;
    D[index].value = value;

}


// Function that returns the value based on the passed key
// Function returns -1 if key is not in the dictionary
int getValue(Dictionary D, int key) {
    // Implementation here...
    // search!!!

    int index = hash(key);
    while(D[index].key!=EMPTY && D[index].key!=key){
        index = (index + 1) % MAX;
    }
    return (D[index].key!=EMPTY) ? D[index].value : -1;
}