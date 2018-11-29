/*!
* file: MultiString.h
* MultiString class definition
* written: 01/05/201
* Copyright (c) 2012 by Yu.Zorin
*/
#pragma once
#include <string.h>
#include <stdio.h>
class MultiString{
	public:
		//constructors destructor
		MultiString();
		MultiString(int );
		~MultiString();
		//methods

		MultiString & operator=(const MultiString &ms);
		char * operator[] (int nindex) const;
		MultiString & operator+=(const MultiString &);
		void MergeMultiStringexclusive(const MultiString &);
		int Find(const char *pszsub ) const;
		int Getlength( ) const;
		bool Isempty()const{ return str_nmb == 0;};
		void Empty();
		void Setat( int nindex, const char* str );
		void Printstr(int nindex) const;
		void PrintAll() const;
	private:
		void SetSize(int n);
		//forbidden copy constructor
		MultiString ( const MultiString & ms){};
		//attributes
		char **buf = 0;//pointer to vector
		int str_nmb;//strings number
		int lastset = -1;
};
