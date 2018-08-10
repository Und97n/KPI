#include <stdio.h>
#include <stdlib.h>

int parse_and_double(char buf[]){
    int t;
    sscanf(buf,"%d",&t);
    return t*2;
}

int should_print(char c){
    return !(c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o' ||
             c == 'A' || c == 'I' || c == 'U' || c == 'E' || c == 'O');
}

int main()
{
    char buf[1024];
    char dbuf[255];
    int dflag = 0;
    int i = 0;
    FILE *f = fopen("file.txt","r");
    while(1){
        char t = fgetc(f);
        if(t == EOF) break;
        printf("%c",t);

        if(isdigit(t)){
            dbuf[dflag] = t;
            dflag++;
        }else{
            if(dflag){ // Double number
                dbuf[dflag] = 0;
                int t = parse_and_double(dbuf);
                sprintf(dbuf,"%d",t);
                for(int j = 0;dbuf[j];j++){
                    buf[i] = dbuf[j];
                    i++;
                }
                dflag = 0;
            }
            if(should_print(t)){
                buf[i] = t;
                i++;
            }

        }


    }
    buf[i] = 0;
    printf("%s",buf);
    fclose(f);
    f = fopen("file.txt","w");
    fputs(buf,f);
    fclose(f);


    return 0;
}
