#include <stdio.h>
#include <math.h>

void toscreen();

int main() {

double E_s = 0.001;
int max_iteration = 50;

int a1[] = {4,1,-1,1};
int a2[] = {1,4,-1,-1};
int a3[] = {1,-1,1,3};
int a4[] = {-1,-1,5,1};

int x0[4] = {0,0,0,0};
double x1[4];
double x2[4];

int row1 = 0;
int row2 = 0;

int tot = 0;

for (int i=0; i<=3; i++) {
   if (i != 0) { tot += abs(a1[i]); }
}
    if (abs(a1[0]) < tot) {
            printf("problem in row 1");
            row1= 1;
            }
    tot = 0;

for (int i=0; i<=3; i++) {
    if (i != 1) { tot += abs(a2[i]); }
}
    if (a2[1] < tot) {
            printf("problem in row 2");
            if (row1 == 0) row1 = 2;
            else row2 = 2;
            }
     tot = 0;

for (int i=0; i<=3; i++) {
    if (i != 2) { tot += abs(a3[i]); }
}
  if (a3[2] < tot) {
        printf("problem in row 3");
            if (row1 == 0) row1 = 3;
            else row2 = 3;
            }
   tot = 0;

for (int i=0; i<=3; i++) {
    if (i != 3) { tot += abs(a4[i]); }
}
   if (a4[3] < tot) {
        printf("problem in row 4");
            if (row1 == 0) row1 = 2;
            else row2 = 2;
            }
    tot = 0;

printf("\n For convergence, rows %d and %d should interchange\n", row1+1, row2+1);

//interchange rows
int hold[4];
for (int c=0; c<=3; c++) {
hold[c] = a3[c];
a3[c] = a4[c];
a4[c] = hold[c];
}

int iteration = 2;

//first iteration
x1[0] = (1/a1[0])*(-a1[1]*x0[1] -a1[2]*x0[2] -a1[3]*x0[3] + (-2));
x1[1] = (1/a1[1])*(-a1[0]*x1[0] -a1[3]*x0[3] -a1[4]*x0[4] + (-1));
x1[2] = (1/a1[2])*(-a1[0]*x1[0] -a1[1]*x1[1] -a1[4]*x0[4] + 1);
x1[3] = (1/a1[3])*(-a1[0]*x1[0] -a1[1]*x1[1] -a1[3]*x1[3] + 0);

printf("Iteration 1\n");
for (int i=0; i<=3; i++) {
    printf("x%d(1) = %d\n", i, x1[i]);
}

while (iteration < max_iteration) {
//second iteration
x2[0] = (1/a1[0])*(-a1[1]*x1[1] -a1[2]*x1[2] -a1[3]*x1[3] + (-2));
x2[1] = (1/a1[1])*(-a1[0]*x2[0] -a1[3]*x1[3] -a1[4]*x1[4] + (-1));
x2[2] = (1/a1[2])*(-a1[0]*x2[0] -a1[1]*x2[1] -a1[4]*x1[4] + 1);
x2[3] = (1/a1[3])*(-a1[0]*x2[0] -a1[1]*x2[1] -a1[3]*x2[3] + 0);

printf("Iteration %d\n", iteration);
for (int i=0; i<=3; i++) {
    printf("x%d(%d) = %d\n", i, iteration, x2[i]);
}

//error
double max_x2 = abs(x2[0]);
for (int i=0; i<=3; i++) {
    if (max_x2 < abs(x2[i])) max_x2 = abs(x2[i]);
}

double difference = abs( x2[0] - x1[0]);
for (int i=0; i<=3; i++) {
    if (difference < abs( x2[i] - x1[i])) difference = abs( x2[i] - x1[i]);
}

double E_a = difference/max_x2;

if (E_a <= E_s) break;
else { //x2 is the new x1
    for (int c=0; c<=3; c++) {
        x1[c] = x2[c];
    }
    iteration++;
    }
}
}

