#ifndef BOOK_H
#define BOOK_H

#include "Date.h"
#include "Employee.h"
#include <list>
#include <string>
using namespace std;

class Book
{
public:

	// Constructor
	Book(string book_name);
	~Book();

	// Getters and Setters
	string getTitle();
	void setTitle(string book_name);
	bool get_archived();
	void set_archived(bool b);
	Date get_start_circulation();
	void set_start_circulation(Date date);
	Date get_end_circulation();
	void set_end_circulation(Date date);

	bool empty();
	// push employee to the priority queue of book
	void push(Employee* e);
	// Pop the first employee of priority queue
	void pop();
	// sort the employee queue according the priority of waiting_time – retaining_time
	void sort();
	// update the retaining time and waiting time of employee in the queue
	void update(int days);
	// Print the book 
	void print();

private:
	string title;
	Date start_circulation;
	Date end_circulation;
	bool archived;
	list<Employee*> employee_queue;
};
#endif