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

	Book(string book_name);
	~Book();
	string getTitle();
	bool isArchived();
	bool empty();
	void pop();
	void push(Employee* e);

	void set_archived(bool b);
	bool get_archived();
	void set_start_circulation(Date date);
	Date get_start_circulation();
	void set_end_circulation(Date date);
	Date get_end_circulation();
	void print_queue();
	void sort();
	void update(int days);

private:
	string title;
	Date start_circulation;
	Date end_circulation;
	bool archived;
	list<Employee*> employee_queue;
};
#endif