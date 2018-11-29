#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>

void set_cur_pos(int XPos, int YPos)
{
    printf("\033[%d;%dH", YPos, XPos);
}

void print_center(char s[], int line){
    int l = strlen(s);
    set_cur_pos(40-(l+2)/2,line);
    printf("%s",s);
}

void menu(){
    print_center("Лабораторна робота №7",5);
    print_center("Выконав фвофдылвофывфдлыasadasdasdв", 7);

}


int main()
{
initscr();
noecho();
cbreak();
    menu();
    while(1){
        int command = getch();
        if(command != -1)
        printf("%c = %d\n",command,command);
    }
    return 0;
}
