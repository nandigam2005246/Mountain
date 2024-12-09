#include <iostream>
#include <thread>

std::atomic<int> count = 0;
const int maxSize = 10;

void printEven()
{
	while (count <= maxSize)
	{
		if (count % 2 == 0)
		{
			std::cout << "Even: " << count << std::endl;
			count++;
		}
	}
}

void printOdd()
{
	while (count <= maxSize)
	{
		if (count % 2 == 1)
		{
			std::cout << "Odd: " << count << std::endl;
			count++;
		}
	}
}

int main()
{
	std::thread t1(printEven);
	std::thread t2(printOdd);

	t1.join();
	t2.join();

	return 0;
}

//Output
/*
Even: 0
Odd: 1
Even: 2
Odd: 3
Even: 4
Odd: 5
Even: 6
Odd: 7
Even: 8
Odd: 9
Even: 10
*/