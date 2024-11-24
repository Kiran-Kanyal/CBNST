//13. WAP to Integrate numerically using Trapezoidal rule.

#include<stdio.h>
#include<math.h>
float f(float x){
    return 1/(1+pow(x,2));
}
#include<stdio.h>
int main(){
    int n;
    printf("Enter the number of intervals: ");
    scanf("%d", &n);
    float a,b;
    printf("Enter the limit: ");
    scanf("%f%f", &a, &b);
    float h = (b-a)/n;
    float y[n+1];
    for (int i=0; i<=n; i++){
        y[i] = f(a+i*h);
    }
    float res = 0;
    for (int i=0; i<=n; i++){
        if (i==0 || i==n){
            res += y[i];
        }
        else {
            res += 2*y[i];
        }
    }
    res = (h/2)*res;
    printf("Result using Trapezoidal formula = %f", res);
    return 0;
}