#include <iostream>
#include <vector>
#include <memory>

class Isubscriber
{
    public:
    virtual void notify(std::string& msg) = 0;
};

class Subcriber : public Isubscriber
{
    private:
    int m_id;
    
    public:
    
    Subcriber(int id) : m_id(id)
    {
        
    }
    
    void notify(std::string& msg) override
    {
        std::cout << msg << " for user" << m_id << std::endl; 
    }
};

class Publisher
{
    public:
    void subscribe(Isubscriber* obj)
    {
        users.push_back(obj);
    }
    void unsubscribe(Isubscriber* obj)
    {
         users.pop_back();
    }
    void notify(std::string msg)
    {
        for(auto& user: users)
        {
            user->notify(msg);
        }
    }
    private:
    std::vector<Isubscriber*> users;
};

int main()
{
    Publisher* publish = new Publisher();
    
    Subcriber* user1 = new Subcriber(1);
    Subcriber* user2 = new Subcriber(2);
    Subcriber* user3 = new Subcriber(3);
    
    /*std::shared_ptr<Isubscriber*> user1 = std::make_shared<Subcriber*>(1);
    std::shared_ptr<Isubscriber*> user2 = std::make_shared<Subcriber*>(new int (2));
    std::shared_ptr<Isubscriber*> user3 = std::make_shared<Isubscriber*>(new int(3));*/
    
    publish->subscribe(user1);
    publish->subscribe(user2);
    publish->subscribe(user3);
    
    publish->notify("Message from Publisher");
    
    publish->unsubscribe(user1);
    
    publish->notify("Message from Publisher");
    
    delete user1;
    delete user2;
    delete user3;
    
    return 0;
}
