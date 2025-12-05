#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char String[32];

typedef struct {
	int book_id;
	String book_name;
} Book;

typedef struct node {
	Book book;
	struct node *left;
	struct node *right;
} *BST;

void init(BST *Tree){
    *Tree = NULL;
}

void insertNode(BST *root, Book newBook){
	// insert code here
    BST *trav;

    for(trav = root; *trav!=NULL && (*trav)->book.book_id != newBook.book_id; trav = newBook.book_id < (*trav)->book.book_id ? &(*trav)->left : &(*trav)->right){}

    if(*trav == NULL){
        BST newNode = malloc(sizeof(struct node));
        newNode->book = newBook;
        newNode->left = NULL;
        newNode->right = NULL;

        *trav = newNode;

        printf("Book inserted successfully into Tree!\n");
    }else{
        printf("Book was not inserted.\n");
    }
}

void display(BST root){
    if(root!=NULL){
        display(root->left);
        printf("%s\n", root->book.book_name);
        display(root->right);
    }
}


int main(){

    BST Tree;

    init(&Tree);

    Book newBook = {1, "Book One"};
    Book newBook2 = {2, "Book Two"};
    Book newBook3 = {3, "Book Three"};

    insertNode(&Tree, newBook);
    insertNode(&Tree, newBook2);
    insertNode(&Tree, newBook3);

    printf("\nBook list in order: \n");
    display(Tree);



}