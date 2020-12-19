#include <iostream>
#include <string>
using namespace std;


class Node {
public:
	int data;
	Node* next;

	Node(int e) {
		this->data = e;
		this->next = NULL;
	}
};


class SLinkedList {
public:
	Node* head;
	Node* tail;

	SLinkedList() {
		head = NULL;
		tail = NULL;
	}

	void addFront(int X)

	{

		Node* newnode = new Node(X);

		if (head == NULL)
		{
			head = tail = newnode;
		}
		else
		{
			newnode->next = head;
			head = newnode;
		}
	}
	int removeFront()
	{
		if (head == NULL)
		{
			return -1;
		}
		else
		{
			Node* temp = head;
			head = head->next;
			return temp->data;
		}
	}
	int front()

	{

		if (head == NULL)

		{

			return -1;

		}

		else

		{

			return head->data;

		}

	}

	int empty()

	{

		if (head == NULL)

		{

			return 1;

		}

		else

		{

			return 0;

		}



	}

	void showList()

	{

		if (empty() == 1)

		{

			cout << "-1" << endl;

		}

		else

		{

			Node* cnode = head;

			while (cnode != tail)

			{

				cout << cnode->data << " ";

				cnode = cnode->next;

			}

			cout << cnode->data << endl;

		}

	}

	void addBack(int X)

	{

		Node* newnode = new Node(X);

		if (head == NULL)

		{

			head = tail = newnode;

		}

		else

		{

			tail->next = newnode;

			tail = newnode;

		}

	}

};



int n;

string str;

int x;



int main()

{

	cin.tie(NULL);

	ios::sync_with_stdio(false);



	SLinkedList ll;



	cin >> n;

	while (n--)

	{

		cin >> str;

		if (str == "empty")

		{

			cout << ll.empty() << endl;

		}

		else if (str == "front")

		{

			cout << ll.front() << endl;

		}

		else if (str == "removeFront")

		{

			cout << ll.removeFront() << endl;

		}

		else if (str == "addFront")

		{

			cin >> x;

			ll.addFront(x);

		}

		else if (str == "showList")

		{

			ll.showList();

		}

		else if (str == "addBack")

		{

			cin >> x;

			ll.addBack(x);

		}

		str = { NULL };

	}





	return 0;

}