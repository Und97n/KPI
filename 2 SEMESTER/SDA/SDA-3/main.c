#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float rec_down(int n, int i, float f, float sum){
    sum+=f;
    if(i==n){
        return sum;
    }
    i++;
    f = (2*sqrt(f))+i;

    return rec_down(n,i,f,sum);

}

float rec_up(int i,float* sum){
    if(i==1){
    *sum+=1;
        return 1;
    }
    float f = 2*sqrt(rec_up(i-1,sum)) + i;
    *sum+=f;
    return f;
}

float rec_down_up(int n, int i, float f){
    if(i>n){
        return 0;
    }
    i++;


    return f+rec_down_up(n,i,((2*sqrt(f))+i));
}

int main()
{
    int n;
    scanf("%d",&n);
    float res = rec_down(n,1,1,0);
    printf("Спуск: %f\n",res);
    res = 0;
    rec_up(n,&res);
    printf("Повернення: %f\n",res);
    res = rec_down_up(n,1,1);
    printf("Спуск та повернення: %f",res);
    return 0;
}
