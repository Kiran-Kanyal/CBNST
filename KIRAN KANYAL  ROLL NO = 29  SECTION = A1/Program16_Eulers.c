// find solution of ODE by Euler's Method.

#include <stdio.h>
#include <math.h>

float f(float x, float y) {
    if (y + x == 0) { 
        printf("Division by zero encountered at x = %.2f, y = %.2f\n", x, y);
        return 0;
    }
    return (y - x) / (y + x);
}

int main() {
    float x0, y0, h, x_find;
    printf("Enter initial condition x0 & y0: ");
    scanf("%f %f", &x0, &y0);
    printf("Value of x for which you need to find y: ");
    scanf("%f", &x_find);
    printf("Enter step size: ");
    scanf("%f", &h);

    int itr = 1;
    float tolerance = 1e-6; 
    while (fabs(x0 - x_find) > tolerance) {
        float y = y0 + h * f(x0, y0); 
        x0 += h;                      
        y0 = y;                       
        printf("Iteration %d: x = %.4f, y = %.4f\n", itr, x0, y0);
        itr++;
    }
    printf("The approximated value for x = %.2f is y = %.4f\n", x_find, y0);
    return 0;
}
