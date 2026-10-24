#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
const int maxSize = 10;
int count = 0;

void printEven()
{
	while (true)
	{
		std::unique_lock<std::mutex> lock(mtx);
		cv.wait(lock, []() {
			return (count % 2 == 0) || count > maxSize;
			});

		if (count > maxSize)
			break;

		std::cout << "Even: " << count << std::endl;
		++count;

		lock.unlock();
		cv.notify_one();
	}
}

void printOdd()
{
	while (true)
	{
		std::unique_lock<std::mutex> lock(mtx);
		cv.wait(lock, []() {
			return (count % 2 == 1) || count > maxSize;
			});

		if (count > maxSize)
			break;

		std::cout << "Odd: " << count << std::endl;
		++count;

		lock.unlock();
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

/*Output
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

// count > maxSize prevents the even thread from waiting indefinitely
// after all numbers have been processed.