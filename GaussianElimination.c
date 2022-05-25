#include<stdio.h>

int main(){
    int n = 3;
    double matrix[n][n+1];
    for(int i=0; i<n; i++) {
        printf("Enter value of X-%d: ", i);
        scanf("%lf", &matrix[i][0]);
        printf("Enter value of Y-%d: ", i);
        scanf("%lf", &matrix[i][1]);
        printf("Enter value of Z-%d: ", i);
        scanf("%lf", &matrix[i][2]);
        printf("Enter value of Eq-%d: ", i);
        scanf("%lf", &matrix[i][3]);
        printf("\n");
    }

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++) {
            double ratio = matrix[j][i]/matrix[i][i];
            for(int k=0; k<=n; k++) {
                matrix[j][k] = matrix[j][k] - ratio*matrix[i][k];
            }
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<=n; j++) {
            printf("%.02lf\t", matrix[i][j]);
        }
        printf("\n");
    }

    double values[n];
    for(int i=0; i<n; i++) values[i] = 1.0;

    for(int i=n-1; i>=0; i--) {
        double tmp = 0.0;
        for(int j=0; j<=n; j++) {
            tmp += (matrix[i][j] * values[j]);
        }
        values[i] = matrix[i][n]/tmp;
    }

    printf("\nThe values of x, y, z are: %lf, %lf, %lf", values[0], values[1], values[2]);
    return 0;
}