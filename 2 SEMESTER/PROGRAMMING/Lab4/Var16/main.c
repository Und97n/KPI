#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double f(double x){
    return sqrt(log(x)+tan(x)+2.17)*sin(x);
}

double quadraturna_formula(double a, double b, int n, double(*func)(double)){

    double h = (b-a)/(double)n;
    double sum,x;
    for(int i=0;i<n;i++){
        x = a+(i)*h;
        sum+=func(x);
    }
    return sum*h;
}


int main()
{
    double a=0.2, b=1.3;
    int n = 10;
    double I,prevI = quadraturna_formula(a,b,n,f);
    double err = 999999;
    printf("\n");
    while(err>0.001){
        n*=2;
        printf("%c",0);
        I = quadraturna_formula(a,b,n,f);
        err = fabs(I - prevI)/3.0;
        prevI = I;
    }

    printf("I = %lf\n",prevI);

    return 0;
}
