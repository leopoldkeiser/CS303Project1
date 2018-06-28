#include "Book.h"
#include "Employee.h"
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

Book::Book(string book_name) :archived(true), title(book_name)
{

}

Book::~Book()
{

}

// Getters and Setters
string Book::getTitle() 
{ 
	return title; 
}

void Book::setTitle(string book_name)
{
	title = book_name;
}

bool Book::get_archived()
{
	return archived;
}

void Book::set_archived(bool b)
{
	archived = b;
}

Date Book::get_start_circulation()
{
	return start_circulation;
}

void Book::set_start_circulation(Date date)
{
	start_circulation = date;
}

Date Book::get_end_circulation()
{
	return end_circulation;
}

void Book::set_end_circulation(Date date)
{
	end_circulation = date;
}

bool Book::empty() 
{ 
	return employee_queue.empty();
}

// push employee to the priority queue of book.
void Book::push(Employee* employee)
{
	employee_queue.push_back(employee);
}

// Pop the first employee of priority queue
void Book::pop()
{
	employee_queue.pop_front();
}

// sort the employee queue according the priority of waiting_time – retaining_time
void Book::sort()
{
	employee_queue.sort([](Employee * lhs, Employee * rhs)
	{ return (lhs->get_waiting_time() - lhs->get_retaining_time()) > (rhs->get_waiting_time() - rhs->get_retaining_time()); });
}

// update the retaining time and waiting time of employee in the queue
void Book::update(int days)
{
	list<Employee*> ::iterator iter;
	for (iter = employee_queue.begin(); iter != employee_queue.end(); ++iter)
	{
		if (iter == employee_queue.begin())
		{
			(*iter)->updayte_retaining_time(days);
		}
		else
		{
			(*iter)->update_waiting_time(days);
		}
	}
}

// Print the book 
void Book::print()
{
	sort();
	cout << setiosflags(ios::left) << setw(12) << "Employee" << setw(20) << "Retaining Time" << setw(20) << "Waiting Time" << endl;
	list<Employee*> ::iterator iter;
	for (iter = employee_queue.begin(); iter != employee_queue.end(); ++iter)
	{
		cout << setiosflags(ios::left) << setw(12) << (*iter)->get_name() << setw(20) << (*iter)->get_retaining_time() << setw(20) << (*iter)->get_waiting_time() << endl;
	}
	cout << endl;
}