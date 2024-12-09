#include <iostream>
using namespace std;

class OperatorOverloading
{
public:
    OperatorOverloading() : x(0), y(0)
    {

    }
    void func(std::ostream& out)
    {
        out << x << std::endl;
        out << y << std::endl;
    }

    // operator++ (pre increment overlaoding)
    OperatorOverloading& operator++()
    {
        //pre increment
        ++x;
        ++y;
        return *this;
    }

    // operator++ (post increment overlaoding)
    OperatorOverloading operator++(int a)
    {
        //post increment
        auto old = (*this);
        ++x;
        ++y;
        return old;
    }

    //operator== overloading
    bool operator==(OperatorOverloading& obj)
    {
        if ((x == obj.x) && (y == obj.y))
            return true;
        else
            return false;
    }
    void display()
    {
        cout << x << endl;
        cout << y << endl;
    }

    friend std::ostream& operator<<(std::ostream& out, OperatorOverloading& obj);
    friend std::istream& operator>>(std::istream& in, OperatorOverloading& obj);
private:
    int x, y;

};

//operator << overloading made it as a friend inorder to access the private variables of class OperatorOverloading 
std::ostream& operator<<(std::ostream& out, OperatorOverloading& obj)
{
    out << "x: " << obj.x << endl;
    out << "y: " << obj.y << endl;
    return out;
}

//operator >> overloading made it as a friend inorder to access the private variables of class OperatorOverloading 
std::istream& operator>>(std::istream& in, OperatorOverloading& obj)
{
    cin >> obj.x;
    cin >> obj.y;
    return in;
}

int main()
{
    OperatorOverloading a1;
    OperatorOverloading a2;
    cout << "Before Pre-Increment" << endl;
    cout << a1;
    cout << a2;
    a2 = ++a1;
    cout << "After Pre-Increment" << endl;
    cout << a1;
    cout << a2;


    OperatorOverloading a3;
    OperatorOverloading a4;
    cout << "Before Post-Increment" << endl;
    cout << a3;
    cout << a4;
    a4 = a3++;
    cout << "After Post-Increment" << endl;
    cout << a3;
    cout << a4;


    OperatorOverloading a5;
    cout << "Enter x and y: " << endl;
    cin >> a5;
    cout << "x and y values are: " << endl;
    cout << a5;
    OperatorOverloading a6;
    auto res = (a6 == a5);
    cout << "Res: " << res << endl;
    cout << a6;

    return 0;
}
