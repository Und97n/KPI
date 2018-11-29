#include <stdio.h>
#include <stdlib.h>

#include <time.h>

void SetCurPos(int XPos, int YPos){
printf("\033[%d;%dH", YPos, XPos);
}

int main()
{
    int i=0;
    while (i<12){
        int j;
        for (j=1; j<=80; j++){
            SetCurPos(j, 12-i);
            printf("*");
            SetCurPos(81-j, 13+i);
            printf("*");
            usleep(5000);
            fflush(stdout);
        }
        i++;
        for (j=80; j>=1; j--){
            SetCurPos(j, 12-i);
            printf("*");
            SetCurPos(81-j, 13+i);
            printf("*");
            usleep(5000);
            fflush(stdout);
        }
        i++;
    }
    SetCurPos(1,25);

    return 0;
}
