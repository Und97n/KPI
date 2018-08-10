#include <stdio.h>
#include <cmath>

using namespace std;

float ctg(float x){
    return cos(x)/sin(x);
}


int main()
{
    float x,y,z,a,b;
    printf("x y z:\n");
    scanf("%f %f %f",&x,&y,&z);

    if(sin(x)==0){
        printf("Zero division\n");
    }else{
    a = 5*ctg(x) - 0.25*atan(y);
    printf("A: %f\n",a);
    }
    float znam = abs(x-y)*abs(x-y)-(z*z);
    if (znam == 0){
        printf("Zero division\n");
    }else if(x<=0){
        printf("Log error\n");
    }else{
        b = (log(x) + abs(x-y) + x*x)/znam;
        printf("B: %f\n",b);
    }


    return 0;
}
