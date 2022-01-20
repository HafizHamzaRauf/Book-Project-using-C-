#ifndef CD_H
#define CD_H
#include "Media.h"

class CD :public Media
{

	int  capacity;
public:
	CD(String, int);
	void setCapacity(int);
	int getCapacity()const;
	virtual void display();
	virtual Media* clone();
};
#endif // !CD_H

