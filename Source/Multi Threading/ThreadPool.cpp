#include <iostream>
#include <mutex>
#include <thread>
#include <condition_variable>
#include <queue>
#include <functional>

class ThreadPool
{
    public:
    ThreadPool(int threads) : m_threadCount(threads)
    {
        for(int i = 0; i < m_threadCount; ++i)
        {
            m_threads.emplace_back([this]{
               while(true)
               {
                   std::function<void()> task;
                   {
                       std::unique_lock<std::mutex> lock(mtx);
                       cv.wait(lock, [this]{
                           return (m_shutdown || !m_tasks.empty());
                       });

                       if(m_shutdown && m_tasks.empty())
                       {
                           return ;
                       }
                       
                       task = std::move(m_tasks.front());
                       m_tasks.pop();
                   }
                   
                   task();
                }
            });
        }
    }
    
    void enqueue(std::function<void()> task)
    {
        {
            std::unique_lock<std::mutex> lock(mtx);
            m_tasks.emplace(std::move(task));
        }
        cv.notify_one();
    }
    
    ~ThreadPool()
    {
        {
            std::unique_lock<std::mutex> lock(mtx);
            
            m_shutdown = true;
            
        }
        
        cv.notify_all();
        
        for(auto& thread: m_threads)
        {
            thread.join();
        }
    }
    private:
    
    std::mutex mtx;
    
    std::condition_variable cv;
    
    std::vector<std::thread> m_threads;
    
    int m_threadCount;
    
    std::queue<std::function<void()>> m_tasks;
    
    bool m_shutdown = false;
};

int main()
{
    ThreadPool pool(3);
    
    for(int i = 0; i < 40; i++)
    {
        pool.enqueue([i](){
            std::cout << "Task is runing on thread " << i << " of id: " << std::this_thread::get_id() << std::endl;
        });
    }
    return 0;
}
