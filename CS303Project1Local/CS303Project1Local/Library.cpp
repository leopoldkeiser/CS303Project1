#include "Library.h"
#include "Book.h"
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

// Constructor
Library::Library()
{
}

Library::~Library()
{
}

// Add book to the library.
void Library::add_book(string book_name)
{
	Book new_book = Book(book_name);
	archived_books.push_back(new_book);
}

// Add employee to the employee_database of library.
void Library::add_employee(string employee_name)
{
	Employee new_employee = Employee(employee_name);
	employee_database.push_back(new_employee);
}

// Start circulate the book.
void Library::circulate_book(string book_name, Date circulate_date)
{
	// Pop the book from archived_books list.
	list<Book> ::iterator iter;
	for (iter = archived_books.begin(); iter != archived_books.end(); ++iter)
	{
		if (iter->getTitle() == book_name) 
		{
			iter->set_archived(false);
			circulated_books.push_back(*iter);
			archived_books.erase(iter);
			break;
		}
	}

	// Update the circulate_date and create the employee queue for the book.
	for (iter = circulated_books.begin(); iter != circulated_books.end(); ++iter)
	{
		if (iter->getTitle() == book_name) {
			iter->set_start_circulation(circulate_date);
			// import employee from employee_database of library to employee_queue of the book .
			list<Employee> ::iterator it;
			for (it = employee_database.begin(); it != employee_database.end(); ++it)
			{
				iter->push(&(*it));
			}
		}
	}
}

// Pass the book on to the next employee on the queue on a given date.
void Library::pass_on(string book_name, Date date)
{
	list<Book> ::iterator iter;
	for (iter = circulated_books.begin(); iter != circulated_books.end(); ++iter)
	{
		if (iter->getTitle() == book_name)
		{
			iter->set_end_circulation(Date(date));
			int days = iter->get_end_circulation() - iter->get_start_circulation();
			iter->set_start_circulation(Date(date));

			iter->sort();
			iter->update(days);
			iter->pop();	

			//If the employee who is passing on the book is the last in the queue, the book gets archived.
			if (iter->empty()) 
			{
				archived_books.push_back(Book(book_name));
				circulated_books.erase(iter);
				return;
			}
			return;
		}
	}
	cout << "Can not find the book:" << book_name << "from archived books of library" << endl << endl;
}

// print the library
void Library::print()
{
	// Print archived books
	cout << "Archived Books:" << endl;
	list<Book> ::iterator iter;
	for (iter = archived_books.begin(); iter != archived_books.end(); ++iter)
	{
		cout << iter->getTitle() << endl;
	}
	cout << endl;

	// Print circulated books
	for (iter = circulated_books.begin(); iter != circulated_books.end(); ++iter)
	{
		cout << "Circulated Books: "<< iter->getTitle() << endl;
		cout << "Waiting list of this book" << endl;
		iter->print();
	}

	// Print employee database of library
	cout << "Employee Database" << endl;
	cout << setiosflags(ios::left) << setw(12) << "Employee" << setw(20) << "Retaining Time" << setw(20) << "Waiting Time" << endl;
	list<Employee> ::iterator it;
	for (it = employee_database.begin(); it != employee_database.end(); ++it)
	{
		cout << setiosflags(ios::left) << setw(12) << it->get_name() << setw(20) 
			<< it->get_retaining_time() << setw(20) << it->get_waiting_time() << endl;
	}
	cout << endl;
}