#include <stdio.h>
#include <stdlib.h>

struct Node {
    int row;
    int column;
    int value;
    struct Node *next;
    struct Node *down;
};

struct Node *create(int n);
void display( struct Node *start);
void display2( struct Node *start);

int main() {
    int nodenumber=10;

    struct Node *start=NULL;

    start= create(nodenumber);

    display2(start);


}

struct Node *create(int n) {
    struct Node *start=NULL;
    struct Node *temp=NULL;
    struct Node *p=NULL;

    for (int i=0; i<n;i++) {

        temp=(struct Node*)malloc(sizeof(struct Node));
        temp->row = 2;
        temp->column= 3;
        temp->value= 4;
        temp->next=NULL;
        temp->down=NULL;

        if(start == NULL) {
            start=temp;
        }
        else {
            p=start;

            while(p->next !=NULL)
                p = p->next;
                p->next = temp;

            while (p->down !=NULL)
                p = p->down;
                p->down = temp;
        }
    }
  return start;

};

void display( struct Node *start){
    struct Node *p= start;

    while(p != NULL) {
        printf("%d\n", p->row);
        printf("%d\n", p->column);
        printf("%d\n", p->value);
        p= p->next;
    }
}


void display2( struct Node *start){
    struct Node *p= start;

    while(p != NULL) {
        printf("%d\t", p->row);
        printf("%d\t", p->column);
        printf("%d\n", p->value);
        p= p->down;
    }
}
