#include <stdio.h>
#include <stdlib.h>
#define N 17

void addNode(int number);

int data[N] = {34, 25, 58, 19, 73, 33, 15, 26, 55, 9, 76, 74, 20, 78, 48, 89, 77};

struct Node {
    int value;
    struct Node * left;
    struct Node * right;
};

int main() {
    for(int i=0; i<N; i++) {
        addNode( data[i] );
    }
}

void addNode( int number ) {
    struct Node *rootPtr;

    struct Node *current;
    struct Node *parent;
    struct Node *newnode;

    newnode = malloc( sizeof (struct Node));
    newnode->value = number;
    newnode->left = NULL;
    newnode->right = NULL;

    if (rootPtr == NULL) {
        rootPtr = newnode;
        return;
    }

    current = rootPtr;
    while ( current != NULL ) {
        parent = current;
        if ( number < current->value) {
            current = current->left;
        }
        else
            current = current ->right;
    }

    if ( number < parent->value) {
        parent->left = newnode;
    }
    else
        parent->right = newnode;
}
