// ITERATIVE METHOD

#include <stdio.h>
#include <math.h>
float f(float x)
{
    return 2 * x - log10(x) - 7;
} 
float g(float x) //phi(x)
{
    return (log10(x) + 7) / 2;
}

float dq(float x)//phi'(x)
{
    return 1 / (2 * x * log(10));
}

int main()
{
    int iter = 0;
    float x0, x1, allowederr;
    do
    {
        printf("Enter the value of x0:\n");
        scanf("%f", &x0);
        if (fabs(dq(x0)) < 1)
        {
            break;
        }
        else
        {
            printf("Condition |dq(x0)| < 1 not satisfied, change x0 or function.\n");
        }
    } while (1);

    printf("Enter Allowed Error:\n");
    scanf("%f", &allowederr);

    do
    {
        x1 = g(x0);

        if (fabs(x1 - x0) <= allowederr)
        {
            printf("Root of the equation is %f after %d iterations\n", x1, iter);
            break;
        }
        else
        {
            x0 = x1;
            printf("%d iteration, value of x0 = %f, value of g(x0) = %f\n", iter, x0, g(x0));
        }
        iter++;
    } while (1);
    return 0;
}
