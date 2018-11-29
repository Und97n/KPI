#define _CRT_SECURE_NO_WARNINGS /
#include <stdio.h>

int main()
{

    float *a = malloc(sizeof(float)*10);

    for(int i=0;i<10;i++) a[i] = (0.5*i)-2.5;
    for(int i=0;i<10;i++) printf("%f ",a[i]);
    float sum = 0;
    int s = 0;
    for(int i=0;i<10;i++) {
        if(a[i]<-1) sum+=a[i];
        if(a[i]<-1 || a[i]>1) s++;
    }
    float *b = malloc(sizeof(float)*s);
    int j =0;
    for(int i=0;i<10;i++){
        if(a[i]<-1 || a[i]>1){
         b[j] = a[i];
         j++;
         }
    }
    free(a);
    a = b;
    printf("\n\nSum = %f\n\n",sum);
    for(int i=0;i<s;i++) printf("%f ",a[i]);


  return 0;
}
