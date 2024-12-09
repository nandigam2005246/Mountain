// C++ code for reversing a queue
#include <queue>
#include <iostream>
using namespace std;

//// Utility function to print the queue
//void printQueue(queue<long long int> Queue)
//{
//	while (!Queue.empty()) {
//		cout << Queue.front() << " ";
//		Queue.pop();
//	}
//}
//
//// Recursive function to reverse the queue
//void reverseQueue(queue<long long int>& q)
//{
//	// Base case
//	if (q.empty())
//		return;
//
//	// Dequeue current item (from front) 
//	long long int data = q.front();
//	q.pop();
//
//	// Reverse remaining queue 
//	reverseQueue(q);
//
//	// Enqueue current item (to rear) 
//	q.push(data);
//}

//std::string reverseString(std::string& str, int start, int end)
//{
//	if (start == end)
//	{
//		return "";
//	}
//
//	auto element = str[start];
//	reverseString(str, start + 1, end);
//	cout << element;
//}

// Driver code
//int main()
//{
//	//queue<long long int> Queue;
//	//Queue.push(50);
//	//Queue.push(40);
//	//Queue.push(30);
//	//Queue.push(20);
//	////Queue.push(10);
//	////Queue.push(0);
//	//reverseQueue(Queue);
//	//printQueue(Queue);
//
//	/*std::string a = "Shanmuka";
//	std::cout << reverseString(a, 0, a.length());*/
//}

// C++ Program that illustrates the Implementation of Copy
// Constructor for Deep Copying
#include <cstring>
#include <iostream>
using namespace std;

class Student {
private:
    int test;
public:
    int roll;
    char* name;
    Student(int roll)
        : roll(roll)
    {
        name = new char[100]; // Allocate memory for name
    }

    void setName(const char* name)
    {
        strcpy(this->name, name);
    }

    char** address()
    {
        return &name;
    }
    // Implementing a deep copy constructor
    Student(const Student& other)
        : roll(other.roll)
    {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
    }

    // Implementing the copy assignment operator for deep
    // copying
    Student& operator=(const Student& other)
    {
        if (this != &other) { // Prevent self-assignment
            roll = other.roll;
            delete[] name; // Free existing name memory
            name = new char[strlen(other.name) + 1];
            strcpy(name, other.name);
        }
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& out, const Student& obj);
    // Implementing a destructor to deallocate dynamically
    // allocated memory
    ~Student() { delete[] name; }
};

std::ostream& operator<<(std::ostream& out, const Student& obj)
{
    out << obj.test << std::endl;
    return out;
}

#include <map>
#include <string>
#include <vector>

int main()
{
    // Create an object
    //Student s1(100);
    //s1.setName("John");
    //cout << "Original Object: " << s1.name << endl;

    //// Creating a copy of the object s1
    //Student s2 = s1; // Use copy constructor
    //std::cout << s1 << std::endl;
    //std::cout << s2 << std::endl;
    //cout << "Copy Object: " << s2.name << endl;

    //// Making changes in the data member of the copy object
    //s2.name[0] = 'S';

    //// Printing data members of both objects after making
    //// changes in copy object
    //cout << "After Changes:" << endl;
    //cout << "Original Object: " << s1.name << endl;
    //cout << "Copy Object: " << s2.name << endl;

    //cout << "Address of s1 ptr: " << s1.address() << std::endl;
    //cout << "Address of s2 ptr: " << s2.address() << std::endl;


   
       /* Program 2
        STR = aaabbffceeeeeyyaabh
        O / p = 3a2b2f1c4e5y2a1b1h Should get output like this Count of alphabet with alphabet*/

    std::string s = "aaabbffceeeeeyyaabh";
    std::map<char, int> m;

    for (int i = 0; s[i] != '\0'; i++)
    {
        m[s[i]]++;
    }

    for (auto fir : m)
    {
        std::cout << fir.second << fir.first;
    }

    


    /*Program 1 : 12234553 he will ask you to remove the consecutive number Or repeated numbers from this, in list way, */
   /* std::vector<int> arr = { 1,2,2,3,4,5,5,3 };

    for (int i = 0; i < arr.size(); i++)
    {
        if (i != arr.size())
        {
            if (arr.at(i) == arr.at(i + 1))
            {
                arr.erase(arr.begin() + (i));
            }
        }
    }

    for (int i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << std::endl;
    }*/

    return 0;
}
