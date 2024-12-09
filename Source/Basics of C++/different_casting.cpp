#include <iostream>


class Base
{
public:
    virtual void func()
    {
        std::cout << "Base" << std::endl;
    }
};

class Derived : public Base
{
public:
    void func() override
    {
        std::cout << "Derived" << std::endl;
    }
};

class Base1
{
public:
    void func()
    {
        std::cout << "Base1" << std::endl;
    }
};

class Derived1
{
public:
    void func()
    {
        std::cout << "Derived1" << std::endl;
    }

};

int main()
{
    Base* pb = new Base();

    //static_cast doesn't perform any run time checks.
    //Compiler will take decision during compile time itself
    //As a result Base class func is called
    //Most of the times Base and Derived func implementation
    //will be different and in some cases there might not be
    //any derived class function with same name
    Derived* pd2 = static_cast<Derived*>(pb);
    if (pd2 != nullptr)
    {
        pd2->func();
    }

    //dynamic_cast performs run time checks, if the cast is not valid it returns nullptr
    //in this case since we are trying to convert base to derived, cast will fail
    //and retuns nullptr
    Derived* pd1 = dynamic_cast<Derived*>(pb);
    if (pd1 != nullptr)
    {
        pd1->func();
    }
    else
    {
        std::cout << "Cannot cast" << std::endl;
    }

    /* const_cast */

    //removes constness from objects, this cannot be achieved using static_cast
    const Base* bp1 = new Base();
    //Base* bp2 = static_cast<Base*>(bp1);
    Base* bp2 = const_cast<Base*>(bp1);

    /* reinterpret_cast */

    /* Example 1*/
    //able to convert pointer of one type to other type
    //dangerous cast should be careful while using it
    char* chptr = new char('A');
    std::cout << *chptr << std::endl;
    int* iptr = reinterpret_cast<int*>(chptr);
    std::cout << *iptr << std::endl;
    delete chptr;

    /* Example 2*/
    //It is used to cast different types of objects
    //One should be clear while doing this cast
    //It might be dangerous if you don't know what 
    //exactly you are doing
    //In this case there is no relation b/w Base1 and Derived1
    //can't use static_cast or dynamic_cast or const_cost
    Base1* base1 = new Base1();
    Derived1* obj1 = new Derived1();
    Derived1* obj2 = reinterpret_cast<Derived1*>(base1);
    Base1* obj3 = reinterpret_cast<Base1*>(obj1);
    obj3->func();
    obj2->func();

    return 0;
}
