
// GAUSS SIEDEL
#include <stdio.h>
#include <math.h>

float f1(float a, float b, float c, float d, float y, float z)
{

    return (d - c * z - b * y) / a;
}

float f2(float a, float b, float c, float d, float x, float z)
{
    return (d - c * z - a * x) / b;
}

float f3(float a, float b, float c, float d, float x, float y)
{
    return (d - b * y - a * x) / c;
}

int main()
{

    int n;
    printf("Enter the order of the matrix: ");
    scanf("%d", &n);

    int A[n][n + 1];

    printf("Enter coefficients for x1, x2, ..., x%d and the constant terms:\n", n);
    for (int i = 0; i < n; i++)
    {
        int diagonal = 0;
        int sum = 0;
        for (int j = 0; j <= n; j++)
        {
            scanf("%d", &A[i][j]);
            if (i == j)
                diagonal = fabs(A[i][j]);
            else if (j != n)
                sum += fabs(A[i][j]);
        }
        if (diagonal < sum)
        {
            printf("Solution does not converge.");
            return -1;
        }
    }

    float allowedErr;
    printf("Enter allowed error : ");
    scanf("%f", &allowedErr);

    float e1, e2, e3, x1, y1, z1, x0 = 0, y0 = 0, z0 = 0;
    int count = 1;
    do
    {
        x1 = f1(A[0][0], A[0][1], A[0][2], A[0][3], y0, z0);
        y1 = f2(A[1][0], A[1][1], A[1][2], A[1][3], x1, z0);
        z1 = f3(A[2][0], A[2][1], A[2][2], A[2][3], x1, y1);
        printf("Iteration = %d\t x = %0.4f\t y = %0.4f\t z = %0.4f\n", count, x1, y1, z1);

        /* Error */
        e1 = fabs(x0 - x1);
        e2 = fabs(y0 - y1);
        e3 = fabs(z0 - z1);

        count++;

        x0 = x1;
        y0 = y1;
        z0 = z1;

    } while (e1 > allowedErr && e2 > allowedErr && e3 > allowedErr);
}