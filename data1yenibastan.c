#include <stdio.h>
#include <stdlib.h>

void printList();
void add_row(int val);
void add_column(int val);
void add_value(int val);
void readfile();

int i=0;

struct Node {
    int row;
    int column;
    int value;
    struct Node * next;
    struct Node * down;
};

struct Node *start=NULL;

int main() {

    readfile();
    printList();

}

void add_row(int val) {
    struct Node *newp;
    struct Node *pre;
    struct Node *cur;

    newp=malloc(sizeof(struct Node));
    newp->row=val;



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

void add_column(int val) {
    struct Node *newp;
    struct Node *pre;
    struct Node *cur;

    newp=malloc(sizeof(struct Node));
    newp->column=val;
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

void add_value(int val) {
    struct Node *newp;
    struct Node *pre;
    struct Node *cur;

    newp=malloc(sizeof(struct Node));
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

void readfile() {
    FILE *file;
    int data;

    file = fopen( "SPARSE.TXT", "r");

    while ( !feof(file)) {

        fscanf(file ,"%d", &data);

        if (i%3==0) {add_row(data);}

        if (i%3==1) {add_column(data);}

        if (i%3==2) {add_value(data);}

        i=i+1;

    }

    fclose(file);
}
