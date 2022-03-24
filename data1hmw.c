#include <stdio.h>
#include <stdlib.h>

void printList();
void readfile();
void readfile2();
void calculate_row();
void calculate_column();
void row_show();
void column_show();

struct Node {
    int row;
    int col;
    int value;
    struct Node * next;
    struct Node * down;
};

#define NR 5
#define NC 8
struct Node * ArrayOfRows[NR] = {NULL};
struct Node * ArrayOfColumns[NC] = {NULL};


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
        printf("%d\t", cur->col);
        printf("%d\n", cur->value);
        cur=cur->next;
    }
}

void calculate_row() {
    struct Node *cur = ArrayOfRows[NR];
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
        if (cur->col == 0) { column0+=cur->value; }
        if (cur->col == 1) { column1+=cur->value; }
        if (cur->col == 2) { column2+=cur->value; }
        if (cur->col == 3) { column3+=cur->value; }
        if (cur->col == 4) { column4+=cur->value; }
        if (cur->col == 5) { column5+=cur->value; }
        if (cur->col == 6) { column6+=cur->value; }
        if (cur->col == 7) { column7+=cur->value; }

        cur=cur->down;
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
        newp->col=data;

        fscanf(file ,"%d", &data);
        newp->value=data;

        newp->next=NULL;
        newp->down=NULL;

        pre=NULL;
        cur=ArrayOfRows[NR];

        while(cur != NULL) {
            pre=cur;
            cur=cur->next;
        }

        if (pre==NULL) {
            newp->next=ArrayOfRows[NR];
            ArrayOfRows[NR]=newp;
        }

        else {
            pre->next=newp;
            newp->next=cur;
        }
    }

    fclose(file);
}

void readfile2() {
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
        newp->col=data;

        fscanf(file ,"%d", &data);
        newp->value=data;

        newp->next=NULL;
        newp->down=NULL;

        pre=NULL;
        cur=start;

        while(cur != NULL) {
            pre=cur;
            cur=cur->down;
        }

        if (pre==NULL) {
            newp->down=start;
            start=newp;
        }

        else {
            pre->down=newp;
            newp->down=cur;
        }
    }

    fclose(file);
}


void row_show(){
    printf( " TOTALS OF ROWS: \n");
    printf( " Row 0 : %d\n Row 1 : %d\n Row 2 : %d\n Row 3 : %d\n Row 4 : %d\n", row0, row1, row2, row3, row4);
}

void column_show(){
    printf( " TOTALS OF COLUMNS: \n");
    printf( " Col 0 : %d\n Col 1 : %d\n Col 2 : %d\n Col 3 : %d\n Col 4 : %d\n Col 5 : %d\n Col 6 : %d\n Col 7 : %d\n", column0, column1, column2, column3, column4, column5,
           column6, column7);
}
