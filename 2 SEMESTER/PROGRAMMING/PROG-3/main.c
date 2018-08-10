#include <stdio.h>
#include <stdlib.h>


void fillfile(char name[], char content[]){
    FILE* f = fopen(name,"wb");
    for(int i=0;content[i];i++){
        fwrite(&content[i],sizeof(char),1,f);
    }
    fclose(f);
}

void printfile(char name[]){
    FILE* f = fopen(name,"rb");
    char c;
    while(!feof(f)){
        fread(&c,1,1,f);
        if(feof(f)) break;
        printf("%c",c);
    }
    printf("\n============\n");
    fclose(f);

}

int should_swap(FILE* f,int i){
    fseek(f,i,SEEK_SET);
    char c1 ,c2;
    fread(&c1,1,1,f);
    fread(&c2,1,1,f);
    return c1 > c2;
}

void swap(FILE* f, int i){
    fseek(f,i,SEEK_SET);
    char c1 ,c2;
    fread(&c1,1,1,f);
    fread(&c2,1,1,f);
    fseek(f,i,SEEK_SET);
    fwrite(&c2,1,1,f);
    fwrite(&c1,1,1,f);
}

void sortline(FILE* f,int start, int end){
    for(int j = start;j<end;j++){
        for(int i = start;i<end-1;i++){
            if(should_swap(f,i)){
                swap(f,i);
            }
        }
    }

}

void sortfile(char name[]){
    FILE* f = fopen(name,"rb+");

    int start = 0,i = 0,end=0;
    char c;
    while(!feof(f)){
        fread(&c,1,1,f);
        if(feof(f)) break;
        if(c == '\n'){
            end = i;
            sortline(f,start,end);
            start = end+1;
            fseek(f,i+1,SEEK_SET);
        }
        i++;
    }
    sortline(f,start,i);
    fclose(f);
}

int main()
{
    fillfile("file","agadasdasd\nasdasdasdsdfad\nooqwopeimcbasd\niwlerjanamdnad");
    printfile("file");
    sortfile("file");
    printfile("file");
    return 0;
}
