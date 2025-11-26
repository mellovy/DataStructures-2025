#include <stdio.h>
#include <stdbool.h>

typedef struct node{
	char elem;
	struct node *link;
}*charList;

charList createNode(char elem){
	charList newNode = (charList) malloc(sizeof(struct node));
	newNode->elem = elem;
	newNode->link = NULL;
	return newNode;
}

bool findElem(charList list, char X){
	while (list != NULL) {
        if (list->elem == X) {
            return true;
        }
        list = list->link;
    }
    return false;
}

int main() {
    // Test case a) List is empty
    charList list1 = NULL;
    char X = 'A';
    printf("Test case a) Empty list, find '%c': %s\n", X, findElem(list1, X) ? "true" : "false");

    // Test case b) List is not empty, X is in the list
    charList list2 = createNode('A');
    list2->link = createNode('B');
    list2->link->link = createNode('C');
    X = 'B';
    printf("Test case b) List has 'A', 'B', 'C', find '%c': %s\n", X, findElem(list2, X) ? "true" : "false");

    // Test case c) List is not empty, X is not in the list
    X = 'D';
    printf("Test case c) List has 'A', 'B', 'C', find '%c': %s\n", X, findElem(list2, X) ? "true" : "false");

    // Free allocated memory
    while (list2 != NULL) {
        charList temp = list2;
        list2 = list2->link;
        free(temp);
    }

    return 0;
}
