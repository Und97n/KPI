#include <stdio.h>
#include <stdlib.h>
#include <math.h>

    const int n = 10;
    int a = 1, b = 10;

float f(float x){
    if(x>7*a){
        return a/(x+3);
    }else{
        return 6 * b * x;
    }
}



int main()
{
    float temp;
    srand(5);
    float Y[n],Z[n];
    for(int i = 0; i<n; i++){
        Y[i] = (float)rand()/(float)(RAND_MAX) * 20.0; // random float generation
        Z[i] = f(Y[i]);
    }
    float min = Z[0]*a*-1;
    for(int i = 1; i<n;i++){
        temp = pow(-1,i+1)*a*Z[i];
        if(temp<min){
            min = temp;
        }
    }
    printf("%.3f",min);





    return 0;
}
