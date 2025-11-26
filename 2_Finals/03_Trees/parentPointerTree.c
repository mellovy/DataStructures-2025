#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef enum{
    NO_PARENT = -1,
    EMPTY = -2
}ParentStatus;

typedef struct{
    int data;
    int parent;
} Node;

typedef Node Tree[MAX];

void initTree(Tree T);
void insert(Tree T, int data, int idx, int pdx);
void printFromRoot(Tree T, int idx);

int main(){
    Tree T;

    initTree(T);

    insert(T, 100, MAX/2, NO_PARENT);

    for(int i = MAX/2 -1; i >=0; i--){
        insert(T, i,i, i+1);
    }

    for(int i = MAX/2 + 1; i < MAX; i++){
        insert(T, i, i, i-1);
    }

    int node = 0;
    printf("From root up to node %d: ", node);
    printFromRoot(T, node);
}

// set every node's parent to empty
void initTree(Tree T){
    for(int i = 0; i < MAX; i++){
        T[i].parent = EMPTY;
    }
}

// manually place a node at index and specify the parent index
void insert(Tree T, int data, int idx, int pdx){
    T[idx].data = data;
    T[idx].parent = pdx;
}

void printFromRoot(Tree T, int idx){
    if(T[idx].parent!=NO_PARENT && T[idx].parent!=EMPTY){
        printFromRoot(T, T[idx].parent);
        printf("%d ", T[idx].data);
    }
}
