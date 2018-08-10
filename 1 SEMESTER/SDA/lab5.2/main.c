#include <stdio.h>
#include <stdlib.h>
#include <time.h>




int main()
{
    int m = 6, n = 6;

    float A[m][n];
    srand(time(0));
    for(int i=0; i<m; i++){
        for(int j=0; j<n;j++){
            A[i][j] = floorf(((float)rand()/(float)(RAND_MAX)) * 1.0 * 10) ;
        }
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<n;j++){
            printf("%.1f ",A[i][j]);
        }
        printf("\n");
    }

    int maxi = 0,mini = 0;
    for(int i = 1;i < n;i++){
        if(A[i][i] >= A[maxi][maxi]){
            maxi = i;
        }
        if(A[i][n-1-i] < A[mini][n-1-mini]){
            mini = i;
        }
    }
    float t = A[maxi][maxi];
    A[maxi][maxi] = A[mini][n-1-mini];
    A[mini][n-1-mini] = t;
    printf("\n");
    for(int i=0; i<m; i++){
        for(int j=0; j<n;j++){
            printf("%.1f ",A[i][j]);
        }
        printf("\n");
    }
    return 0;
}
