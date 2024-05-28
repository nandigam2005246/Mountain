#pragma once
#include <iostream>
using namespace std;
#include <memory>

class Employee
{
public:
    Employee();
    ~Employee();
    Employee(std::string str);
    void Display();
    friend void DisplayOut(shared_ptr<Employee>& obj);
private:
    string name;
};