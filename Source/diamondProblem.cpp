/*
		A
	   / \
	  B   C
	   \ /
		D

*/

#include <iostream>

class A
{
public:
	void func()
	{
		std::cout << "Class A" << std::endl;
	}
};

class B : virtual public A
{
public:
	/*void func1()
	{
		std::cout << "Class B" << std::endl;
	}*/
};

class C : virtual public A
{
public:
	/*void func2()
	{
		std::cout << "Class C" << std::endl;
	}*/
};

class D : public B, C
{

};

int main() {
	D d;
	d.func();

	/*
		Using virtual keyword in class B and class C
		while inheriting will overcome the amiguity.
	*/

	/*
		One more way is to have different function names 
		in both Classes B and C.
	*/
	return 0;
}