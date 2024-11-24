//14. WAP to Integrate numerically using Simpson’s 1/3 rules.
#include<stdio.h>
#include<math.h>
float f(float x){
    return 1/(1+pow(x,2));
}
int main(){
    int n;
    printf("Enter the no. of intervals: ");
    do{
        scanf("%d",&n);
        if (n%2!=0) printf("Number of intervals should be even.\n");
    }while (n%2!=0);
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
        else if (i%2 == 0){
            res += 2*y[i];
        }
        else{
            res += 4*y[i];
        }
    }
    res = res*(h/3);
    printf("Result using Simpson's 1/3 formula = %f",res);
}