#include <stdio.h>
#include <stdlib.h>

void printList();
void add(int val);

struct Node {
    int row;
    int column;
    int value;
    struct Node * next;
    struct Node * down;
};

struct Node *start=NULL;

int main() {
    add(1);
    printList();
}

void add(int val) {
    struct Node *newp;
    struct Node *pre;
    struct Node *cur;

    newp=malloc(sizeof(struct Node));
    newp->row=val;
    newp->column=val;
    newp->value=val;
    newp->next=NULL;

    pre=NULL;
    cur=start;

    while(cur != NULL) {
        pre=cur;
        cur=cur->next;
    }

    if (pre==NULL) {
        newp->next=start;
        start=newp;
    }

    else {
        pre->next=newp;
        newp->next=cur;
    }
}

void printList() {
    struct Node *cur = start;
    if ( cur==NULL) { printf("empty list"); }

    while (cur != NULL ) {
        printf("%d\t", cur->row);
        printf("%d\t", cur->column);
        printf("%d\n", cur->value);
        cur=cur->next;
    }
}
