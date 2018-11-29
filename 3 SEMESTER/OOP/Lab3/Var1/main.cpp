
#include <iostream>
#include "MultiString.h"


using namespace std;

int main(){
	cout << "Creating two MultiStrings" << endl;
	MultiString a(5);
	MultiString b(10);
	cout << "A:" << endl;
	a.PrintAll();
	cout << "B:" << endl;
	b.PrintAll();
	cout << "Setat" << endl;
	a.Setat(0,"Zero");
	a.Setat(1,"One");
	a.Setat(1,"Two");
	b.Setat(0,"Hello");
	b.Setat(1,"World");
	b.Setat(1,"Two");
	cout << "A:" << endl;
	a.PrintAll();
	cout << "B:" << endl;
	b.PrintAll();
	cout << "Mergeexcluseive" << endl;
	a.MergeMultiStringexclusive(b);
	cout << "A:" << endl;
	a.PrintAll();
	cout << "B:" << endl;
	b.PrintAll();
	cout << "a+=b" << endl;
	a+=b;
	a.PrintAll();
	cout << "B:" << endl;
	cout << "b.Printstr(0)" << endl;
	a.Printstr(0);
	cout << "Find two in B:" << b.Find("Two") << endl;	
	b.Empty();
	cout << "B emptied, b.Isempty() = " << b.Isempty() << endl;
	cout << "B:" << endl;
	b.PrintAll();




}
