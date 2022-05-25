#include<stdio.h>
#include<math.h>

double f(double x, double y) {
    return (1 - x*y) / pow(x,2);
}

int main(){
    double x, y, h, X;
    printf("Enter value of X-0: ");
    scanf("%lf", &x);
    printf("Enter value of Y-0: ");
    scanf("%lf", &y);
    printf("Enter step size: ");
    scanf("%lf", &h);
    printf("Enter value of X for finding the approximation: ");
    scanf("%lf", &X);
    while (x < X){
        y = y + h*f(x,y);
        x += h;
    }
    printf("The value at X=%g is %g", X, y);
    return 0;
}