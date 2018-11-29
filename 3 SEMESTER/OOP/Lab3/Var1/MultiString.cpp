#include "MultiString.h"
#include <cstdlib>
#include <cstring>
#include <iostream>



MultiString::MultiString(){
	str_nmb = 0;
	buf = 0;
}

MultiString::MultiString(int n){
	SetSize(n);
	for(int i = 0;i<n;i++){
		buf[i] = (char*)malloc(sizeof(char));
		buf[i][0] = '\0';
	}
	lastset = -1;
}

MultiString::~MultiString(){
	Empty();
}

MultiString & MultiString::operator+=(const MultiString & other){
	int msize = (Getlength() > other.Getlength())?other.Getlength():Getlength();

	for(int i = 0;i<msize;i++){
		char* tmp = other[i];
		buf[i] = (char*)realloc(buf[i],(strlen(buf[i])+strlen(tmp)+1)*sizeof(char));
		strcat(buf[i],tmp);
		free(tmp);
	}
	return *this;
}

char* MultiString::operator[](int i) const{
	if(i < 0 || i >= str_nmb) throw "Bad index";

	char* tmp = (char*)malloc((strlen(buf[i]) + 1) * sizeof(char));
	strcpy(tmp, buf[i]);
	return tmp;
}

void MultiString::MergeMultiStringexclusive(const MultiString & other){
	for(int i =0;i<other.Getlength();i++){
		char* tmp = other[i];
		if(Find(tmp) == -1){
			if(lastset == str_nmb-1)
				SetSize(++str_nmb);
			Setat(++lastset,tmp);
		}
		free(tmp);
	}
	
}

void MultiString::PrintAll() const{

	for(int i =0;i<Getlength();i++){

		std::cout << i <<" - "<<((buf[i]==0)?"":buf[i])<<std::endl;
	}
}

MultiString & MultiString::operator=(const MultiString &ms){
	Empty();
	SetSize(ms.Getlength());
	for(int i = 0; i< ms.Getlength();i++){
		Setat(i,ms[i]);
	}
	return *this;
}

int MultiString::Getlength() const{
	return str_nmb;
}

int MultiString::Find(const char *pszsub ) const{
	if(pszsub == 0) throw "Bad pointer";
	for(int i =0;i<str_nmb;i++){
		if(strcmp(pszsub, buf[i]) == 0) return i;
	}
	return -1;
}

void MultiString::Setat( int nindex, const char* str ){
	if(str == 0) throw "Bad pointer";
	if(nindex < 0 || nindex >= str_nmb) throw "Bad index";
	buf[nindex] = (char*)realloc(buf[nindex],(strlen(str) + 1) * sizeof(char));
	strcpy(buf[nindex],str);
	if(nindex > lastset) lastset = nindex;
}

void MultiString::Printstr(int nindex) const{
	if(nindex < 0 || nindex >= str_nmb) throw "Bad index";
	std::cout << buf[nindex] << std::endl;
}

void MultiString::Empty(){
	for(int i = 0;i<str_nmb;i++){
		free(buf[i]);
	}
	free(buf);
	buf = 0;
	str_nmb = 0;
	lastset = 0;
}

void MultiString::SetSize(int n){
	str_nmb = n;
	buf = (char**)realloc(buf,sizeof (char*) * n);

}




