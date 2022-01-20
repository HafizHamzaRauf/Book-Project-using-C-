#include <iostream>
#include "String.h"
#include "Magzine.h"
#include "Book.h"
#include "Media.h"
#include "CD.h"
#include "Shelf.h"
using namespace std;
/*
int main()
{

	int mediaItems;
	cout << "How many media items you want to create:";
	cin >> mediaItems;
	cout << endl;
	Media** mediaList= new Media*[mediaItems];
	int choice = 0;
	String title, authorName, isbn, month;
	int year, capacity;
	for (int i = 0; i < mediaItems; i++)
	{
		cout << "\n Enter 1 to create an object of Book ";
		cout << "\n Press 2 to create the  object of Magzine ";
		cout <<"\n Press 3 to create an object of CD : ";
		cin >> choice;
		while (choice == 0)
		{
			cout << "\nInvalid choice";
			cout << "\n Enter 1 to create an object of Book and Press 2 to create the  object of Magzine";
			cin >> choice;
		}
		if (choice == 1)
		{
			cin.ignore();
			cout << "\nEnter title of the book:";
			
			cin >> title;
			cout << "\nEnter author Name of the book:";

			cin >> authorName;
			cout << "\nEnter ISBN of the book:";

			cin >> isbn;
			mediaList[i] = new Book(title, authorName, isbn);
		}
		else if(choice==2)
		{
			cout << "\nEnter the name of the magzine:";
			cin.ignore();
			cin >> title;

			cout << "\nEnter the month of the publication of the magzine:";

			cin >> month;
			cout << "\n Enter the year of the publication of the magzine:";
			cin >> year;
			mediaList[i] = new Magzine(title, month, year);
		}
		else
		{
			cout << "\n Enter the name of the CD:";
			cin.ignore();
			cin >> title;
			cout << "\n Enter the capacity of the CD:";
			cin >> capacity;
			mediaList[i] = new CD(title, capacity);
			
		}
	}

	for (int i = 0; i < mediaItems; i++)
	{
		mediaList[i]->display();
	}


	for (int i = 0; i < mediaItems; i++)
	{
		delete  mediaList[i];
		
	}
	delete []mediaList;

	return 0;
}*/

int main()
{
	cout << "Enter how many Media objects you want to create:";
	int noOfItems;
	cin >> noOfItems;
	Shelf mediaList(noOfItems);
	int choice = 0;
	String title, authorName, isbn, month;
	int year, capacity;
	Media**itemsList = new Media*[4];

	for (int i = 0; i < noOfItems; i++)
	{
		cout << "\n Enter 1 to create an object of Book ";
		cout << "\n Press 2 to create the  object of Magzine ";
		cout << "\n Press 3 to create an object of CD : ";
		cin >> choice;
		while (choice == 0)
		{
			cout << "\nInvalid choice";
			cout << "\n Enter 1 to create an object of Book \nPress 2 to create the  object of Magzine \n Press 3 to create the object of CD:";
			cin >> choice;
		}
		if (choice == 1)
		{
			cin.ignore();
			cout << "\nEnter title of the book:";

			cin >> title;
			cout << "\nEnter author Name of the book:";

			cin >> authorName;
			cout << "\nEnter ISBN of the book:";

			cin >> isbn;
			itemsList[i] = new Book(title, authorName, isbn);
			mediaList.insert( itemsList[i]);
		}
		else if (choice == 2)
		{
			cout << "\nEnter the name of the magzine:";
			cin.ignore();
			cin >> title;

			cout << "\nEnter the month of the publication of the magzine:";

			cin >> month;
			cout << "\n Enter the year of the publication of the magzine:";
			cin >> year;
			itemsList[i] = new Magzine(title, month, year);
			mediaList.insert(itemsList[i]);

		}
		else
		{
			cout << "\n Enter the name of the CD:";
			cin.ignore();
			cin >> title;
			cout << "\n Enter the capacity of the CD:";
			cin >> capacity;
			itemsList[i] = new CD(title, capacity);
			mediaList.insert(itemsList[i]);
		}
	}
	mediaList.displayContents();
	for (int i = 0; i < noOfItems; i++)
	{
		delete  itemsList[i];

	}
	delete[]itemsList;
}
