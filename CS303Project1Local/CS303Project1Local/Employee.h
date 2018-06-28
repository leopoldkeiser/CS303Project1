#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
using namespace std;
class Employee {

public:
	// Constructor
	Employee(string employee_name);
	~Employee();

	// Getters and Setters
	string get_name();
	void set_name(string employee_name);
	int get_waiting_time();
	void set_waiting_time(int days);
	int get_retaining_time();
	void set_retaining_time(int days);

	// update waiting time
	void update_waiting_time(int days);
	// updayte retaining time
	void updayte_retaining_time(int days);

private:
	string name;
	int waiting_time;
	int retaining_time;
};
#endif // !EMPLOYEE_H

