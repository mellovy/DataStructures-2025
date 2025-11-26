#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
} *Tree;

void initTree(Tree *T);

void insertTree(Tree *T, int data);
void delete(Tree *T, int data);
int search(Tree T, int data);

void display(Tree T);

int main(){

    Tree T;
    initTree(&T);

    insertTree(&T, 6);
    insertTree(&T, 8);
    insertTree(&T, 4);
    insertTree(&T, 1);
    insertTree(&T, 9);
    insertTree(&T, 7);
    insertTree(&T, 5);

    display(T);
    
    int found = search(T, 1);
    printf("SEARCH: %d\n", found);

    delete(&T, 4);
    display(T);

}

void initTree(Tree *T){
    *T = NULL;
}

void display(Tree T){  
    if(T != NULL){
        //in order
        display(T->left);
        printf("%d ", T->data);
        display(T->right);
    }
}

int search(Tree T, int data){
    while (T != NULL && T->data != data) {
        T = (data < T->data) ? T->left : T->right;
    }
    return (T != NULL) ? T->data : 0; 
}


void insertTree(Tree *T, int data){ 
    Tree *trav;

    Tree temp = (Tree)malloc(sizeof(struct node));
    if(temp != NULL){
        temp->data = data;
        temp->left = NULL;
        temp->right = NULL;

        // always data < (*trav->data) 

        for(trav = T; *trav !=NULL && (*trav)->data != data; 
            trav = (data < (*trav)->data) ? &(*trav)->left : &(*trav)->right){}

        if(*trav == NULL){
            *trav = temp;
        }
    }
}

void delete(Tree *T, int data){
    Tree temp;
    Tree *trav;
    trav = T;

    for(; *trav != NULL && (*trav)->data != data; 
        trav = (data < (*trav)->data) ? &(*trav)->left : &(*trav)->right);
        
    if(*trav != NULL){

        // RIGHT CHILD SUBTREE LOOKING FOR MINIMUM ----------------

        // if((*trav)->right == NULL) {             // if there is no right child
        //     temp = *trav;
        //     *trav = temp->left; 
        // } else {                                 // else, if there is
        //     Tree *successor = &(*trav)->right;   // successor is the right child now 

        //     while((*successor)->left != NULL) {  // traverse to the leaf on the left
        //         successor = &(*successor)->left;
        //     }

        //     (*trav)->data = (*successor)->data;  // trav is now the leaf
        //     temp = (*successor);                 // temp will now point to successor
        //     *successor = temp->right; //         // successor will now be temp->right (NULL)
        // }
        
        // LEFT CHILD SUBTREE LOOKING FOR MAXIMUM ----------------

        // if((*trav)->left == NULL) {
        //     temp = *trav;
        //     *trav = temp->right; 
        // } else {
        //     Tree *successor = &(*trav)->left; 

        //     while((*successor)->right != NULL) { 
        //         successor = &(*successor)->right;
        //     }

        //     (*trav)->data = (*successor)->data; 
        //     temp = (*successor);
        //     *successor = temp->left; // 
        // }

        free(temp);

    }
}