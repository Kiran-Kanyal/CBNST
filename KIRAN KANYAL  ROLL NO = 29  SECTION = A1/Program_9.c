// WAP to implement NEWTONS FORWARD INTERPOLATION
#include <stdio.h>
#include <math.h>
int main()
{
    int n;
    printf("Enter the number of observations: ");
    scanf("%d", &n);

    float x[n];
    float y[n][n];

    printf("Enter the value of x and y for %d terms :\n", n);

    for (int i = 0; i < n; i++)
    {
        scanf("%f", &x[i]);
        scanf("%f", &y[i][0]);
    }

    float xValue;
    printf("Enter the point at which you want to find the value: ");
    scanf("%f", &xValue);

    float a = x[0];
    float h = x[1] - x[0];
    float u = (xValue - a) / h;

    for (int j = 1; j < n; j++)
    {
        for (int i = 0; i < n - j; i++)
        {
            y[i][j] = y[i + 1][j - 1] - y[i][j - 1];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            printf("%.2f\t", y[i][j]);
        }
        printf("\n");
    }

    float res = y[0][0];

    float uTerm = 1;
    float fact = 1;

    for (int i = 1; i < n; i++)
    {
        uTerm *= (u - (i - 1));
        fact *= i;
        res += (uTerm * y[0][i]) / fact;
    }
    printf("The interpolated value at x = %.4f is %.4f", xValue, res);
    return 0;
}