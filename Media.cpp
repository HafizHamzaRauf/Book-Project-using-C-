#include <iostream>
#include "String.h"
#include "Media.h"
using namespace std;
Media::Media(String titl):title(titl)
{

}
void Media::setTitle(String a)
{
	title = a;
}
String Media::getTitle()const
{
	return title;
}

