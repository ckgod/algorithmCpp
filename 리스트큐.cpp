#include<iostream>
#include<string>
using namespace std;

class node
{
public:
	int v;
	node* next;
	node()
	{
		this->v = 0;
		this->next = NULL;
	}
};

class queue
{
public:
	int capacity;
	int* Q;
	node* head = new node;
	node* tail = new node;

	queue(int x)
	{
		this->capacity = x;
		Q = new int[x];
		head = NULL;
		tail = NULL;
	}

	void pushback(int x)
	{
		node* newnode = new node;
		newnode->v = x;
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
	void popfront()
	{
		if (head == NULL)
		{
			cout << "Empty\n";
		}
		else
		{
			node* tmp = new node;
			tmp = head;
			head = head->next;
			delete tmp;
		}
	}
	int size()
	{


	}
	bool isEmpty()
	{

	}
	void print()
	{

	}
};

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);






	return 0;
}