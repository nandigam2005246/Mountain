#include <iostream>

template<typename T>
class SharedPtr
{
public:

	//default const
	SharedPtr() : m_ptr(nullptr), m_counter(nullptr) {}
	
	//param const
	SharedPtr(T* ptr) : m_ptr(ptr), m_counter(new int(1)) {}

	//copy const
	SharedPtr(const SharedPtr<T>& obj) : m_ptr(obj.m_ptr), m_counter(obj.m_counter)
	{
		incrementCounter();
	}

	//copy assign
	SharedPtr<T>& operator=(const SharedPtr<T>& obj)
	{
		if (this != &obj)
		{
			decrementCounter();
			m_ptr = obj.m_ptr;
			m_counter = obj.m_counter;
			incrementCounter();
		}

		return *this;
	}

	//move const
	SharedPtr(SharedPtr<T>&& obj) : m_ptr(obj.m_ptr), m_counter(obj.m_counter)
	{
		obj.m_ptr = nullptr;
		obj.m_counter = nullptr;
	}

	//move assign
	SharedPtr<T>& operator=(SharedPtr<T>&& obj)
	{
		if (this != &obj)
		{
			decrementCounter();
			m_ptr = obj.m_ptr;
			m_counter = obj.m_counter;
			obj.m_ptr = nullptr;
			obj.m_counter = nullptr;
		}

		return *this;
	}

	//Get func
	T* Get() const
	{
		return m_ptr;
	}

	// * overloading
	T& operator*() const
	{
		return *m_ptr;
	}

	// -> overloading
	T* operator->() const
	{
		return m_ptr;
	}

	T useCount() const
	{
		if (m_counter != nullptr)
			return *m_counter;

		return 0;
	}
	//destructor
	~SharedPtr()
	{
		decrementCounter();
	}

private:
	T* m_ptr = nullptr;
	int* m_counter = nullptr;

	//increment
	void incrementCounter()
	{
		(*m_counter)++;
	}

	//decrement
	void decrementCounter()
	{
		if (m_counter != nullptr)
		{
			(*m_counter)--;
			if (*m_counter == 0)
			{
				delete m_ptr;
				delete m_counter;
			}
		}
	}
};
int main()
{
	
	//param const
	SharedPtr<int> ptr1(new int(10));
	std::cout << ptr1.useCount() << std::endl;

	// copy const
	SharedPtr<int> ptr2(ptr1);
	std::cout << ptr1.useCount() << std::endl;
	std::cout << ptr2.useCount() << std::endl;
	//default const
	SharedPtr<int> ptr3(new int(200));

	std::cout << *ptr1 << std::endl;
	std::cout << *ptr2 << std::endl;

	*ptr2 = 30;
	//copy assign
	ptr1 = ptr3;
	std::cout << *ptr3 << std::endl;

	std::cout << *ptr1 << std::endl;
	std::cout << *ptr2 << std::endl;
	
	return 0;
}