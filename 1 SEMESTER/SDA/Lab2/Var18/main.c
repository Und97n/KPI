#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main()
{
    int n;
    double s= 1, ts;
    printf("Enter n : ");
    scanf("%d",&n);

    for(int i = 1; i<=n; i++){
        ts = 0;
        for(int j = 1; j<=i; j++){
            ts+= j + sin(j);
        }
        s *= ts/((i*i)+1);
    }
    printf("S = %.7f\n",s);


    return 0;
}
