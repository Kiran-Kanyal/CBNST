#include <stdio.h>
#include <math.h>

float getAbsoluteError(float actual, float approximate)
{
    return fabs(actual - approximate);
}

float getRelativeError(float actual, float approximate)
{
    return getAbsoluteError(actual, approximate) / actual;
}

float getPercentageError(float actual, float approximate)
{
    return (getAbsoluteError(actual, approximate) / actual) * 100;
}

int main()
{
    float approximate;
    float actual = sqrt(2);

    printf("Input the approximate value of under root 2 : ");
    scanf("%f", &approximate);

    float absoluteError = getAbsoluteError(actual, approximate);
    float relativeError = getRelativeError(actual, approximate);
    float percentageError = getPercentageError(actual, approximate);

    printf("Absolute Error : %f\n", absoluteError);
    printf("Relative Error : %f\n", relativeError);
    printf("Percentage Error : %f\n", percentageError);

    return 0;
}
