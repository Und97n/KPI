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
            A[i][j] = floorf(((float)rand()/(float)(RAND_MAX)) * 1.0 * 10) / 10;
        }
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<n;j++){
            printf("%.1f ",A[i][j]);
        }
        printf("\n");
    }
    printf("\nВведiть Х:\n");
    float x;
    scanf("%f",&x);

    int resulti = -1, resultj = -1;
    for(int j = 0;j < n;j++){
        for(int i = 0; i < m; i++){
            if(A[i][j] == x){
                resulti = i;
                resultj = j;
                printf("Знайдено: %d %d\n",resulti, resultj);
            }
        }
    }
    if(resulti==-1){
        printf("Не знайдено\n");
   }

    return 0;
}
