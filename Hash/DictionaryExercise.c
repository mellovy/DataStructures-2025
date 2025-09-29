#include <stdio.h>
#include <string.h>

typedef int SET[9];

int hashOne(int num){
	return (num/100)%10;
}

int hashTwo(int num){
	
	int digit = 0;
	int sum = 0;
	
	while(num>0){
		digit = num%10;
		sum += digit;
		num /= 10;
	}
	
	return sum%19;
}

int hashThree(char* name){
	
	int i;
	int sum = 0;
	int val;
	
	for(i=0; i<strlen(name);i++){
		val = (int)name[i];
		sum += val;
	}
	
	return sum%49;
	
}

int main(void){
	
	SET S = {0, 13, 20, 28, 30, 33, 45, 48, 108};
	int i;
	int ascii;
	char str[20] = "Name";
	
	
	printf("Prob1\n");
	for(i = 0; i<9; i++){
		printf("%d ", hashOne(S[i]));
	}
	
	printf("\nProb2\n");
	for(i = 0; i<9; i++){
		printf("%d ", hashTwo(S[i]));
	}
	
	printf("\nProb3\n");
	ascii = hashThree(str);
	printf("%d", ascii);
	
	
}
