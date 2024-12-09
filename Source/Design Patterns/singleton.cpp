#include <iostream>

class Singleton
{
private:
	
	//static private pointer
	static Singleton* ptr;

	int m_logLevel;

	//private constructor
	Singleton()
	{
		ptr = nullptr;
		m_logLevel = 0;
	}
public:

	//static public function
	static Singleton* getInstance();

	void setLogLevel(int logLevel);
	int getLogLevel();
	void printLogLevel();
};

Singleton* Singleton ::ptr = nullptr;

Singleton* Singleton::getInstance()
{
	if (ptr == nullptr)
	{
		ptr = new Singleton();
		return ptr;
	}
	else
	{
		return ptr;
	}
}

void Singleton::setLogLevel(int logLevel)
{
	m_logLevel = logLevel;
}

int Singleton::getLogLevel()
{
	return m_logLevel;
}

void Singleton::printLogLevel()
{
	std::cout << m_logLevel << std::endl;
}

int main()
{
	Singleton* s1 = Singleton::getInstance();
	//log level is set to 5 by s1 object.
	s1->setLogLevel(5);
	s1->printLogLevel();

	//log level is updated using s2 obj from 5 to 6.
	Singleton* s2 = Singleton::getInstance();
	s2->setLogLevel(6);
	s2->printLogLevel();

	//Log level is changed only in s2 obj but s1 obj is also changed.
	s1->printLogLevel();
	s2->printLogLevel();

	//Updated value will be there at any point of time for any instance

	//Logging once created/modified the same is needed for other users as well.
}
