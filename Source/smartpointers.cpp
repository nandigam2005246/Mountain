#include <memory>
#include "smartpointers.hpp"

Employee::Employee()
{
}

Employee::~Employee()
{
}

Employee::Employee(std::string str)
{
}

void Employee::Display()
{
}

void DisplayOut(shared_ptr<Employee>& obj)
{
	cout << obj->name << endl;
}
