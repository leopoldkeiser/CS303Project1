#include "Book.h"
#include "Employee.h"
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

// Constructor
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

// Pop the first employee of priority queue and update retaining time and waiting time of employee.
void Book::pop(int days)
{
	// Find the emmployee with the highest priority in the queue
	list<Employee*> ::iterator iter, to_be_popped;
	to_be_popped = employee_queue.begin();
	int max = (*to_be_popped)->calculate_priority();
	for (iter = employee_queue.begin(); iter != employee_queue.end(); ++iter)
	{
		if (((*iter)->calculate_priority()) > max)
		{
			max = (*iter)->calculate_priority();
			to_be_popped = iter;
		}
	}
	// update the retaining time for the employee with the highest priority
	(*to_be_popped)->update_retaining_time(days);
	// pop the emmployee with the highest priority
	employee_queue.erase(to_be_popped);

	if (employee_queue.empty())
		return;
	
	// update the waiting time for the rest employee in the queue
	for (iter = employee_queue.begin(); iter != employee_queue.end(); ++iter)
	{
		(*iter)->update_waiting_time(days);
	}
}


// Print the book 
void Book::print()
{
	cout << setiosflags(ios::left) << setw(12) << "Employee" << setw(20) << "Retaining Time" << setw(20) << "Waiting Time" << endl;
	list<Employee*> ::iterator iter;
	for (iter = employee_queue.begin(); iter != employee_queue.end(); ++iter)
	{
		cout << setiosflags(ios::left) << setw(12) << (*iter)->get_name() << setw(20) << (*iter)->get_retaining_time() << setw(20) << (*iter)->get_waiting_time() << endl;
	}
	cout << endl;
}