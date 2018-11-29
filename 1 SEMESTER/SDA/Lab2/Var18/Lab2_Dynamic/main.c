#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main()
{
    int n;
    double s= 1,ch=0 ;
    printf("Enter n : ");
    scanf("%d",&n);

    for(int i = 1; i<=n; i++){
        ch+=i+sin(i);
        s *= ch/((i*i)+1);
    }
    printf("S = %.7f\n",s);


    return 0;
}
