#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct node {
	int data;
	struct node* next;
} *SET;

typedef SET Dictionary[MAX];

void initDict(Dictionary D);
void insert(Dictionary D, int data);
void display(Dictionary D);

int main(){
	Dictionary D;
	
	initDict(D);
	
	insert(D, 0);
	insert(D, 20);
	insert(D, 30);
	insert(D, 13);
	insert(D, 33);
	insert(D, 45);
	insert(D, 28);
	insert(D, 48);
	insert(D, 108);
	
	display(D);
	
	return 0;
}

void initDict(Dictionary D){
	int i = 0;
	
	for(i = 0; i < MAX; i++){
		D[i] = NULL;
	}
}

void insert(Dictionary D, int data){
	SET newNode = (SET)malloc(sizeof(struct node));
	int temp = data % 10;
	
	if(newNode != NULL){
		newNode->data = data;
		newNode->next = D[temp];
		D[temp] = newNode;
	}
}

void display(Dictionary D){
	int i;
	SET trav;
	
	for(i = 0; i < MAX; i++){
		printf("Index [%d]: ", i);
		
		for(trav = D[i]; trav != NULL; trav = trav->next){
			printf("%d -> ", trav->data);
		}
		
		printf("NULL\n");
	}
}
