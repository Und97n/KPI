#include "cArray.h"



cArray::cArray(void){
	allocated = 0;
	size = 0;
	data = 0;
}
cArray::~cArray(void){
	if(data != 0)
		free(data);
}

void cArray::grow(){
	allocated+=GROWBY;
	data = (int*)std::realloc(data,allocated*sizeof(int));
}

void cArray::print(){
	std::cout << "cArray of size: " << Getcount() << " and capacity: " << Getsize() << " upper bound: " << Getupperbound() <<std::endl;
	std::cout << "{";
	if(size == 0){
		std::cout << " }" << std::endl;
		return;
	}
	for(int i = 0; i< size-1;i++){
		std::cout << data[i] << ",";
	}
	std::cout << data[size-1] << "}" << std::endl;
}

int cArray::Getsize() const{
	return allocated;
}
int cArray::Getcount() const{
	return size;
}
int cArray::Getupperbound() const{
	return size-1;
}
bool cArray::IsEmpty() const{
	return size == 0;
}
void cArray::SetSize( int nnewsize ){
	allocated = nnewsize;
	data = (int*)std::realloc(data,allocated*sizeof(int));
	if(size > allocated){
		size = allocated;
	}
}
void cArray::FreeExtra(){
	if(size < allocated){
		allocated = size;
		data = (int*)std::realloc(data,allocated*sizeof(int));
	}
}
void cArray::RemoveAll(){
	size = 0;
}
int cArray::GetAt(int i) const{
	if(i < 0 || i >= size){
		throw "cArray out of bounds exception";
	}
	return data[i];
}
void cArray::SetAt(int n, int indx){
	data[indx] = n;
}
void cArray::Add(int n){
	std::cout << "Add "<<n<<std::endl;
	if(size >= allocated){
		grow();
	}
	data[size] = n;
	size++;
}
void cArray::Append(cArray * from){
	for(int i=0;i<from->Getcount();i++){
		Add(from->GetAt(i));
	}
}
void cArray::Copy(cArray * from){
	if(from->allocated > allocated){
		allocated = from->allocated;
		free(data);
		data = (int*)malloc(allocated*sizeof(int));
	}
	size = from->size;
	for(int i = 0;i < size;i++){
		data[i] = from->GetAt(i);
	}
}
void cArray::InsertAt(int n, int indx){
	if(indx > size) return;
	if(size == allocated) grow();
	size++;
	for(int i = size-1;i>indx;i--){
		data[i] = data[i - 1];
	}
	data[indx] = n;

}
void cArray::RemoveAt(int n ){
	for(int i = n;i<size-1;i++){
		data[i] = data[i+1];
	}
	size--;
}
int& cArray::operator [](int i){
	return data[i];
}
