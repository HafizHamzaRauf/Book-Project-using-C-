#ifndef MEDIA_H
#define MEDIA_H
#include "String.h"
class Media
{
	String title;
public:
	Media(String);
	void setTitle(String);
	String getTitle()const;
	virtual void display() = 0;
	virtual Media* clone() = 0;
};

#endif