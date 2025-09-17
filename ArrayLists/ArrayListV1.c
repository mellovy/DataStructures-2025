#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct{
	int elems[MAX];
	int count;
}List;

void initListV1(List*);
List initListV2(void);

void insertLast(List*, int);
void insertFirst(List*, int);
void insertSorted(List*, int);

void deleteLast(List*);
void deleteFirst(List*);
void deleteElem(List*, int);

int findElem(List, int);

void displayList(List);

int main(void){
	List listNum;
	//initListV2();
	initListV1(&listNum);
	int i;
	
    insertSorted(&listNum, 16);
    insertSorted(&listNum, 12);
    insertSorted(&listNum, 18);

    deleteElem(&listNum, 18);
    
    displayList(listNum);
	
	return 0;
}

void initListV1(List* L)
{
	L->count = 0;
}

List initListV2(void)
{
	List temp;
	temp.count = 0;
	return temp;
}

void insertFirst(List* L, int data){
//here
    if(L->count > 0){
        int i = 0;

        for(i = L->count ; i > 0; i--){
            L->elems[i] = L->elems[i-1];
        }  

        L->elems[0] = data;
        L->count++;

    }else{
        L->elems[0] = data;
        L->count++;
    }
}

void insertLast(List* L, int data)
{
	if(L->count != MAX){
		L->elems[L->count] = data;
		L->count++;
	}
}

void insertSorted(List* L, int data){
//here
    int i = L->count - 1;
    while(i >= 0 && L->elems[i] > data){
        L->elems[i+1] = L->elems[i];
        i--;
    }

    L->elems[i+1] = data;
    L->count++;
}

void deleteFirst(List* L){
//here
    if(L->count > 0){
        int i = 0;

        for(i = 0; i < L->count-1; i++){
            L->elems[i] = L->elems[i+1];
        }
        L->count--;
    }else{
        L->count--;
    }
}

void deleteLast(List* L)
{
	if(L->count > 0){
		L->count--;		
	}
}

void deleteElem(List* L, int data){
//here
    int i=0;
    for(i = 0; i<L->count; i++){
        if(L->elems[i] == data){
            for(int j = i; j < L->count - 1; j++){
                L->elems[j] = L->elems[j+1];
            }
            L->count--;
        }
    }
}

int findElem(List L, int data)
{
	int i;
	for(i = 0; i < L.count && L.elems[i] != data; i++){}
	return (i < L.count) ? i : -1;
}

void displayList(List L)
{
	int i;
	
	for(i = 0; i < L.count; i++){
		printf("L[%d]: %d\n", i, L.elems[i]);
	}
	
}
