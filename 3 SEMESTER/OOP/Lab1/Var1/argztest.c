#include "./argz.h"




int main(){

	error_t ok = argz_create_sep(0, 'a',0,0);
	if(ok == ERROR){
		printf("Error catching in argz_create_sep works\n");
	}
	char* argz;
	size_t argz_len;
	ok = argz_create_sep("SHELL=/bin/bash:usr=monty:PWD=/bin/monty:LANG=en_US.UTF-8",':',&argz, &argz_len);
	if(ok == OK && argz_len == 58 && !strcmp(argz,"SHELL=/bin/bash")){
			printf("argz_create_sep works\nState after:\n");
			argz_print(argz, argz_len);
			printf("\n");
	}

	size_t count = argz_count(argz, argz_len);
	if(count == 4){
		printf("argz_count works\nState after:\n");
		argz_print(argz, argz_len);
		printf("\n");
	}
	ok = argz_add(&argz,&argz_len,"TERM=xterm-256");
	if(ok == OK && argz_len == 73 && argz_count(argz, argz_len) == 5){
		printf("argz_add works\nState after:\n");
		argz_print(argz, argz_len);
		printf("\n");
	}
	char* entry1 = argz_next(argz,argz_len,0);
	char* entry2 = argz_next(argz,argz_len,entry1);
	if(!strcmp(entry1,"SHELL=/bin/bash") && !strcmp(entry2,"usr=monty")){
			printf("argz_next works\nState after:\n");
			argz_print(argz, argz_len);
			printf("\n");
	}
	argz_delete(&argz,&argz_len,entry2);
	argz_delete(&argz,&argz_len,argz_next(argz,argz_len,0));
	if(!strcmp(argz,"PWD=/bin/monty")){
		printf("argz_delete works\nState after:\n");
		argz_print(argz, argz_len);
		printf("\n");
	}

	ok = argz_insert(&argz,&argz_len,argz,"FLAG=TRUE");
	if(ok == OK && !strcmp(argz,"FLAG=TRUE")){
			printf("argz_insert works\nState after:\n");
			argz_print(argz, argz_len);
			printf("\n");
	}
	
	ok = argz_replace(&argz, &argz_len, "TERM=xterm-256", "A=B");
	if(ok == OK){
			printf("argz_replace works\nState after:\n");
			argz_print(argz, argz_len);
			printf("\n");
	}

	free(argz);


}
