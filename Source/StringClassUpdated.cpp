#include <iostream>
#include <cstring>

class String
{
public:

    String()
    {
        m_ptr = nullptr;
    }
    //param const
    String(const char* ptr)
    {
        m_ptr = new char[strlen(ptr) + 1];
        strcpy(m_ptr, ptr);
    }

    //copy const
    String(const String& obj)
    {
        m_ptr = new char[strlen(obj.m_ptr) + 1];
        strcpy(m_ptr, obj.m_ptr);
    }

    //copy assign
    String& operator=(const String& obj)
    {
        if (this == &obj)
        {
            return *this;
        }

        String temp(obj);
        Swap(*this, temp);
        return *this;
    }

    //move const
    String(String&& obj) noexcept
    {
        moveFrom(obj);
    }

    //move assign
    String& operator=(String&& obj) noexcept
    {
        if (this == &obj)
        {
            return *this;
        }

        //free old resource
        cleanup();

        moveFrom(obj);

        return *this;
    }

    //destructor
    ~String()
    {

    }

    void display()
    {
        std::cout << m_ptr << std::endl;
    }

    void cleanup()
    {
        m_ptr = nullptr;
    }

    void moveFrom(String& obj)
    {
        //shallow copy
        m_ptr = obj.m_ptr;

        //reset the object since the ownership has been moved
        obj.m_ptr = nullptr;
    }

    friend void Swap(String& lhs, String& rhs);

private:
    char* m_ptr;
};

void Swap(String& lhs, String& rhs)
{
    std::swap(lhs.m_ptr, rhs.m_ptr);
}

int main()
{
    String a("Hello");
    a.display();

    String a1(std::move(a));
    a1.display();

    const char* name = "Shanmuk";
    a1 = std::move(name);
    a1.display();
    String a2;
    a2 = std::move(a1);
    a2.display();

    return 0;
}

//Output:
/*
Hello
Hello
Shanmuk
Shanmuk
*/
