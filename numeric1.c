#include <stdio.h>
#include <math.h>

void bisection_method(double x_l, double x_u);
double function(double);
void false_position(double x_l, double x_u) ;

int main() {
    double x_l= 0;
    double x_u= 0.5;

    bisection_method( x_l, x_u);

}

void bisection_method( double x_l, double x_u) {

    if ( function(x_l)*function(x_u) > 0 ) { printf( "No root in this interval!" ); }

    printf( "Iteration no:\t x_l\t         x_u\t         x_r\t         f(x_r)\t         E_a\n");

    int no = 1;
    double E_a = (x_u - x_l)/(x_l + x_u);


    while ( E_a > 0.000001) {

    double x_r = (x_l + x_u)/ 2;

    E_a = (x_u - x_l)/(x_l + x_u);

    printf( "\t %d\t %f\t %f\t %f\t %f\t %f\n", no, x_l, x_u, x_r, function(x_r), E_a);

    if ( function(x_r)*function(x_l) < 0) { x_u = x_r; }
    else { x_l = x_r; }

    no++;
    }

}

double function(double t) {
  double i_t=9*exp(-t)*cos(2*M_PI*t)-3.5;
  return i_t;
}

void false_position( double x_l, double x_u ) {
    if ( function(x_l)*function(x_u) > 0 ) { printf( "No root in this interval!" ); }
}
