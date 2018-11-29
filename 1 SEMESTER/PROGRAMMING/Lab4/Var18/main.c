#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fill(int m, int n, int A[m][n]){
    srand(time(0));
    for(int i = 0;i<m;i++){
        for(int j = 0; j<n; j++){
            A[i][j] = rand()%10;
        }
    }
}

void out(int m, int n, int A[m][n],  char title[255]){
    printf("%s\n",title);
    for(int i = 0;i<m;i++){
        for(int j = 0; j<n; j++){
            printf("%3d ",A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void reverse_columns(int m, int n, int A[m][n]){
    int buf;
    for(int i=0; i<m/2;i++){
        for(int j=0;j<n;j++){
            buf = A[i][j];
            A[i][j] = A[m-i-1][j];
            A[m-i-1][j] = buf;
        }
    }
}

int main()
{
    int m=4,n=7;
    int A[m][n];
    fill(m,n,A);
    out(m,n,A,"Матрица А:");
    reverse_columns(m,n,A);
    out(m,n,A,"Перетворена матриця А:");
    m=7;n=5;
    int B[m][n];
    fill(m,n,B);
    out(m,n,B,"Матриця Б:");
    reverse_columns(m,n,B);
    out(m,n,B,"Перетворена матриця Б:");

    return 0;
}
