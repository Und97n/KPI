#include "m2.h"

void s4(){
    printf("s4 start\n");
    s5();
    printf("s4 end\n");
}

void s5(){
    printf("s5 start\n");
    Vg1 = 1;
    s6();
    printf("s5 end\n");
}

void s6(){
    printf("s6 start\n");
    s2();
    printf("s6 end\n");
}

