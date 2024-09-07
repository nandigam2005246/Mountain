#pragma once
#include <iostream>
using namespace std;

class Base
{
public:
	Base();

	virtual ~Base();

	virtual void func();
};

class Derived : public Base
{
public:
	Derived();

	~Derived();

	void func();
};