#include<stdio.h>
#include<math.h>

double f(double x) {
    return 1.0/(1+pow(x,2));
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

    double evens=0, odds=0;

    for(int i=1; i<n; i++) {
        if(i%2 == 0) {
            evens += values[i][1];
        } else {
            odds += values[i][1];
        }
    }

    double y = h/3 * ((values[0][1] + values[n][1]) + 4*(odds) + 2*(evens));

    printf("The value is: %g", y);
    return 0;
}