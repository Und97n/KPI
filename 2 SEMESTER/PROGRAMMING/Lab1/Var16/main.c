#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void fill(int n, FILE* f){
    float k;
    for(int i=1;i<=n;i++){
        k = i*pow(tan(i),i-1);
        fwrite(&k,sizeof(k),1,f);
    }
}

void printfile(int n, FILE *f){
    printf("File contents: ");
    float t;
    while(fread(&t,sizeof(t),1,f)){
        printf("%f ",t);
    }
    printf("\n");
}

float findmin(int n, FILE *f){
    float min,t;
    fread(&min,sizeof(min),1,f);
    while(fread(&t,sizeof(t),1,f)){
        if(t<min) min = t;
    }
    return min;
}

int main()
{
    int n = 30;
    FILE *f = fopen("file","wb");
    fill(n,f);
    fclose(f);
    f = fopen("file","rb");
    printfile(n,f);
    fclose(f);
    f = fopen("file","rb");
    float min = findmin(n,f);
    fclose(f);
    printf("Minimal values is %f\n",min);
    return 0;
}
