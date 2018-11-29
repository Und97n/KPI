#include <stdio.h>
#include <cmath>
using namespace std;



//25 27 28
//a b n =  0 6 7

float f1(float x){


    return pow(2,x-4)-3;

}
float f2(float x){

    return pow(x+9,3/2.0);

}
float f3(float x){

    return (4*exp(-abs(x)))-1;
}


 int main()
{
    float a,b;
    int n;
    //printf("a b n:\n");
    //scanf("%f %f %d",&a,&b,&n);
    a = 0;b=6;n=7;
    float h = (b-a)/n;
    printf("┌───────────────────────────────────────────────────────┐\n");
    printf("│                Функції однієї змінної                 │\n");
    printf("├──────────┬────────────┬──────────┬────────────────────┤\n");
    printf("│ Аргумент │ 2^(x-4)-3  │(x+9)^3/2 │  4e^(-|x|)-1       │\n");
    printf("├──────────┼────────────┼──────────┼────────────────────┤\n");
    for(int i = 0;i<=n;i++){
        float x = a+h*i;
        printf("│ %.2f\t   │   %.2f\t│ %.2f\t   │  %.7f \t│\n",x,f1(x),f2(x),f3(x));
    }
    printf("├──────────┴────────────┴──────────┴────────────────────┤\n");
    printf("│                                  Склав: Потурай КВ-71 │\n");
    printf("└───────────────────────────────────────────────────────┘\n");
    return 0;
}
