#include<stdio.h>

int factorial(int n) {
    return (n == 1) ? 1 : n*factorial(n-1);
}

double calc_u(double u, int n) {
    double tmp = u;
    for(int i=1; i<n; i++) {
        tmp *= (u-i);
    }
    return tmp;
}

int main(){
    int n;
    double x;
    printf("Enter no of data: ");
    scanf("%d", &n);

    double table[n][n+1];
    for(int i=0; i<n; i++) {
        printf("Enter X-%d: ", i+1);
        scanf("%lf", &table[i][0]);
        printf("Enter Y-%d: ", i+1);
        scanf("%lf", &table[i][1]);
    }

    printf("\nEnter the value of X ('X' = the point for which you need 'Y' value): ");
    scanf("%lf", &x);

    for(int i=2; i<=n; i++){
        for(int j=0; j<=n-i; j++){
            table[j][i] = table[j+1][i-1] - table[j][i-1];
        }
    }

    printf("\nThe difference table:\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<=n-i; j++){
            if(table[i][j] < 0) printf("%g\t", table[i][j]);
            else printf(" %g\t", table[i][j]);
        }
        printf("\n");
    }

    double u = (x - table[0][0]) / (table[1][0] - table[0][0]);
    double y = table[0][1];

    for(int i=2; i<=n; i++) {
        y += (table[0][i] * calc_u(u, i-1) / factorial(i-1));
    }

    printf("\nThe value of 'Y' for 'X' = %g is: %g\n", x, y);
    return 0;
}