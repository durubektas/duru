#include <stdio.h>
#include <stdlib.h>

void printList();
void readfile();
void calculate_row();
void calculate_column();
void row_show();
void column_show();

int row0 = 0;
int row1 = 0;
int row2 = 0;
int row3 = 0;
int row4 = 0;

int column0 = 0;
int column1 = 0;
int column2 = 0;
int column3 = 0;
int column4 = 0;
int column5 = 0;
int column6 = 0;
int column7 = 0;


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
    calculate_row();
    row_show();
    calculate_column();
    column_show();

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

void calculate_row() {
    struct Node *cur = start;
    if ( cur == NULL) { printf("empty");}

    while (cur != NULL ) {
        if (cur->row == 0) { row0+=cur->value; }
        if (cur->row == 1) { row1+=cur->value; }
        if (cur->row == 2) { row2+=cur->value; }
        if (cur->row == 3) { row3+=cur->value; }
        if (cur->row == 4) { row4+=cur->value; }

        cur=cur->next;
    }
}

void calculate_column() {
    struct Node *cur = start;
    if ( cur == NULL) { printf("empty");}

    while (cur != NULL ) {
        if (cur->column == 0) { column0+=cur->value; }
        if (cur->column == 1) { column1+=cur->value; }
        if (cur->column == 2) { column2+=cur->value; }
        if (cur->column == 3) { column3+=cur->value; }
        if (cur->column == 4) { column4+=cur->value; }
        if (cur->column == 5) { column5+=cur->value; }
        if (cur->column == 6) { column6+=cur->value; }
        if (cur->column == 7) { column7+=cur->value; }

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

void row_show(){
    printf( "%d , %d, %d, %d, %d", row0, row1, row2, row3, row4);
}

void column_show(){
    printf( "%d , %d, %d, %d, %d, %d, %d, %d", column0, column1, column2, column3, column4, column5,
           column6, column7);
}
