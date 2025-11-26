#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}Tree;

Tree*newNode(int value){
    Tree* t = malloc(sizeof(Tree));
    t->data = value;
    t->left = NULL;
    t->right=NULL;
    return t;
}

void preorder(Tree* T){
    if( T == NULL) return;

    printf("%d", T->data); // root
    preorder(T->left); // left
    preorder(T->right); // right

}

void inorder(Tree* T){
    if( T == NULL) return;

    inorder(T->left); // left
    printf("%d", T->data); // root
    inorder(T->right); // right

}

void postorder(Tree* T){
    if( T == NULL) return;

    postorder(T->left); // left
    postorder(T->right); // right
    printf("%d", T->data); // root

}

int main(){
    Tree*root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);

    root->left->left = newNode(4);
    root->left->right = newNode(5);

    root->right->left = newNode(6);
    root->right->right = newNode(7);

    printf("PREORDER: ");
    preorder(root);

    printf("\nINORDER: ");
    inorder(root);

    printf("\nPOSTORDER: ");
    postorder(root);
}