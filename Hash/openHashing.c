#include <stdio.h>
#define MAX 10

typedef int Dictionary[MAX];

int hash(int key){
    return key % MAX;
}

int main(){
    
    Dictionary D = {0, 20, 30, 13, 33, 45, 28, 48, 108};

    for(int i = 0; i < MAX - 1; i++){
        printf("Where is %d in the dictionary?\n", D[i]);
        printf("Index: %d\n\n", hash(D[i]));
    }
    
}
