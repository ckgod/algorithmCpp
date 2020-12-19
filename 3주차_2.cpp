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
			tail->next = head;
		}
	}

};

int n;
string str;
int x;
int arr[10];

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	SLinkedList ll;

	cin >> n;
	while (n--)
	{
		for (int i = 0; i < 10; i++)
		{
			cin >> arr[i];
			ll.addBack(arr[i]);
		}
		for (int i = 0; i < 3; i++)
		{
			cin >> str;
			if (str == "Delete")
			{
				cin >> x;
				Node* cnode = ll.head;
				Node* tmp = ll.head;
				if (x == 0)
				{
					ll.head = ll.head->next;
					ll.tail->next = ll.head;
				}
				else
				{
					for (int j = 0; j < x - 1; j++)
					{
						cnode = cnode->next;
					}
					for (int j = 0; j < x + 1; j++)
					{
						tmp = tmp->next;
					}
					if (cnode->next == ll.tail)
					{
						ll.tail = cnode;
					}
					else if (cnode->next == ll.head)
					{
						ll.head = tmp;
					}
					cnode->next = tmp;
				}
			}
		}
		ll.showList();
		ll.head = NULL;
		ll.tail = NULL;
	}


	return 0;

}