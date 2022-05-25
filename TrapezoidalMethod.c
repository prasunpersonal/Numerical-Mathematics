#include<stdio.h>
#include<math.h>

double f(double x) {
    return 1.0/(1+pow(x,2));
    // return 1.0/x;
}

int main(){
    double a=0, b=1;
    int n;
    printf("Enter the no of iuntervals: ");
    scanf("%d", &n);

    double values[n+1][2];
    double h = (b-a)/n, x=a;

    for(int i=0; x<=b; i++) {
        values[i][0] = x;
        values[i][1] = f(x);
        x += h;
    }

    double y = (values[0][1] + values[n][1]) / 2;
    for(int i=1; i<n; i++) {
        y += values[i][1];
    }
    y *= h;

    printf("The value is: %g", y);
    return 0;
}