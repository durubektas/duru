#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <string.h>

void ReadData();
void WriteData();
void add();

struct Node {
    int row;
    int column;
    int value;
    struct Node * next_right;
    struct Node * next_down;
};

struct Node matrix;

#define NR5
#define NC 8
struct Node * ArrayOfRows[NR] = {NULL};
struct Node * ArrayOfColumns[NC] = {NULL};

int main() {
    ReadData();
    WriteData();
}

void ReadData() {

    FILE *cfPtr;
    int data;

    cfPtr=fopen("SPARSE.TXT","r");

    while( !=feof(cfPtr) ) {
        fscanf( cfPtr, "%d", &data);
        add(data);
    }

    while ()

}


