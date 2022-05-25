#include<stdio.h>
#include<math.h>

#define EPSIOLON 0.00001

double f(double x) {
    return pow(x, 2) - 3;
}

double RegularFalsi(double a, double b) {
    double x;
    int i=1;
    do{
        x = (a*f(b) - b*f(a)) / (f(b) - f(a));
        if(f(x) < 0) {
            if(f(a) < 0) a = x;
            else b = x;
        } else if(f(x) > 0) {
            if(f(a) < 0) b = x;
            else a = x;
        } else {
            break;
        }
        printf("%02d no iteration = %g\n", i++, x);
    }while(fabs(f(x)) >= EPSIOLON);
    return x;
}

int main(){
    printf("\nThe approximate root is: %g", RegularFalsi(1, 2));
    return 0;
}