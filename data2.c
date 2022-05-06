#include <stdio.h>
#include <stdlib.h>
#define N 17

struct Node {
    int value;
    struct Node * left;
    struct Node * right;
};

void addNode(int number);
void avlevel(int level);
void linearity(struct Node * root);
void btr(struct Node * root);
void push(int);
int pop();

int data[N] = {34, 25, 58, 19, 73, 33, 15, 26, 55, 9, 76, 74, 20, 78, 48, 89, 77};

struct Node *rootPtr;
struct Node * Q[100];
int f=-1;
int l=-1;
int travel[N];

int main() {
    //TASK 1
    for(int i=0; i<N; i++) {
        addNode( data[i] );
    }

    //TASK 2
    int level;
    printf("Enter a tree level(minimum 0): ");
    scanf("%d", &level);

    btr(rootPtr);
    avlevel(level);

    //TASK 3
    linearity(rootPtr);

}

void addNode( int number ) {
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


void btr( struct Node * root) {
    if (root == NULL) {
        return;
    }



    push(root);

    int count=0;
    while (f!=-1) {
        struct Node * v = pop();
        printf("%d ", v->value);
        travel[count] = v->value;

        if (v->left != NULL) {
            push(v->left);
        }

        if (v->right != NULL) {
            push(v->right);
        }

        count++;
    }
}


void avlevel( int level ) {
    int total=0;
    int div;

    printf("\n Data items at that level are = ");

    switch (level) {

    case 0:
        total += travel[0];
        printf("%d ", travel[0]);
        div=1;
        break;

    case 1:
        for (int i=1; i<=2; i++) {
            total += travel[i];
            printf("%d ", travel[i]);
        }
        div=2;
        break;

    case 2:
        for (int i=3; i<=6; i++) {
            total += travel[i];
            printf("%d ", travel[i]);
        }
        div=4;
        break;

    case 3:
        for (int i=7; i<=11; i++) {
            total += travel[i];
            printf("%d ", travel[i]);
        }
        div=5;
        break;

    case 4:
        for (int i=12; i<=14; i++) {
            total += travel[i];
            printf("%d ", travel[i]);
        }
        div=3;
        break;

    case 5:
        for (int i=15; i<=16; i++) {
            total += travel[i];
            printf("%d ", travel[i]);
        }
        div=2;
        break;

    }

    float average = total/div;
    printf("\n Average at that level is= %d/%d= %f", total, div, average);

}

void push(int dat) {
    if (l==-1) {
        f=0,
        l=0;
    }
    else
        l= (l+1) %N;

    Q[l]=dat;
}

int pop() {
    int dat = Q[f];
    Q[f] = 0;

    if (f==l) {
        f=-1;
        l=-1;
    }

    else f= (f+1) %N;

    return dat;
}

void linearity(struct Node * root) {

    struct Node * cur;

    if ( root->left != NULL && root->right != NULL) {
        printf("\n FALSE NOT LINEAR \n");
        return;
    }
    else {
        if ( root->left != NULL ) {
            cur = root->left;
        }
        if ( root->right != NULL) {
            cur = root->right;
        }
        if ( root->left == NULL && root->right== NULL) {
            printf("\n TRUE LINEAR \n");
            return;
        }

        linearity(cur);
    }

}
