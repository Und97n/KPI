#include <stdio.h>
#include <stdlib.h>


typedef struct student{
    char Name[255];
    char Adress[255];
    int SDA, MatAn, LinAl;
} student;

void fill(student S[], int n){
    FILE *f = fopen("students.txt","r");
    for(int i = 0;i<n;i++){
        fscanf(f,"%[^,], %[^,],%d, %d, %d\n",S[i].Name,S[i].Adress, S[i].SDA,&S[i].MatAn,&S[i].LinAl);
    }
    fclose(f);
}

int is_in_hostel(student S){
    char t[] = "гурт. 14";
    for(int i=0;i<8;i++){
        if(t[i] != S.Adress[i]){
            return 0;
        }
    }
    return 1;
}

int get_room_number(student S){
    int room;
    sscanf(S.Adress, "%*s %*s %*s %d", &room);
    return room;
}

void print_info(student s){
    int room = get_room_number(s);
    printf("%s - %s\n",s.Name,room);
}

int main()
{
    student S[11];
    fill(S,11);

    for(int i = 0; i<= 1000; i++){
        if(is_in_hostel(S[i])){
            int room = get_room_number(S[i]);
            if(!((room/100)%2)){
                print_info(S[i]);
            }
        }
    }

    return 0;
}
