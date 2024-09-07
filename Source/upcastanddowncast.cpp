#include "upcastanddowncast.h"

Base::Base()
{
}

Base::~Base()
{
}

void Base::func()
{
	cout << "Base Function" << endl;
}

Derived::Derived()
{
}

Derived::~Derived()
{
}

void Derived::func()
{
	cout << "Derived Function" << endl;
}


int main()
{
    //Up Casting (compiler itself will do the conversion)
    Derived d;
    Base* bp = &d;
    bp->func();

    //Down Casting (user need to convert explicitly)
    //Why Down casting is Dangerous?

    Base b;
    Derived* dp = dynamic_cast<Derived*> (&b);

    if (dp != nullptr)
    {
        cout << "pointer is not null" << endl;
    }
    else
    {
        cout << "pointer is null" << endl;
    }

    return 0;
}