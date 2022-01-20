#ifndef STRING_H
#define STRING_H
#include "String.h"
#include <iostream>

using namespace std;


class String
{
	friend istream& operator >>  (istream& is, String& cString);
	char* data;
	int size;
	int  stringLength(const char*)const;
	void stringCopy(char*, const char*)const;
	void  MyMemCopy(void* des, const void* src, int);
	void  MyMemMove(void*, const void*, int);

public:

	String();
	String(const String&);
	String(const char);
	String(const char*);
	String(String&&);
	~String();
	int getSize()const;
	char& operator[](const int);
	const char& operator[](const int)const;
	void resize(int);
	int getLength()const;
	void reverse();
	bool operator!()const;
	void makeLower();
	void makeUpper();
	void trimRight();
	void trimLeft();
	void trim();
	int find(const String&, const int) const;
	void shrink();
	void insert(const int, const String&);
	void remove(int, int);
	int operator==(const String&)const;
	String  operator+ (const String&) const;
	explicit  operator long long int()const;
	String left(const int);
	String right(const int);
	explicit operator double()const;
	String& operator=(const long long int);
	int replace(const String&, const String&);
	String operator+=(const String&);
	void concatEqual(const String&);
	String& operator=(const String&);
	explicit operator bool()const;
	String operator()(const String&);
	String& operator = (const  double);
	String& operator= (String&&);
};
istream& operator >>  (istream& is, String& cString);
ostream& operator << (ostream& is, const String& cString);

#endif // !STRING

