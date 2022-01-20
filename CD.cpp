#include <iostream>
#include "Media.h"
#include  "CD.h"
using namespace  std;
CD::CD(String titl, int cap) :Media(titl), capacity(cap)
{

}
void CD::setCapacity(int cap)
{
	if (cap < 0)
	{
		capacity = 0;
	}
	else
	{
		capacity = 0;
	}
}
int CD::getCapacity()const
{
	return capacity;
}
void CD::display()
{
	cout << "\nTitle :" << getTitle();
	cout << "\n Capacity in MBs: " << getCapacity();
}
Media* CD::clone()
{
	return new CD(*this);
}