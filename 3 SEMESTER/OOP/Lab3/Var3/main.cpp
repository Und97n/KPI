#include "cArray.h"



int main(){


	cArray arr;
	std::cout << "Setting size and adding elements" << std::endl;
	std::cout << "IsEmpty = " << arr.IsEmpty() << std::endl;
	arr.print();
	arr.SetSize(3);
	arr.Add(1);
	arr.Add(2);
	arr.Add(3);
	arr.print();
	arr.Add(4);
	arr.print();
	std::cout << "IsEmpty = " << arr.IsEmpty() << std::endl;
	std::cout << "Checking FreeExtra" << std::endl;
	arr.FreeExtra();
	arr.print();
	std::cout << "arr[" << 2 << "] = " << arr[2] << std::endl;
	arr[2] = 10;
	std::cout << "After arr[2] = 10 : arr[" << 2 << "] = " << arr[2] << std::endl;
	arr.SetAt(11,1);
	std::cout << "After arr.SetAt(11,1) : arr[" << 1 << "] = " << arr[1] << std::endl;
	
	cArray arr2;
	arr2.Add(5);
	arr2.Add(6);
	std::cout << "arr:" << std::endl;
	arr.print();
	std::cout << "arr2:" << std::endl;
	arr2.print();
	std::cout << "After arr2.Append(&arr) arr2:" <<std::endl;
	arr2.Append(&arr);
	arr2.print();
	std::cout << "After arr.Copy(&arr2) arr:" <<std::endl;
	arr.Copy(&arr2);
	arr.print();
	std::cout << "arr.InsertAt(3,0); arr.InsertAt(10,2)" << std::endl;
	arr.InsertAt(3,0); arr.InsertAt(10,2);
	arr.print();
	std::cout << "arr.RemoveAt(1)" << std::endl;
	arr.RemoveAt(1);
	arr.print();
	std::cout << "arr.RemoveAll()" << std::endl;
	arr.RemoveAll();
	arr.print();



	return 0;
}
