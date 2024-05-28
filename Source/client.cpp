#include <iostream>
#include "algorithms.hpp"
#include "smartpointers.hpp"
#include "linkedlist.hpp"



int main()
{
    //Employee* employee = new Employee();
    //delete employee;

    // Shared pointer

    shared_ptr<Employee>e1 = make_shared<Employee>("Shanmukanand");
    e1->Display();

    shared_ptr<Employee>e11 = make_shared<Employee>("Shashi");
    e11->Display();

    shared_ptr<Employee> e12 = e1;

    cout << e11.get() << endl;
    cout << e1.get() << endl;
    cout << e12.get() << endl;

    cout << "Before Reset: " << e1.use_count() << endl;
    cout << "Before Reset: " << e12.use_count() << endl;

    e1->Display();

    e1.reset();
    cout << "After Reset: " << e1.use_count() << endl;
    cout << "After Reset: " << e12.use_count() << endl;

    DisplayOut(e11);
    //e1->Display(); //Since the object is freed using reset it will be nullptr

    // Unique Pointer

    /* unique_ptr<Employee>e2 = make_unique<Employee>("Anudeep");
    e2->Display();

    unique_ptr<Employee>e3 = make_unique<Employee>("Harish");
    e3 = std::move(e2);

    e3->Display();*/

    return 0;
}