// Gauss Elimination method
#include <stdio.h>
int main()
{
    int n;
    printf("Enter the order of matrix: ");
    scanf("%d", &n);
    float A[n][n + 1];
    printf("Enter coefficients for x1, x2, ..., x%d and the constant terms:\n", n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            scanf("%f", &A[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (A[i][i] == 0)
            {
                printf("Unique solution does not exist.\n");
                return -1;
            }
            for (int k = 0; k <= n; k++)
            {
                A[j][k] = A[j][k] - (A[j][i] / A[i][i]) * A[i][k];
            }
        }
    }

    printf("Upper Triangular Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            printf("%.0f\t", A[i][j]);
        }
        printf("\n");
    }
    float x[n];

    for (int i = n - 1; i >= 0; i--)
    {

        x[i] = A[i][n];
        for (int j = i + 1; j < n; j++)
        {
            x[i] -= A[i][j] * x[j];
        }
        x[i] /= A[i][i];
    }

    printf("The solution is : \n");
    for (int i = 0; i < n; i++)
    {
        printf("x%d = %.3f\n", i + 1, x[i]);
    }
    return 0;
}
