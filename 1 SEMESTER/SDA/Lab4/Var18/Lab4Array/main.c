#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define n 3




void swap (int A[n],int a, int b) {
    int B[n];
    for (int i=0; i<n; i++){
        B[i] = A[a*n+i];
    }
    for(int i = 0;i<n;i++){
        A[a*n+i] = A[b*n+i];
    }
    for(int i=0;i<n;i++){
        A[b*n+i] = B[i];
    }
}

void reverse(int A[n], int a){
    int B[n];
    for (int i=0; i<n; i++){
        B[i]=A[(a+1)*n-1-i];
    }
    for (int i=0; i<n; i++){
        A[a*n+i]=B[i];
    }
}

int main()
{
    int A[4*n] ={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    for (int i=0; i<4*n; i++){
        printf("A[%d]=%d ", i, A[i]);
    }
    printf("\n\n");

    swap(A,0,3);
    swap(A,0,1);
    reverse(A,1);
    reverse(A,2);
    reverse(A,3);

    for (int i=0; i<4*n; i++){
        printf("A[%d]=%d ", i, A[i]);
    }

    return 0;
}
