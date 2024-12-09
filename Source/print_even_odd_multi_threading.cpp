#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

int count = 0;
std::mutex mtx;
std::condition_variable cv;
const int maxSize = 10;

void printEven()
{
	while (count < maxSize)
	{
		std::unique_lock<std::mutex> lck(mtx);
		cv.wait(lck, []() {
			return (count % 2 == 0);
			});
		std::cout << "Even: " << count << std::endl;
		count++;
		lck.unlock();
		cv.notify_one();
	}
}

void printOdd()
{
	while (count < maxSize)
	{
		std::unique_lock<std::mutex> lck(mtx);
		cv.wait(lck, []() {
			return (count % 2 == 1);
			});
		std::cout << "Odd: " << count << std::endl;
		count++;
		lck.unlock();
		cv.notify_one();
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