// WRITE A  PROGRAM TO IMPLEMENT NEWTONS BACKWARD SUBSTITUTION
#include<stdio.h>
#include<math.h>
int main(){
    int n ;
    printf("Enter the no. of observations: ");
    scanf("%d",&n);
    float x[n];
    float y[n][n];
    printf("Enter x and y for %d observations: \n",n);
    for (int i=0; i<n; i++){
        scanf("%f",&x[i]);
        scanf("%f",&y[i][0]);
    }
    for (int j=1; j<n; j++){
        for (int i=n-1; i>=j; i--){
            y[i][j] = y[i][j-1]-y[i-1][j-1];
        }
    }
    printf("Backward Difference Table : \n");
    for (int i=0; i<n; i++){
        for (int j=0; j<=i; j++){
            printf("%.2f\t",y[i][j]);
        }
        printf("\n");
    }
    float xPredict;
    printf("Enter the point at which you want to find the value: ");
    scanf("%f", &xPredict);
    float h = fabs(x[0]-x[1]);
    float u = (xPredict-x[n-1])/h;  // x = a+hu calculating u
    float predictedValue = y[n-1][0];
    float fact = 1;
    float uValue = 1;
    for (int i=1; i<n; i++){
        fact = fact*i;
        uValue = uValue*(u+i-1);
        predictedValue += (uValue*y[n-1][i])/fact;
    }
    printf("Predicted value for %f is %f",xPredict,predictedValue);
    return 0;
}