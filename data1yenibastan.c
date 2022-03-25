#include <stdio.h>
#include <stdlib.h>

//The function prototypes

void readfile();            //Function that reads file and creates linked list with those values
void calculate_row();       //Function that goes through rows and calculates
void calculate_column();    //Function that goes through columns and calculates
void row_show();            //Screen output for rows
void column_show();         //Screen output for columns
//void printList();         //this function was for me to see

//Global definitions
struct Node {
    int row;                //Row index
    int col;                //Column index
    int value;              //Non-zero data value
    struct Node * next;     //Pointer to next in line
    struct Node * down;     //Pointer to down
};

#define NR 5   //Max number of rows
#define NC 8   //Max number of columns
struct Node * ArrayOfRows[NR] = {NULL};     //Array of row
struct Node * ArrayOfColumns[NC] = {NULL};  //Array of column

//For the output (total of rows)
int row0 = 0;
int row1 = 0;
int row2 = 0;
int row3 = 0;
int row4 = 0;

//For the output (total of columns)
int column0 = 0;
int column1 = 0;
int column2 = 0;
int column3 = 0;
int column4 = 0;
int column5 = 0;
int column6 = 0;
int column7 = 0;

struct Node *start=NULL;  //defining a start node which is initialized as empty

//Main function
int main() {

    readfile();             //File is read and linked list is built
    calculate_row();        //Go through linked list for rows
    row_show();             //The total of rows is printed to screen
    calculate_column();     //Go through linked list for columns
    column_show();          //The total of columns is printed to screen

}

//Function to go through the linked list and calculate for each row summation
void calculate_row() {
    struct Node *cur = start; //a pointer called "cur" (for current) of type Node is initialized as "start"
    if ( cur == NULL) { printf("empty");} //if "cur" is empty, print it to the screen

    //While "cur" is not at the end of list;
    while (cur != NULL ) {

        //The total values for each row is increased by the value of the node for each case
        if (cur->row == 0) { row0+=cur->value; }
        if (cur->row == 1) { row1+=cur->value; }
        if (cur->row == 2) { row2+=cur->value; }
        if (cur->row == 3) { row3+=cur->value; }
        if (cur->row == 4) { row4+=cur->value; }

        cur=cur->next; //"cur" goes to the next node

    }
}

//Function to go through the linked list and calculate for each column summation
void calculate_column() {
    struct Node *cur = start; //a pointer called "cur" (for current) of type Node is initialized as "start"
    if ( cur == NULL) { printf("empty");} //if "cur" is empty, print it to the screen

    //While "cur" is not at the end of list;
    while (cur != NULL ) {

        //The total values for each column is increased by the value of the node for each case
        if (cur->col == 0) { column0+=cur->value; }
        if (cur->col == 1) { column1+=cur->value; }
        if (cur->col == 2) { column2+=cur->value; }
        if (cur->col == 3) { column3+=cur->value; }
        if (cur->col == 4) { column4+=cur->value; }
        if (cur->col == 5) { column5+=cur->value; }
        if (cur->col == 6) { column6+=cur->value; }
        if (cur->col == 7) { column7+=cur->value; }

        cur=cur->next; //"cur" goes to the next node
    }
}

//This function opens the file and creates linked list with the values inside
void readfile() {

    FILE *file; //Pointer to the type of FILE is initialized
    int data; //Integer that will be used

    file = fopen( "SPARSE.TXT", "r"); //file is opened to read

    while ( !feof(file)) { //While file is not at the end

        //New pointers of type Node:
        struct Node *newp;  //newp for new pointer
        struct Node *pre;   //pre for previous pointer
        struct Node *cur;   //cur for current pointer

        newp=malloc(sizeof(struct Node)); //New place is created for newp

        fscanf(file ,"%d", &data); //gets the value from file and data is equalized to that integer
        newp->row=data; //data integer is the row index of the node

        fscanf(file, "%d", &data); //gets a new data from file
        newp->col=data; //data integer is the column index of the node

        fscanf(file ,"%d", &data); //gets another new data
        newp->value=data; //data integer is the value index of the node

        //the pointers of the Node are initialized to NULL
        newp->next=NULL;
        newp->down=NULL;

        pre=NULL;  //previous pointer is also equalized to NULL
        cur=start; //current pointer is equalized to start pointer

        //While current pointer is not at the end
        while(cur != NULL) {
            pre=cur;        //previous is the new current
            cur=cur->next;  //current is the new current's next
        }

        //If previous is at the beginning
        if (pre==NULL) {
            newp->next=start;
            start=newp;
        }

        else {
            pre->next=newp; //previous' next pointer is the new pointer
            newp->next=cur; //new pointers' next pointer is the new current
        }
    }

    fclose(file); //file is closed
}

//Screen output function to show row values
void row_show(){
    printf( " TOTALS OF ROWS: \n");
    printf( " Row 0 : %d\n Row 1 : %d\n Row 2 : %d\n Row 3 : %d\n Row 4 : %d\n", row0, row1, row2, row3, row4);
}

//Screen output function to show column values
void column_show(){
    printf( " TOTALS OF COLUMNS: \n");
    printf( " Col 0 : %d\n Col 1 : %d\n Col 2 : %d\n Col 3 : %d\n Col 4 : %d\n Col 5 : %d\n Col 6 : %d\n Col 7 : %d\n", column0, column1, column2, column3, column4, column5,
           column6, column7);
}

/*
This function was for me to see if readfile() could open the file correctly

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
*/
