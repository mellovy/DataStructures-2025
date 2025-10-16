#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int data;
    struct node* next;
} node, *Set;

void initSet(Set *S){
   S = NULL;
}

void displaySet(Set S){
    for(Set curr = S; curr!=NULL; curr = curr->next){
        printf("%d ", curr->data);
    }
    printf("\n");
}

void insertElem(Set* S, int data){

    Set *trav = S;

    for(; *trav!=NULL && (*trav)->data!=data; trav = &(*trav)->next) {}

    if(*trav == NULL){
        Set temp = (Set)malloc(sizeof(node));
        if(temp!=NULL){
            temp->data = data;
            temp->next = NULL;
            *trav = temp;
        }
    }
}

void deleteElem(Set* S, int data){
    Set temp, *trav;

    for(trav = &S; *trav!=NULL && (*trav)->data!=data; trav = &(*trav)->next){}
    if(*trav!=NULL){
        temp = *trav;
        *trav = temp->next;
        free(temp);
    }

}

int isMember(Set S, int data){
    Set trav;
    for(trav = S; trav!=NULL && trav->data!=data; trav = trav->next){}
    return trav == NULL ? 0 : 1;
}

Set unionSet(Set A, Set B){
   
    Set U = NULL;
    Set* trav = &U;

    for(Set curr = A; curr!=NULL; curr = curr->next){
        Set temp = (Set)malloc(sizeof(node));

        if(temp!=NULL){
            temp->data = curr->data;
            *trav = temp;
            trav = &(*trav)->next;
        }
    }

    *trav = NULL;

    for(Set curr = B; curr!=NULL; curr = curr->next){
        insertElem(&U, curr->data);
    }

    return U;
}

Set instersectionSet(Set A, Set B){
    
    Set I = NULL;

    for(Set currA = A; currA!=NULL; currA = currA->next){
        Set currB;
        for(currB = B; currB!=NULL && currA->data!=currB->data; currB = currB->next){}
        
        if(currB!=NULL){
            Set temp = malloc(sizeof(node));
            if(temp!=NULL){
                temp->data = currA->data;
                temp->next = I;
                I = temp;
            }
        }
    }

    return I;
}

void differenceSet(Set A, Set B){ 
    
    Set D = NULL;

    for(Set currA = A; currA!=NULL; currA = currA->next){
        Set currB;
        for(currB = B; currB!=NULL && currA->data!=currB->data; currB = currB->next){}

        if(currB == NULL){
            Set temp = malloc(sizeof(node));

            if(temp!=NULL){
                temp->data = currA->data;
                temp->next = D;
                D = temp;
            }
        }
    }

    return D;
}

int main(){

    printf("Linked List Implementation of Sets");

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
