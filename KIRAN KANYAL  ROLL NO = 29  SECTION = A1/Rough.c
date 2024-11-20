#include<stdio.h>
#include<math.h>
int main(){
    int n;
    scanf("%d", &n);
    int x[n];
    int y[n][n]; // (take input)
    for (int j=1; j<n; j++){
        for (int i=n-1;i>=j;i--){
            y[i][j] = y[i][j-1]-y[i-1][j-1];
        }
    }
    float xPredict;
    float u = (xPredict- x[n-1])/(abs(x[n-1]-x[n-2]));
    int fact = 1;
    float res = y[n-1][0];
    float uValue = 1;
    for (int i=1; i<n; i++){
        fact=fact*i;
        uValue = uValue*(uValue +i-1);
        res += (y[n-1][i]*uValue)/fact;
    }
}