// BISECTION METHOD
#include <stdio.h>
#include <math.h>
float f(float x)
{
    return x * log10(x) - 1.2;
}
int main()
{
    float x, a, b, aerr;
    int itr = 0, flag = 0;
    do
    {
        printf("\nEnter 1st number: ");
        scanf("%f", &a);
        printf("\nEnter 2nd number: ");
        scanf("%f", &b);
        if (a < b && f(a) * f(b) < 0)
        {
            flag = 1;
            printf("\nRoots lie between %f and %f", a, b);
        }
        else
        {
            printf("\nWrong Intervals");
        }
    } while (flag != 1);
    printf("\nEnter the allowed error: ");
    scanf("%f", &aerr);
    do
    {
        itr++;
        x = (a + b) / 2;
        printf("\n%d Iteration value of x is %f, value of (%f) is %f", itr, x, x, f(x));
        if (fabs(f(x)) <= aerr)
        {
            flag = 0;
            printf("\nThe roots of the equation is %f after %d iteration", x, itr);
        }
        else if (f(x) * f(a) < 0)
        {
            b = x;
        }
        else
        {
            a = x;
        }
    } while (flag != 0);
}
