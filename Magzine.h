#ifndef MAGZINE_H
#define MAGZINE_H
#include "Media.h"
#include "String.h"
class Magzine:public Media
{
	String month;
	int year;
public:
	Magzine(String , String ,int );
	virtual void display();
	virtual Media* clone();
	
};
#endif // !MAGZINE_H

