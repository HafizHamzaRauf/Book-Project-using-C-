#include <iostream>
#include "Shelf.h"
#include "Media.h"
#include "Magzine.h"
#include "Book.h"
#include "CD.h"
#include "String.h"
using namespace std;
Shelf::Shelf(int size)
{
	maxSize = size;
	items = new Media * [maxSize];

}
void Shelf::insert(Media*p)
{

	items[CurSize] = p->clone();
	CurSize++;
}
void Shelf::displayContents()
{
	for (int i = 0; i < CurSize; i++)
	{
		items[i]->display();
	}

}
Shelf::~Shelf()
{
	for (int i = 0; i < CurSize; i++)
	{
		delete items[i];
	}
	delete[] items;

}
