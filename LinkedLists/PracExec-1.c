#include <stdio.h>
#include <stdbool.h>

#define MAX 100

typedef struct{
	char element[MAX];
	int count;
}charList;

bool findElem(charList L, char X){
	int i;
	for(i=0; i<L.count && L.element[i]!=X; i++){}
	return (i<L.count)? true:false;
}

int main(){
	
	charList L;
	L.count = 3;
	L.element[0] = 'U';
	L.element[1] = 'S';
	L.element[2] = 'C';
	
	
	char X = 'X';
	bool result;
	
	result = findElem(L, X);
}
