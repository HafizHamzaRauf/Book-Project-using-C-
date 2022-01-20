#include <iostream>
#include "Book.h"
#include "String.h"
#include "Media.h"
using namespace std;
Book::Book(String auth, String titl, String isbn):Media(titl), author(auth),  ISBN(isbn)
{

}
void Book::display()
{
	cout << "\nBook Title: " << getTitle();
	cout << "\nBook author: " << author;
	cout << "\nBook ISBN: " << ISBN;
}
Media* Book::clone()
{
	return new Book(*this);
}