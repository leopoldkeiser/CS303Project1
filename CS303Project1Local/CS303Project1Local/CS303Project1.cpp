// CS303Project1.cpp : Defines the entry point for the console application.

#include "Employee.h"
#include "Book.h"
#include "Library.h"
#include "Date.h"
#include "StringTokenizer.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	Library library;
	// Add book to the library.
	library.add_book("Software Engineering");
	library.add_book("Chemistry");

	// Add employee to the employee_database of library.
	library.add_employee("Adam");
	library.add_employee("Sam");
	library.add_employee("Ann");

	// Start circulate the book.
	library.circulate_book("Chemistry", Date(2015, 3, 1));
	library.circulate_book("Software Engineering", Date(2015, 4, 1));

	// Pass the book on to the next employee on the queue on a given date.
	library.pass_on("Chemistry", Date(2015, 3, 5, DateFormat::US)); 
	library.pass_on("Chemistry", Date(2015, 3, 7, DateFormat::US));
	library.pass_on("Chemistry", Date(2015, 3, 15, DateFormat::US)); 

	// print current information of the library
	library.print();

	library.pass_on("Software Engineering", Date(2015, 4, 5, DateFormat::US));
	library.pass_on("Software Engineering", Date(2015, 4, 10, DateFormat::US));
	library.pass_on("Software Engineering", Date(2015, 4, 15, DateFormat::US));

	// print current information of the library
	library.print();

	system("pause");
	return 0;
}

