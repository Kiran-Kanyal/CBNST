#include <stdio.h>
#include <math.h>
float getAbsoluteError(float actual, float approximate)
{
    return fabs(actual - approximate);
}
int main()
{
    float approximate1, approximate2, approximate3;
    float actual = (float)1 / 3;

    printf("Input the first approximate value of (1/3) : ");
    scanf("%f", &approximate1);
    printf("Input the second approximate value of (1/3) : ");
    scanf("%f", &approximate2);
    printf("Input the third approximate value of (1/3) : ");
    scanf("%f", &approximate3);

    float absoluteError1 = getAbsoluteError(actual, approximate1);
    float absoluteError2 = getAbsoluteError(actual, approximate2);
    float absoluteError3 = getAbsoluteError(actual, approximate3);

    float bestApproximate;

    if (absoluteError1 < absoluteError2 && absoluteError1 < absoluteError3)
    {
        bestApproximate = approximate1;
    }
    else if (absoluteError2 < absoluteError1 && absoluteError2 < absoluteError3)
    {
        bestApproximate = approximate2;
    }
    else
    {
        bestApproximate = approximate3;
    }

    printf("Absolute Error for %f : %f\n", approximate1, absoluteError1);
    printf("Absolute Error for %f : %f\n", approximate2, absoluteError2);
    printf("Absolute Error for %f : %f\n", approximate3, absoluteError3);
    printf("Best Approximation for 1/3 is = %.2f\n", bestApproximate);

    return 0;
}