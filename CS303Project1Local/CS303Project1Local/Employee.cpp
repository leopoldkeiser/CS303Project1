#include "Employee.h"
#include <string>
using namespace std;

// Constructor
Employee::Employee(std::string employee_name)
{
	name = employee_name;
	waiting_time = 0;
	retaining_time = 0;
}

Employee::~Employee()
{

}

// Getters and Setters
string Employee::get_name() 
{ 
	return name; 
}

void Employee::set_name(string employee_name)
{
	name = employee_name;
}

int Employee::get_waiting_time() 
{ 
	return waiting_time; 
}

void Employee::set_waiting_time(int days)
{
	waiting_time = days;
}

int Employee::get_retaining_time() 
{ 
	return retaining_time; 
}

void Employee::set_retaining_time(int days)
{ 
	retaining_time = days;
}

// update waiting time
void Employee::update_waiting_time(int days)
{ 
	waiting_time += days;
}

// updayte retaining time
void Employee::update_retaining_time(int days)
{ 
	retaining_time += days;
}

// calculate the priority: waiting_time – retaining_time.
int Employee::calculate_priority()
{
	return waiting_time - retaining_time;
}