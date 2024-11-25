// find solution of ODE by Euler's Method.
// example function : dy/dx = x+y
#include<stdio.h>

float f (float x, float y){
    return x + y;
}

int main(){
    float x0,y0,xn,yn;
    int n;
    printf("Enter the initial values of x0 & y0: ");
    scanf("%f%f", &x0,&y0);
    printf("Enter the calculating point (xn): ");
    scanf("%f",&xn);
    printf("Enter the number of steps: ");
    scanf("%d",&n);
    float h = (xn-x0)/n;

    for (int i=0; i<n; i++){
        float slope = f(x0,y0);
        yn = y0 + h*slope;
        x0 += h;
        y0 = yn;
    }
    
    printf("The approximated of f(%f) = %f",xn,yn);
    return 0;
}