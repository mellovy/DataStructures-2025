#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct node{
    int data;
    struct node* next;
}Node;

typedef struct {
    Node *elems[MAX];
} Dictionary;

int hash(int data){
    return data % MAX;
}

void createDictionary(Dictionary *table){
    for(int i = 0; i < MAX; i++){
        table->elems[i] = NULL;
    }
}

void insertUniqueData(Dictionary *table, int data){
    Node **trav;
    int key = hash(data);

    Node*newNode = malloc(sizeof (Node));
    newNode->data = data;

    for(trav = &table->elems[key]; *trav!=NULL && (*trav)->data!=data; trav = &(*trav)->next){}

    if(*trav == NULL){
      newNode->next = table->elems[key];
      table->elems[key] = newNode;  
      printf("Inserted %d into the dictionary.\n", data);
    }else{
        printf("%d is already in dictionary.\n", data);
    }
}

void displayDictionary(Dictionary table){
    for(int i = 0; i < MAX; i++){
        Node *curr = table.elems[i];
        int count = 0;
        if(curr != NULL){
            printf("Elem [%d]: ", i);
            while(curr != NULL){
                if(count > 0) printf(" -> ");
                printf("%d", curr->data);
                curr = curr->next;
                count++;
            }
            printf("\n");
        }
    }
}

int findMember(Dictionary *table, int num){
    Node** trav;
    int key = hash(num);

    for(trav = &table->elems[key]; *trav!=NULL && (*trav)->data !=num; trav = &(*trav)->next){}
    return(*trav!=NULL) ? 1 : 0;
}

int deleteMember(Dictionary *table, int num){
    Node *temp, **trav;
    int key = hash(num);

    for(trav = &table->elems[key]; *trav!=NULL && (*trav)->data !=num; trav = &(*trav)->next){}
    if(*trav!=NULL){
        temp = *trav;
        *trav = temp->next;
        free(temp);
        printf("Deleted %d from dictionary.\n", num);
    }else{
        printf("Cannot find %d in dictionary?.\n", num);
    }
}

int main(){

    Dictionary table;

    createDictionary(&table);

    insertUniqueData(&table, 12);
    insertUniqueData(&table, 7);
    insertUniqueData(&table, 22);
    insertUniqueData(&table, 17);
    insertUniqueData(&table, 5);

    displayDictionary(table);

    int numtofind = 17;
    int find = findMember(&table, numtofind);
    if(find){ printf("Found %d\n", numtofind);} else { printf("Did not find %d\n", numtofind);}

    deleteMember(&table, 7);

    displayDictionary(table);

    insertUniqueData(&table, 32);
    displayDictionary(table);

}

