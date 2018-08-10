#include "m1.h"


Vg1 = 0;
void s1(){
    printf("s1 start\n");
    s2();
    printf("s1 end\n");
}

void s2(){
    printf("s2 start\n");
    Vg1++;
    s3();
    if(Vg1 < 3){
        s6();
    }
    printf("s2 end\n");
}

void s3(){
    printf("s3 start\n");

    printf("s3 end\n");
}
