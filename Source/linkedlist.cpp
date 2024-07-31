class LinkedList
{
private:
	Node* head;
public:
	LinkedList()
	{
		head = nullptr;
	}
	void insertItems(int a)
	{
		//create a new node
		Node* newNode = new Node(a);

		if (head == nullptr)
		{
			head = newNode;
			return;
		}

		Node* temp = head;
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}

		temp->next = newNode;
	}

	void printList(Node* n)
	{

		/*if (head == nullptr)
		{
			cout << "List is empty" << endl;
			return;
		}*/

		while (n != nullptr)
		{
			cout << n->a << " " << endl;
			n = n->next;
		}
	}

	int middleElement()
	{
		Node* temp = head;
		Node* slowPtr = head;
		Node* fastPtr = head;

		while (fastPtr != nullptr && fastPtr->next != nullptr)
		{
			slowPtr = slowPtr->next;
			fastPtr = fastPtr->next->next;
		}
		return slowPtr->a;
	}

	Node* reverseList()
	{
		Node* temp = nullptr;
		Node* n = nullptr;

		while (head != nullptr)
		{
			temp = head->next;
			head->next = n;
			n = head;
			head = temp;
		}
		return n;
	}
};

int main()
{
	LinkedList list;

	list.insertItems(1);
	list.insertItems(2);
	list.insertItems(3);
	list.insertItems(4);
	list.insertItems(5);
	list.insertItems(6);
	list.insertItems(7);
	list.insertItems(8);
	list.insertItems(9);

	cout << "Elements of the lists are: ";

	//list.printList();

	auto res = list.middleElement();
	cout << "Middle element is: " << res << endl;

	auto res1 = list.reverseList();

	cout << "Elements of the lists are: ";

	list.printList(res1);
	return 0;
}
