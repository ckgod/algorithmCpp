#include <iostream>
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

class Linkedlist
{
public:
	node* head;
	node* tail;
	Linkedlist()
	{
		head = NULL;
		tail = NULL;
	}


	void enqueue(int x)
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
	int dequeue()
	{
		if (head == NULL)
		{
			return -1;
		}
		else
		{
			node* tmp = new node;
			tmp = head;
			head = head->next;
			return tmp->v;
		}
	}
	int size()
	{
		int cnt = 0;
		node* cur = new node;
		cur = head;
		while (cur != NULL)
		{
			cur = cur->next;
			cnt++;
		}
		return cnt;
	}
	int front()
	{
		if (head == NULL)
		{
			return -1;
		}
		else
		{
			return head->v;
		}
	}
	int set()
	{

	}
	void print()
	{
		node* cur = new node;
		cur = head;
		while (cur != NULL)
		{

			cout << cur->v << " ";
			cur = cur->next;
		}
	}
};


int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	Linkedlist ll;

	for (int i = 0; i < 4; i++)
	{
		int n;
		cin >> n;
		ll.enqueue(n);
	}

	ll.dequeue();
	ll.dequeue();
	ll.print();
	cout << ll.size() << endl;

	


	return 0;
}