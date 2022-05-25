#include<stdio.h>
#include<math.h>

#define EPSIOLON 0.0001

double f(double x) {
    return pow(x, 3) - 2*x -5;
}

double _f(double x) {
    return 3*pow(x, 2) - 2;
}

double NewtonRapson(double x) {
    int i=0;
    while(fabs(f(x)/_f(x)) >= EPSIOLON) {
        printf("X-%d = %g\n", i++, x);
        x -= f(x)/_f(x);
    }
    return x;
}

int main(){
    printf("\nThe approximate root is: %g", NewtonRapson(2));
    return 0;
}