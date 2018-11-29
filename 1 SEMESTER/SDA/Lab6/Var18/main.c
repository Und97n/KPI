#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void gotoXY(int XPos, int YPos)
{
 printf("\033[%d;%dH", YPos, XPos);
}

int main()
{
    /*int x = 79, y = 1;
    int speed = 1;

    while(x!= 1 || y!=23){
            x+=speed;
            y+=speed;

        if(x==1 && speed < 0) {speed = -speed;gotoXY(x,y); printf("*"); y+=1; gotoXY(x,y); printf("*"); y+=1;}
        if(x == 80 && speed > 0) {speed = -speed;gotoXY(x,y); printf("*"); y+=1; gotoXY(x,y); printf("*"); y+=1;}
        if(y==1 && speed < 0) {speed = -speed; gotoXY(x,y); printf("*");x-=1; gotoXY(x,y); printf("*"); x-=1;}
        if(y == 24 && speed > 0) {speed = -speed;gotoXY(x,y); printf("*"); x-=1; gotoXY(x,y); printf("*"); x-=1;}

        gotoXY(x,y);
        printf("*");
        fflush(stdout);
        usleep(100000);*/
int x=28;
int i,j;
     for( i = 1 ; i < 12; i++){
     for( j = x ; j < 80; j++){
     gotoXY(j,i);
     printf("*");
     fflush(stdout);
     usleep(100000);
    }
    x++;
    i++;
    for( j = 79; j >= x; j--){
    gotoXY(j,i);
    printf("*");
    fflush(stdout);
    usleep(100000);}
    x++;
    }


    return 0;
}
