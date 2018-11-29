#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "scanner.h"

#define tryName(data,str,name) if(!strcmp(str,#name)) return &(data->name);


SCAN_INFO strToScan(char* str){
	SCAN_INFO t;
	char* strtmp = (char*)malloc(sizeof(char)*strlen(str)+1);
	strcpy(strtmp, str);
	char* entry = strtok(strtmp,";");
	strcpy(t.manufacturer, entry);
	entry = strtok(0,";");
	strcpy(t.model, entry);
	entry = strtok(0,";");
	t.year = atoi(entry);
	entry = strtok(0,";");
	t.price = atof(entry);
	entry = strtok(0,";");
	t.x_size = atoi(entry);
	entry = strtok(0,";");
	t.y_size = atoi(entry);

	free(strtmp);	
	return t;
}

RECORD_SET* readFile(FILE* in){
	RECORD_SET* res = (RECORD_SET*)malloc(sizeof(RECORD_SET));
	fread(&(res->rec_nmb),sizeof(int),1,in);
	res->recs = (SCAN_INFO*)malloc(sizeof(SCAN_INFO)*res->rec_nmb);
	fread(res->recs,sizeof(SCAN_INFO),res->rec_nmb,in);
	return res;
}

int getLinesNum(FILE* in){
	int counter = 0;
	while(1){
		char c = getc(in);
		if(c == EOF) break;
		if(c == '\n') counter++;
	}
	rewind(in);	
	printf("Got %d lines",counter);
	return counter;
}

void* getFieldByName(SCAN_INFO* data,char* str){
	tryName(data,str,id);
	tryName(data,str,manufacturer);
	tryName(data,str,year);
	tryName(data,str,model);
	tryName(data,str,price);
	tryName(data,str,x_size);
	tryName(data,str,y_size);
	return 0;
}

int isGreater(SCAN_INFO* a, SCAN_INFO* b,char* field_name){
	if(!strcmp(field_name,"id") ||
			!strcmp(field_name,"year") ||
			!strcmp(field_name, "x_size") ||
			!strcmp(field_name, "y_size")){
		return *((int*) getFieldByName(a,field_name)) > *((int*) getFieldByName(b,field_name));
	}
	if(!strcmp(field_name,"price")){
		return *((float*) getFieldByName(a,field_name)) > *((float*) getFieldByName(b,field_name));
	}
	if(!strcmp(field_name,"model") ||
			!strcmp(field_name,"manufacturer")){
		return strcmp(*(char(*)[127])getFieldByName(a,field_name),*(char(*)[127])getFieldByName(b,field_name)) > 0;
	}

}

int make_index(const char *db, const char *field_name){
	FILE* in = fopen(db,"rb");
	char idx[30];
	strcpy(idx,field_name);
	strcat(idx,".idx");
	FILE* out = fopen(idx,"w");
	if(in == 0 || out == 0){
		return 0;
	}

	RECORD_SET* arr = readFile(in);

	fclose(in);

	for(int i=0;i<arr->rec_nmb;i++){
		for(int j=0;j<arr->rec_nmb-1;j++){
			if(isGreater(&(arr->recs[j]),&(arr->recs[j+1]),field_name)){
				SCAN_INFO t = arr->recs[j];
				arr->recs[j] = arr->recs[j+1];
				arr->recs[j+1] = t;
			}
		}
	}

	for(int i=0;i<arr->rec_nmb;i++){
		fprintf(out,"%d ",arr->recs[i].id);
	}
	free(arr->recs);
	free(arr);
	fclose(out);

	return 1;
}

void create_db(const char* csv, const char *db){
	FILE* in = fopen(csv,"r");
	FILE* out = fopen(db,"wb");
	int lines = getLinesNum(in);
	fwrite(&lines,sizeof(int),1,out);

	for(int i = 0;i<lines;i++){
		char tmp[256];
		fscanf(in,"%[^\n]\n",tmp);
		SCAN_INFO inf = strToScan(tmp);
		inf.id = i;
		fwrite(&inf,sizeof(SCAN_INFO),1,out);
	}
	fclose(in);
	fclose(out);
}


void scanToStr(SCAN_INFO* t, char* tmp){
	sprintf(tmp,"%s;%s;%d;%f;%d;%d;%d",t->manufacturer,t->model,t->year,t->price,t->x_size,t->y_size,t->id);
}

void print_db(const char *db){
	FILE* in = fopen(db,"rb");
	RECORD_SET* rs = readFile(in);

	for(int i =0;i<rs->rec_nmb;i++){
		char tmp[255];
		scanToStr(&(rs->recs[i]),tmp);
		printf("%s\n",tmp);
	}
	printf("\n=======\n");
}

void reindex(const char *db){
	make_index(db,"id");
	make_index(db,"manufacturer");
	make_index(db,"year");
	make_index(db,"model");
	make_index(db,"price");
	make_index(db,"y_size");
	make_index(db,"x_size");
}

void del_scanner(const char *db, int id){
	FILE* in = fopen(db,"rb");
	RECORD_SET* rs = readFile(in);
	fclose(in);
	FILE* out = fopen(db,"wb");
	rs->rec_nmb--;
	fwrite(&(rs->rec_nmb),sizeof(int),1,out);
	for(int i = 0;i<rs->rec_nmb+1;i++){
		if(rs->recs[i].id != id){
			fwrite(rs->recs+i,sizeof(SCAN_INFO),1,out);
		}
	}
	fclose(out);
	free(rs->recs);
	free(rs);
	reindex(db);
}

void add_scanner(const char *db, const char* scanner_str){
	FILE* in = fopen(db,"rb");
	RECORD_SET* rs = readFile(in);
	fclose(in);
	FILE* out = fopen(db,"wb");
	rs->rec_nmb++;
	fwrite(&(rs->rec_nmb),sizeof(int),1,out);
	fwrite(rs->recs,sizeof(SCAN_INFO),rs->rec_nmb-1,out);
	int maxid = -1;
	for(int i =0;i<rs->rec_nmb-1;i++){
		if(rs->recs[i].id > maxid) maxid = rs->recs[i].id;
	}
	SCAN_INFO t = strToScan(scanner_str);
	t.id = maxid+1;
	fwrite(&t, sizeof(SCAN_INFO),1,out);
	fclose(out);
	free(rs->recs);
	free(rs);
	reindex(db);
	
}

int cmp(SCAN_INFO* inf, char* field_name, void* value){
	if(!strcmp(field_name,"id") ||
			!strcmp(field_name,"year") ||
			!strcmp(field_name, "x_size") ||
			!strcmp(field_name, "y_size")){
		return *((int*)getFieldByName(inf,field_name)) == *((int*)value);
	}
	if(!strcmp(field_name,"price")){
		return *((float*)getFieldByName(inf,field_name)) == *((float*)value);
	}
	if(!strcmp(field_name,"model") ||
			!strcmp(field_name,"manufacturer")){
		return strcmp(*(char(*)[127])getFieldByName(inf,field_name),(char*)value) == 0;
	}


}

RECORD_SET* select_db(const char *db, const char *field, const char *value){
	FILE* in = fopen(db,"rb");
	RECORD_SET* ini = readFile(in);
	fclose(in);
	int count = 0;
	for(int i = 0;i<ini->rec_nmb;i++){
		if(cmp(ini->recs+i,field,value)){
			count++;
		}
	}

	RECORD_SET* fin = (RECORD_SET*)malloc(sizeof(RECORD_SET));
	fin->rec_nmb = count;
	fin->recs = (SCAN_INFO*)malloc(sizeof(SCAN_INFO)*count);
	count = 0;
	for(int i = 0;i<ini->rec_nmb;i++){
		if(cmp(ini->recs+i,field,value)){
			fin->recs[count] = ini->recs[i];
			count++;
		}
	}
	free(ini->recs);
	free(ini);
	return fin;
}

void print_rec_set(RECORD_SET *rs){
	for(int i = 0;i<rs->rec_nmb;i++){
		char tmp[255];
		scanToStr(rs->recs+i,tmp);
		printf("%s\n",tmp);
	}
	printf("RECORD SET ENDED\n");
}

RECORD_SET* get_recs_by_index(const char* db, char* field){
	FILE* in = fopen(db,"rb");
	RECORD_SET* rs = readFile(in);
	fclose(in);
	char tmp[30];
	strcpy(tmp,field);
	strcat(tmp,".idx");

	RECORD_SET* res = (RECORD_SET*)malloc(sizeof(RECORD_SET));
	res->rec_nmb = rs->rec_nmb;
	res->recs = (SCAN_INFO*)malloc(sizeof(SCAN_INFO)*rs->rec_nmb);

	FILE* idx = fopen(tmp,"r");
	for(int i=0;i<rs->rec_nmb;i++){
		int x;
		fscanf(idx,"%d",&x);
		for(int j=0;j<rs->rec_nmb;j++){
			if(rs->recs[j].id == x){
				res->recs[i] = rs->recs[j];
				break;
			}
		}
	}
	fclose(idx);
	free(rs->recs);
	free(rs);
	return res;
}


	
