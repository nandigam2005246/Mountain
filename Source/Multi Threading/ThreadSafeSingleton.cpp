#include <iostream>
#include <vector>
#include <memory>
#include <thread>
#include <mutex>

class Singleton
{
    private:
        Singleton()
        {
            std::cout << "ctor"<< std::endl;
        }
        int m_logger;
    
    private:
        static inline Singleton* m_instance = nullptr;
        static inline std::mutex mtx;
        static inline std::once_flag onceFlag;
    
    public:
    
        static inline Singleton* getInstance()
        {
            std::unique_lock<std::mutex> lock(mtx);
            if(m_instance == nullptr)
            {
                std::call_once(onceFlag, [] {
                    m_instance = new Singleton();
                });
            }
            return m_instance;
        }
        
        void release()
        {
            if(m_instance)
            {
                delete m_instance;
                m_instance = nullptr;
            }
        }
        
        void setLoggerLevel(int level)
        {
            m_logger = level;
        }
        
        int getLoggerLevel() const
        {
            return m_logger;
        }
};


int main()
{
    /*Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();*/
    
    std::thread t1(Singleton::getInstance);
    std::thread t2(Singleton::getInstance);
    /*s1->setLoggerLevel(2);
    
    std::cout << s1->getLoggerLevel() << std::endl;
    std::cout << s2->getLoggerLevel() << std::endl;
    
    s2->setLoggerLevel(3);
    
    
    std::cout << s1->getLoggerLevel() << std::endl;
    std::cout << s2->getLoggerLevel() << std::endl;*/
    
    
    t1.join();
    t2.join();
    
    //Singleton::getInstance()->release();
    
    
    
    return 0;
}
