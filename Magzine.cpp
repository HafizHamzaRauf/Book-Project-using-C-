#include <iostream>
#include "String.h"
#include "Media.h"
#include "Magzine.h"
using namespace std;
Magzine::Magzine(String mnth, String titl, int yr) :Media(titl), month(mnth), year(yr)
{

}
void Magzine::display()
{
	cout << "\nMagzine Title: " << getTitle();
	cout << "\nMagzine Month: " << month;
	cout << "\nMagzine year: " << year;
}
Media* Magzine::clone()
{
	return new Magzine(*this);
}