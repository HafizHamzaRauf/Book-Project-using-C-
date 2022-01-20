#ifndef SHELF_H
#define SHELF_H
#include "Media.h"

class Shelf
{
private:
	Media** items;
	int maxSize;
	int CurSize=0;
public:
	Shelf(int);
	void insert(Media*);
	void displayContents();
	~Shelf();
};
#endif // !SHELF_H

