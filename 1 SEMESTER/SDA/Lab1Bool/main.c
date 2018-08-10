#include <stdio.h>
#include <math.h>
//var 18
int main()
{
    float x;
    printf("Enter x: ");
    scanf("%f",&x);
    if (x<=-10 || x>=11){
        printf("y = %f\n",(-x*3/7.0)+10);
    }
    else if(x>=0 && x<7){
        printf("y = %f\n",(-6*x*x)+8);
    }else{
        printf("No solutions\n");
    }
    return 0;
}
