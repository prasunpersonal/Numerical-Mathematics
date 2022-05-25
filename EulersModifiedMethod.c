#include<stdio.h>
#include<math.h>

#define EPSIOLON 0.0001

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
        double mod_y = y + h*f(x,y), mod_x = x+h;
        while(fabs(mod_y - (y + (h/2 * (f(x, y) + f(mod_x, mod_y))))) >= EPSIOLON) {
            mod_y = y + (h/2 * (f(x, y) + f(mod_x, mod_y)));
        }
        x = mod_x;
        y = mod_y;
    }
    printf("The value at X=%g is %g", X, y);
    return 0;
}