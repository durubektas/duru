#include <stdio.h>
#include <stdlib.h>
#define N 17

struct Node {
    int value;
    struct Node * left;
    struct Node * right;
};

void addNode(int number);           //function to add a node to the tree
void avlevel(int level);            //function that finds average value at a level
void linearity(struct Node * root); //function that tells if linear or not
void btr(struct Node * root);       //function that travels through by levels horizontally
void push(int);                     //function that is used in btr
int pop();                          //function that is used in btr

int data[N] = {34, 25, 58, 19, 73, 33, 15, 26, 55, 9, 76, 74, 20, 78, 48, 89, 77};

struct Node *rootPtr;   //root
struct Node * Q[100];   //queu
int f=-1;   //first
int l=-1;   //last
int travel[N];  //array of travel

int main() {
    //TASK 1
    //builds a binary search tree
    for(int i=0; i<N; i++) {
        addNode( data[i] );
    }

    //TASK 2
    //tells the average value of a specific level
    int level;
    //user asked to type a level
    printf("Enter a tree level(minimum 0): ");
    scanf("%d", &level);

    btr(rootPtr);       //function travels through the datas horizontally
    avlevel(level);     //function calculates the average value at that level

    //TASK 3
    //determines whether the tree is linear or not
    linearity(rootPtr);

}

//function that adds a node to the tree
void addNode( int number ) {
    //pointers that will be used
    struct Node *current;
    struct Node *parent;
    struct Node *newnode;

    newnode = malloc( sizeof (struct Node)); //creates space for new node
    //create new node by assigning only it's data value
    newnode->value = number;
    newnode->left = NULL;
    newnode->right = NULL;

    //if tree is empty
    if (rootPtr == NULL) {
        rootPtr = newnode; //new node is the root
        return;
    }

    current = rootPtr;
    //while the leaf is found
    while ( current != NULL ) {
        parent = current;
        if ( number < current->value) {
            current = current->left;    //go to the left of the under of the node
        }
        else
            current = current ->right;  //go to the right of the under of the node
    }

    //when the node is the leaf
    if ( number < parent->value) {
        parent->left = newnode;
    }
    else
        parent->right = newnode;
}

//function that travels through the tree horizontally
void btr( struct Node * root) {
    //if tree is empty
    if (root == NULL) {
        return;
    }

    push(root);

    int count=0;
    //while queu is not finished
    while (f!=-1) {
        struct Node * v = pop();
        printf("%d ", v->value);
        travel[count] = v->value; //writes the value of that node in the travel array

        if (v->left != NULL) {
            push(v->left);
        }

        if (v->right != NULL) {
            push(v->right);
        }

        count++;
    }
}

//calculates the average value at a specific level
void avlevel( int level ) {
    int total=0; //sum of the value of nodes at that level
    int div; //number of nodes at that level

    printf("\n \nData items at that level are = ");

    //according to every level case, the values taken from travel array differ
    switch (level) {

    case 0:
        total += travel[0];
        printf("%d ", travel[0]);
        div=1; //one node
        break;

    case 1:
        for (int i=1; i<=2; i++) {
            total += travel[i];
            printf("%d ", travel[i]);
        }
        div=2; //two nodes
        break;

    case 2:
        for (int i=3; i<=6; i++) {
            total += travel[i];
            printf("%d ", travel[i]);
        }
        div=4; //4 nodes
        break;

    case 3:
        for (int i=7; i<=11; i++) {
            total += travel[i];
            printf("%d ", travel[i]);
        }
        div=5; //5 nodes
        break;

    case 4:
        for (int i=12; i<=14; i++) {
            total += travel[i];
            printf("%d ", travel[i]);
        }
        div=3; //3 nodes
        break;

    case 5:
        for (int i=15; i<=16; i++) {
            total += travel[i];
            printf("%d ", travel[i]);
        }
        div=2; //2 nodes
        break;

    }

    //calculate average
    float average = total/div;
    printf("\nAverage at that level is= %d/%d= %f\n", total, div, average);

}

//push function used in travel function
void push(int dat) {
    if (l==-1) {
        f=0,
        l=0;
    }
    else
        l= (l+1) %N;

    Q[l]=dat;
}

//pop function used in travel function
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

//Finds if tree is linear or not
void linearity(struct Node * root) {

    struct Node * cur; //current pointer

    printf("\nResult of linear testing is = ");

    //if not both left and right pointers of the node is not NULL, it is certain that tree is not linear
    if ( root->left != NULL && root->right != NULL) {
        printf("False \n");
        return;
    }
    //if only one of the node's pointer is not NULL, go to that direction to the next node
    else {
        if ( root->left != NULL ) {
            cur = root->left;
        }
        if ( root->right != NULL) {
            cur = root->right;
        }
        //if leaf is found
        if ( root->left == NULL && root->right== NULL) {
            printf("True \n");
            return;
        }

        //if leaf is not found, put that node into this same function as it is the new root
        linearity(cur);
    }

}
