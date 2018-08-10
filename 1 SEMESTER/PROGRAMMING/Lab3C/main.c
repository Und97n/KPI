#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define n 9



void fill(int arr[n][n]){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            arr[i][j] = 2.758*i*i - 1.5*j - abs(3.3 - i);
        }
    }
}

void printarr(int arr[n][n]){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            printf("%3d ",arr[i][j]);
        }
        printf("\n");
    }
    printf("===================\n");
}

void printvector(int vector[n]){
    for(int i = 0;i<n;i++){
        printf("%3d ",vector[i]);
    }
    printf("\n===================\n");
}


void makevektor(int arr[n][n], int vector[n]){

    for(int j = 0; j < n; j++){
        for(int i = 0; i < n; i++){
            for(int k = 0; k < n-1; k++){
                if(arr[k][j] < arr[k+1][j]){
                    int t = arr[k][j];
                    arr[k][j] = arr[k+1][j];
                    arr[k+1][j] = t;
                }
            }
        }
    }
    for(int i = 0;i<n;i++){
        vector[i] = arr[n-1][i];
    }

}

float g(int V[n]){
    float s = 0;
    for(int i = 0;i<n;i++){
        s+= sqrt(abs(abs(V[i]+1)-10));
    }
    return s;
}

int main()
{
    int A[n][n];
    int V[n];

    fill(A);
    printf("Вихiдна матриця:\n");
    printarr(A);

    makevektor(A,V);
    printf("Перетворена матриця:\n");
    printarr(A);
    printf("Вектор:\n");
    printvector(V);

    float s = g(V);
    printf("G(x) = %f\n",s);


    return 0;
}
