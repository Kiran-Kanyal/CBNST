// WAP TO IMPLEMENT LAGRANGES THEOREM 
#include<stdio.h>
int main(){
    int n;
    printf("Enter the number of observations: ");
    scanf("%d",&n);
    float x[n];
    float y[n];
    printf("Enter x & y for %d observations: \n",n);
    for (int i=0; i<n; i++){
        scanf("%f%f", &x[i], &y[i]);
    }
    float xPredict;
    printf("Enter the point at which you want to find the value: ");
    scanf("%f",&xPredict);
    float res = 0;
    for (int i=0; i<n; i++){
        float numerator = 1;
        float denominator = 1;
        for (int j=0; j<n; j++){
            if (i==j) continue;
            numerator *= (xPredict-x[j]);
            denominator *= (x[i]-x[j]);
        }
        res += (numerator/denominator)*y[i];
    }
    printf("Predicted Value: %f",res);
}