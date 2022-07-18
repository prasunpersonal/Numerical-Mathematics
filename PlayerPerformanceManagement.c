#include <stdio.h>

int factorial(int n)
{
    return (n == 1) ? 1 : n * factorial(n - 1);
}

double calc_u(double u, int n)
{
    double tmp = u;
    for (int i = 1; i < n; i++)
    {
        tmp *= (u - i);
    }
    return tmp;
}

double calculteAveragePerformance(int n, int playerPerformance[])
{
    // Mean Calculation
    float tot = 0;
    for (int i = 0; i < n; i++)
    {
        tot = tot + playerPerformance[i];
    }
    return tot / n;
}

double approxPerformance(int n, int playerPerformance[])
{
    // Approximate performance using newton's forward interpolation
    double table[n][n + 1];

    for (int i = 0; i < n; i++)
    {
        table[i][0] = i + 1;
        table[i][1] = playerPerformance[i];
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j <= n - i; j++)
        {
            table[j][i] = table[j + 1][i - 1] - table[j][i - 1];
        }
    }

    printf("\nThe forward difference table:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n - i; j++)
        {
            if (table[i][j] < 0)
                printf("%lf\t", table[i][j]);
            else
                printf(" %g\t", table[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    double u = (n+1 - table[0][0]) / (table[1][0] - table[0][0]);
    double y = table[0][1];

    for (int i = 2; i <= n; i++)
    {
        y += (table[0][i] * calc_u(u, i - 1) / factorial(i - 1));
    }

    return y;
}

int main()
{
    int n = 4;
    int playerPerformance[n];

    printf("\nEnter player performance of last %d years: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &playerPerformance[i]);
    }
    printf("\n");

    printf("Average performance of the player is: %.lf\n", calculteAveragePerformance(n, playerPerformance));
    printf("Approximate performance of the player for upcoming worldcup is: %.lf\n", approxPerformance(n, playerPerformance));

    return 0;
}