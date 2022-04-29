#include <stdio.h>
#include <math.h>

int main() {

double E_s = 0.001;
int max_iteration = 50;
float w = 1.2;

float a1[] = {4,1,-1,1};
float a2[] = {1,4,-1,-1};
float a3[] = {1,-1,1,3};
float a4[] = {-1,-1,5,1};
/*
for (int i=0; i<=3; i++) {
    printf("a1[%d] = %d\n", i, a1[i]);
    printf("a2[%d] = %d\n", i, a2[i]);
    printf("a3[%d] = %d\n", i, a3[i]);
    printf("a4[%d] = %d\n", i, a4[i]);

}
*/

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
            printf("problem in row 1\n");
            row1= 1;
            }
    tot = 0;

for (int i=0; i<=3; i++) {
    if (i != 1) { tot += abs(a2[i]); }
}
    if (a2[1] < tot) {
            printf("problem in row 2\n");
            if (row1 == 0) row1 = 2;
            else row2 = 2;
            }
     tot = 0;

for (int i=0; i<=3; i++) {
    if (i != 2) { tot += abs(a3[i]); }
}
  if (a3[2] < tot) {
        printf("problem in row 3\n");
            if (row1 == 0) row1 = 3;
            else row2 = 3;
            }
   tot = 0;

for (int i=0; i<=3; i++) {
    if (i != 3) { tot += abs(a4[i]); }
}
   if (a4[3] < tot) {
        printf("problem in row 4\n");
            if (row1 == 0) row1 = 2;
            else row2 = 2;
            }
    tot = 0;

printf("For convergence, rows %d and %d should interchange\n", row1+1, row2+1);

//interchange rows
int hold[4];
for (int c=0; c<=3; c++) {
hold[c] = a3[c];
a3[c] = a4[c];
a4[c] = hold[c];
}

//see the new A
printf("The new A matrix coefficients are:\n");
for (int i=0; i<=3; i++) {
    printf("a1[%d] = %f\n", i, a1[i]);
    printf("a2[%d] = %f\n", i, a2[i]);
    printf("a3[%d] = %f\n", i, a3[i]);
    printf("a4[%d] = %f\n", i, a4[i]);

}

//first iteration
x1[0] = (1-w)*x0[0] + w*(1/a1[0])*(-a1[1]*x0[1] -a1[2]*x0[2] -a1[3]*x0[3] - 2);
x1[1] = (1-w)*x0[1] + w*(1/a2[1])*(-a2[0]*x1[0] -a2[2]*x0[2] -a2[3]*x0[3] - 1);
x1[2] = (1-w)*x0[2] + w*(1/a3[2])*(-a3[0]*x1[0] -a3[1]*x1[1] -a3[3]*x0[3] + 1);
x1[3] = (1-w)*x0[3] + w*(1/a4[3])*(-a4[0]*x1[0] -a4[1]*x1[1] -a4[2]*x1[2] + 0);


printf("Iteration 1\n");
for (int i=0; i<=3; i++) {
    printf("x%d(1) = %f\n", i+1, x1[i]);
}

int iteration = 2;

while (iteration < max_iteration) {
//second iteration
x2[0] = (1-w)*x1[0] + w*(1/a1[0])*(-a1[1]*x1[1] -a1[2]*x1[2] -a1[3]*x1[3] - 2);
x2[1] = (1-w)*x1[1] + w*(1/a2[1])*(-a2[0]*x2[0] -a2[2]*x1[2] -a2[3]*x1[3] - 1);
x2[2] = (1-w)*x1[2] + w*(1/a3[2])*(-a3[0]*x2[0] -a3[1]*x2[1] -a3[3]*x1[3] + 1);
x2[3] = (1-w)*x1[3] + w*(1/a4[3])*(-a4[0]*x2[0] -a4[1]*x2[1] -a4[2]*x2[2] + 0);

printf("Iteration %d\n", iteration);
for (int i=0; i<=3; i++) {
    printf("x%d(%d) = %f\n", i+1, iteration, x2[i]);
}

//error
float max_x2 = fabs(x2[0]);
for (int i=0; i<=3; i++) {
    if (max_x2 < fabs(x2[i])) max_x2 = fabs(x2[i]);
}


double difference = fabs( x2[0] - x1[0]);
for (int i=0; i<=3; i++) {
    if (difference < fabs( x2[i] - x1[i])) difference = fabs( x2[i] - x1[i]);
}

double E_a = difference/max_x2;

printf("E_a = %f\n", E_a);

if (E_a <= E_s) break;
else { //x2 is the new x1
    for (int c=0; c<=3; c++) {
        x1[c] = x2[c];
    }
    iteration++;
    }
}
}

