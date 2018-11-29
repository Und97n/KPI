#include "./argz.h"

error_t argz_create_sep(const char *string, int sep, char **argz, size_t *argz_len){
		if(string == 0 || argz_len == 0 || argz == 0){
			return ERROR;
		}
		*argz_len = strlen(string) +1;
		char* tmp = (char*)malloc(sizeof(char)*(*argz_len));
		

		for(int i = 0;i<*argz_len;i++){
			if(string[i] == sep){
				tmp[i] = 0;
			}else{
				tmp[i] = string[i];
			}
		}
		*argz = tmp;
		return OK;
}

size_t argz_count(const char *argz, size_t arg_len){
	size_t counter = 0;
	for(int i = 0;i<arg_len;i++){
		if(argz[i] == 0){
			counter++;
		}
	}
	return counter;
}

error_t argz_add(char **argz, size_t *argz_len, const char *str){
	if(argz == 0 || *argz == 0 || str == 0 || argz_len == 0){
		return ERROR;
	}


	char* new_argz = (char*)malloc(sizeof(char) * (*argz_len + strlen(str)+1));
	memcpy(new_argz,*argz,sizeof(char) * (*argz_len));
	memcpy(new_argz+(*argz_len),str,sizeof(char)*(strlen(str) + 1));

	*argz_len += strlen(str) + 1;
	
	free(*argz);
	*argz = new_argz;
	return OK;
}

	
char* argz_next(char *argz, size_t argz_len, const char *entry){
	if(entry == 0){
		return argz;
	}
	char* tmp = entry;
	tmp+=strlen(tmp)+1;
	if(tmp - argz >= argz_len){
		return 0;
	}else{
		return tmp;
	}

}
void argz_delete(char **argz, size_t *argz_len, char *entry){
	if(argz == 0 || *argz == 0 || argz_len == 0 || entry == 0){
		return;
	}
	char* tmp = (char*)malloc(sizeof(char) *(*argz_len - strlen(entry)));
	char* ent = 0;
	size_t newlen = 0;
	while( ent = argz_next(*argz,*argz_len,ent)){
		if(strcmp(ent, entry)){
			memcpy((tmp + newlen),ent,strlen(ent)+1);
			newlen += strlen(ent)+1;
			
		}
	}
	free(*argz);
	*argz = tmp;
	*argz_len = newlen;
}


error_t argz_insert (char **argz, size_t *argz_len, char *before, const char *entry){

	if(argz == 0 || *argz == 0 || argz_len == 0 || entry == 0 ||
			before < *argz ){
		return ERROR;
	}
	if(before == 0){
		argz_add(argz,argz_len,entry);
		return OK;
	}

	char* tmp = (char*)malloc(sizeof(char) * (*argz_len + strlen(entry)+1));

	char* ent = 0;
	size_t newlen = 0;

	while(ent = argz_next(*argz, *argz_len, ent)){
		if(!strcmp(ent, before)){
			memcpy(tmp + newlen,entry,strlen(entry)+1);
			newlen+=strlen(entry)+1;
		}
		memcpy(tmp + newlen,ent,strlen(ent)+1);
		newlen+=strlen(ent)+1;

	}
	free(*argz);
	*argz = tmp;
	*argz_len = newlen-1;
	return OK;


}


error_t argz_replace (char **argz, size_t *argz_len, const char *str, const char *with){
	if(argz == 0 || *argz == 0 || str == 0 || with == 0){
		return ERROR;
	}
	size_t newsize = sizeof(char) * (*argz_len - strlen(str) + strlen(with)+1);
	char* tmp = (char*)malloc(newsize);
	if(tmp == 0){
		return ERROR;
	}
	char* ent = 0;
	size_t newlen = 0;
	int replaced = 0;
	while(ent = argz_next(*argz, *argz_len, ent)){
		if(!strcmp(ent,str)){
			memcpy(tmp + newlen, with, strlen(with)+1);
			newlen+= strlen(with)+1;
			replaced = 1;
			break;
		}else{
			memcpy(tmp + newlen, ent, strlen(ent)+1);
			newlen+= strlen(ent)+1;
		}
	}
		
		if(!replaced){
			free(tmp);
			return ERROR;
		}
		free(*argz);
		*argz = tmp;
		*argz_len = (int)newlen;
		return OK;

}


void argz_print(const char *argz, size_t argz_len){
	char* ent = 0;
	while(ent = argz_next((char*)argz, argz_len, ent)){
			printf("%s<0>\n",ent);
	}
}
			


