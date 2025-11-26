#include <stdio.h>
#define MAX 10

typedef unsigned char SET;

void displaySetBits(SET S){
	int i;
	SET mask = 1 << (sizeof(SET)*8-1);
	for(i = 1; mask > 0; mask >>= 1, i++){
		printf("%u", (S&mask)!=0) ? 1 : 0;
		if(i%8==0){
			printf(" ");
		}
	}
}

void insertFront(SET *S){
	SET mask = 1 << (sizeof(SET)*8-1);
	*S = (*S)| mask;
}

void insertLast(SET *S){
	SET mask = 1;
	*S = (*S)| mask;
}

void insertAtPos(SET* S, int pos){
	SET mask = 1 << (pos - 1);
	*S = (*S) | mask;
}

int main(void){
	

	
}
