// 15. WAP to Integrate numerically using Simpson’s 3/8 rules.
#include<stdio.h>
#include<math.h>
float f(float x){
    return 1/(1 + pow(x,2));
}
int main(){
    int n;
    do {
        printf("Enter the number of intervals: ");
        scanf("%d",&n);
        if (n%3!=0){
            printf("Number of intervals should be multiple of 3.\n");
        }
    }while (n%3!=0);
    float a,b;
    printf("Enter the limits: ");
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
        else if (i%3==0){
            res += 2*y[i];
        }
        else{
            res+= 3*y[i];
        }
    }
    res = res*(3*h/8);
    printf("Result using Simpson's 3/8 formula = %f",res);
}