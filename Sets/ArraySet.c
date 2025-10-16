#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct{
    int set[MAX];
    int size;
} Set;

void initSet(Set *S){
    S->size = 0;
}

void displaySet(Set S){

    for(int i = 0; i < S.size; i++){
    printf("%d ", S.set[i]);
    }

    printf("\n");
}

void insertElem(Set* S, int data){

    // if set is not full
    if(S->size < MAX){
        int i;

        // if i < size and does not equal data (no duplicates)
        for(i = 0; i < S->size && S->set[i]!=data; i++) {}

        // if i == size, increment size then assign data
        if(i == S->size){
            S->set[S->size++] = data;
        }
    }
}

void deleteElem(Set* S, int data){

    // is set is greater than 0 (has members)
    if(S->size > 0){
        int i;

        // if i < size and does not equal data
        for(i = 0; i < S->size && S->set[i]!=data; i++){}

        // if i < size (data was found), decrement the size
        if(i < S->size){
            S->size--;

            // if new size > 0, replace elem[i] with last elem in the set
            if(S->size > 0){
                S->set[i] = S->set[S->size];
            }
        }
    }
}

int isMember(Set* S, int data){

    int i;
    for(i = 0; i < S->size && S->set[i]!=data; i++) {}
    return(i < S->size) ? 1 : 0;

}

void unionSet(Set A, Set B){

    Set U = A;
    int i;

    // add elements in B but not in A
    for(i = 0; i < B.size; i++){
        int j;

        // check if an elem in set B is already in set U
        for(j = 0; j < U.size && B.set[i]!=U.set[j]; j++){}

        // if not in set U, add set B[i] and increment set U size
        if(j == U.size){
            U.set[U.size++] = B.set[i];
        }
    }

    return U;
}

void instersectionSet(Set A, Set B){

    // declare and initialize set I
    Set I;
    initSet(&I);

    int i;

    for(i = 0; i < A.size; i++){
        int j;

        // check if an element in A is also in B
        for(j = 0; j < B.size && A.set[i]!=B.set[j]; j++){}

        // if an elem is in both sets, add to set I
        if(j != B.size){
            I.set[I.size++] = A.set[i];
        }
    }

    return I;

}

void differenceSet(Set A, Set B){ 

    // declare and initialize set D
    Set D;
    initSet(&D);

    int i;

    for(i =  0; i < A.size; i++){
        int j;

        // check if an element in A is also in B
        for(j = 0; j < B.size && A.set[i]!=B.set[j]; j++){}

        // if an elem in A is not in B, add element to D
        if(j == B.size){
            D.set[D.size++] = A.set[i];
        }
    }

    return D;
}

int main(){

    printf("Array Implementation of Sets");

    // declaration and initialization of sets 
    Set A, B;
    
    initSet(&A);
    initSet(&B);

    // inserting to sets

    // A
    insertElem(&A, 1);
    insertElem(&A, 4);
    insertElem(&A, 6);
    insertElem(&A, 8);
    insertElem(&A, 10);

    // B
    insertElem(&B, 6);
    insertElem(&B, 7);
    insertElem(&B, 9);
    insertElem(&B, 1);
    insertElem(&B, 3);


}
