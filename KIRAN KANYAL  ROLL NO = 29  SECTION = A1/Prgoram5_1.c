// Newton Raphson Method

#include <stdio.h>
#include <math.h>

float f(float x)
{
    // return 3 * x - cos(x) - 1;
    return x * x - 12;
}

float df(float x)
{
    return 2 * x;
    //   derivative of f(x)
    // return 3 + sin(x);
}

int main()
{
    int iter = 0;
    float x0, x1, allowederr;
    printf("Enter the initial guess:\n");
    scanf("%f", &x0);

    printf("Enter allowed error:\n");
    scanf("%f", &allowederr);

    do
    {
        iter++;
        if (df(x0) == 0)
        {
            printf("Error.");
            break;
        }
        x1 = x0 - f(x0) / df(x0); // Newton Raphson Formula

        printf("%d iteration, x0 = %f, x1 = %f, \n", iter, x0, x1);

        if (fabs(x0 - x1) <= allowederr)
        {
            printf("Root of the equation is %f after %d iterations.\n", x1, iter);
            break;
        }
        x0 = x1;
    } while (1);
    return 0;
}
