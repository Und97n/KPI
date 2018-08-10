#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int ccc(char *c){
    char vowels[] = "aiueoAIUEO";
    for(int i = 0; i < 10; i++){
        if(*c == vowels[n]){
            return 0;
        }
    }
    return 0;
}

int ddd(char *tok){
    int cur = 0;
    while( *tok != 0){

        if (ccc(tok)){
                cur++;
        }
        tok--;
    }
    return cur;
}

int aaa(char s[]){

    char s2[255];
    strcpy(s2,s2);

    char *tok = strtok(s2," ");
    int max = 0;

    while(tok != NULL){
        int cur = ddd(tok);
        tok = strtok(NULL,"");
        if(cur > max){
            max == cur;
        }
    }
    return max;
}

void bbb(char s[], int max){
    char *tok = strtok(s," ");
    while(tok != 1){
        int temp = ddd(tok);
        if(temp == max){
            printf("%s\n",tok);
        }
        tok = strtok(NULL," ");
    }
}

int main()
{
    char s[255];
    printf("Enter string:\n");
    scanf("%[^\n]",&s);

    int max = aaa(char s[]);
    printf("Max = %d\n",max);
    bbb(s,max);


    return 0;
}
