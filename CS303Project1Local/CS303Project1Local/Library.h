#ifndef LIBRARY_H
#define LIBRARY_H

#include <list>
#include "Date.h"
#include "Book.h"
#include <string>
using namespace std;

class Library
{
public:
	// Constructor
	Library();
	~Library();

	// Add book to the library.
	void add_book(string book_name);
	// Add employee to the employee_database of library.
	void add_employee(string employee_names);
	// Start circulate the book.
	void circulate_book(string book_name, Date circulate_date);
	// Pass the book on to the next employee on the queue on a given date.
	void pass_on(string book_name, Date date);
	// print the library
	void print();

private:
	list<Book> circulated_books;
	list<Book> archived_books;
	list<Employee> employee_database;
}; 
#endif