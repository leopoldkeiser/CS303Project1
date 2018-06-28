#include "Book.h"
#include "Employee.h"
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

Book::~Book()
{
	employee_queue.empty();
}

Book::Book(string book_name) :archived(true), title(book_name)
{

}

string Book::getTitle() 
{ 
	return title; 
}

bool Book::isArchived() 
{ 
	return archived; 
}

bool Book::empty() 
{ 
	return employee_queue.empty();
}

// push employee to the priority queue of book
void Book::push(Employee* employee)
{
	employee_queue.push_back(employee);
}

void Book::set_archived(bool b) 
{
	archived = b; 
}

bool Book::get_archived() 
{ 
	return archived; 
}

void Book::set_start_circulation(Date date) 
{ 
	start_circulation = date; 
}

Date Book::get_start_circulation() 
{ 
	return start_circulation; 
}

void Book::set_end_circulation(Date date) 
{ 
	end_circulation = date; 
}

Date Book::get_end_circulation() 
{ 
	return end_circulation; 
}

void Book::pop()
{
	employee_queue.pop_front();
}

// Print the employee queue of book 
void Book::print_queue()
{
	sort();
	cout << setiosflags(ios::left) << setw(12)<< "Employee" << setw(20) << "Retaining Time" << setw(20) << "Waiting Time" << endl;
	list<Employee*> ::iterator iter;
	for (iter = employee_queue.begin(); iter != employee_queue.end(); ++iter)
	{
		cout << setiosflags(ios::left) << setw(12) << (*iter)->getName() << setw(20) << (*iter)->get_retaining_time() << setw(20) << (*iter)->get_waiting_time() << endl;
	}
	cout << endl << endl;
}

// sort the employee queue according the priority of waiting_time – retaining_time
void Book::sort()
{
	employee_queue.sort([](Employee * lhs, Employee * rhs)
	{ return (lhs->get_waiting_time() - lhs->get_retaining_time()) > (rhs->get_waiting_time() - rhs->get_retaining_time()); });
}

// update the retaining time and waiting time of employee 
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