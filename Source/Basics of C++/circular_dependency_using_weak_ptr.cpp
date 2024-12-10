#include <iostream>
#include <memory>

struct B;

struct A
{
	A()
	{
		std::cout << "A const" << std::endl;
	}

	~A()
	{
		std::cout << "A dest" << std::endl;
	}

	
	std::shared_ptr<B> ptr;
};

struct B
{
	B()
	{
		std::cout << "B const" << std::endl;
	}

	~B()
	{
		std::cout << "B dest" << std::endl;
	}

	std::weak_ptr<A> ptr;
};

int main()
{
	std::shared_ptr<A> aobj = std::make_unique<A>();
	std::shared_ptr<B> bobj = std::make_unique<B>();

	std::cout << aobj.use_count() << std::endl;
	std::cout << bobj.use_count() << std::endl;

	aobj->ptr = bobj; // The reference count of bobj increases to 2 because aobj->ptr holds a shared pointer to b.
	bobj->ptr = aobj; // The reference count of aobj increases to 2 because bobj->ptr holds a shared pointer to a

	std::cout << aobj.use_count() << std::endl;
	std::cout << bobj.use_count() << std::endl;

	/*
		Cyclic dependency can be overcome by declaring A class poiner or B class pointer as weak_ptr instead of 
		share_ptr. If shared_ptr is used in both A and B, then there will be memory leaks.
	*/

	return 0;
}

//Output
/*
A const
B const
1
1
1
2
A dest
B dest
*/