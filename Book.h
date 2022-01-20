#ifndef BOOK_H
#define BOOK_H
#include "Media.h"
#include "String.h"
class Book:public Media
{
private:
	String author;
	String ISBN;
public:
	Book(String, String, String);
	Media* clone();
	virtual void display();
	
};
#endif // !BOOK_H

