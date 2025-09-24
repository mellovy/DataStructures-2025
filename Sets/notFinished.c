#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

// SETS

typedef  int Set[10];

void populateSet(Set S, int elems[], int numElems);
int* setUnion(Set A, Set B);
int* setIntersection(Set A, Set B);
int* setDifference(Set A, Set B);
int isSubset(Set A, Set B);

int main(){
	
	Set A = {};
	Set B = {};
	
	int elems[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int numElems = MAX;
	
	populateSet(A, elems, numElems);
	
}

void populateSet(Set S, int elems[], int numElems){
	
	int i;
	
	for(i = 0; i < numElems; i++){
		if(elems[i] >= 0 && elems[i < MAX]){
			S[i] = 1;
		}
	}
	
}

int* setUnion(Set A, Set B){
	
	int i;
	
	Set* C = malloc(sizeof(Set));
	if(C!=NULL){
		for(i = 0; i < MAX ; i++){
			(*C)[i] = A[i] | B[i];
		}
	}
	
	return *C;
	
}

int* setIntersection(Set A, Set B){
	
	int i;
	
	Set* C = malloc(sizeof(Set));
	if(C!=NULL){
		for(i = 0; i < MAX ; i++){
			(*C)[i] = A[i] & B[i];
		}
	}
	
	return *C;
	
}

int* setDifference(Set A, Set B){
	
	int i;
	
	Set* C = malloc(sizeof(Set));
	if(C!=NULL){
		for(i = 0; i < MAX ; i++){
			(*C)[i] = A[i] & (~B[i]);
		}
	}
	
	return *C;
}

int isSubset(Set A, Set B){
	
}
