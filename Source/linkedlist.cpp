#include <iostream>
#include <memory>
using namespace std;

struct Node
{
	int data;
	shared_ptr<Node> next;
};

class LinkedList
{
public:

};