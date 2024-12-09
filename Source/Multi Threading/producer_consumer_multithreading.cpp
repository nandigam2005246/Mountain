#include <iostream>
#include <thread>
#include <mutex>
#include <queue>
#include <condition_variable>

std::condition_variable cv;
std::mutex mtx;
std::queue<int> q;
const int buffersize = 10;

void producer(int num)
{
	std::unique_lock<std::mutex> lck(mtx);
	cv.wait(lck, []() {
			return q.size() < buffersize;
		});
	q.push(num);
	std::cout << "Producer: " << num << std::endl;
	lck.unlock();
	cv.notify_one();
}

void consumer()
{
	std::unique_lock<std::mutex> lck(mtx);
	cv.wait(lck, []() {
		return q.size() > 0;
		});
	int num = q.front();
	q.pop();
	std::cout << "Consumer: " << num << std::endl;
	lck.unlock();
	cv.notify_one();
}

int main()
{
	std::thread pt([]() {
			for (int i = 0; i < 10; ++i)
			{
				producer(i);
			}
		});
	std::thread ct([]() {
			for (int i = 0; i < 10; i++)
			{
				consumer();
			}
		});

	pt.join();
	ct.join();

	return 0;
}

//Output
/*
Producer: 0
Producer: 1
Producer: 2
Producer: 3
Producer: 4
Producer: 5
Producer: 6
Producer: 7
Producer: 8
Producer: 9
Consumer: 0
Consumer: 1
Consumer: 2
Consumer: 3
Consumer: 4
Consumer: 5
Consumer: 6
Consumer: 7
Consumer: 8
Consumer: 9
*/