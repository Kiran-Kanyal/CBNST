#include <stdio.h>

float f (float x, float y){
    return (y*y-x*x)/(y*y+x*x);
}
int main() {
    float x0,y0,xn,yn,k1,k2,k3,k4;
    int n;
    printf("Enter the initital values of x0 & y0: ");
    scanf("%f%f",&x0,&y0);
    printf("Enter the calculating point: ");
    scanf("%f",&xn);
    printf("Enter the number of steps: ");
    scanf("%d",&n);
    float h = (xn-x0)/n;
    for (int i=0; i<n; i++){
        k1 = h*f(x0,y0);
        k2 = h*f(x0+h/2,y0+k1/2);
        k3 = h*f(x0+h/2,y0+k2/2);
        k4 = h*f(x0+h,y0+k3);

        yn = y0 + (k1 + 2*k2 + 2*k3 + k4)/6;

        printf("Current iteration %d: x%d = %f & y%d = %f\n",i+1,i,x0,i,y0);
        x0 += h;
        y0 = yn;
    }
    printf("The approximated value of f(%f) = %f",xn,yn);
}
