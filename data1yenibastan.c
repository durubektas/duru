#include <stdio.h>
#include <stdlib.h>

void printList();
void readfile();

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

        struct Node *newp;
        struct Node *pre;
        struct Node *cur;

        newp=malloc(sizeof(struct Node));

        fscanf(file ,"%d", &data);
        newp->row=data;

        fscanf(file, "%d", &data);
        newp->column=data;

        fscanf(file ,"%d", &data);
        newp->value=data;

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

    fclose(file);
}
