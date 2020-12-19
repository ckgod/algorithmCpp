#include <iostream>
#include <string>
using namespace std;

template<typename Type>
class node
{
public:
	int data;
	node* next;
	node* prev;
	node<Type>()
	{
		this->data = 0;
		this->next = NULL;
		this->prev = NULL;
	}
};

class d_linked_list 
{
protected:
	node<Type>* head = new node<Type>();
	node<Type>* tail = new node<Type>();
	int size = 0;

public:
	d_linked_list()
	{
		head->data = -1;
		tail->data = -1;
		this->size = 0;
		head->next = tail;
		tail->prev = head;
	}

	void push_back(int x)
	{
		node* newnode = new node;
		newnode->data = x;
		tail->prev->next = newnode;
		newnode->prev = tail->prev;
		newnode->next = tail;
		tail->prev = newnode;
		size++;
	}

	void push_front(int x)
	{
		node* newnode = new node;
		newnode->data = x;
		head->next->prev = newnode;
		newnode->next = head->next;
		newnode->prev = head;
		head->next = newnode;
		size++;
	}

	void insert_node_at(int idx, int n)
	{
		if (size < idx)
		{
			cout << "inappropriate position\n";
			return;
		}

		int c = 0;
		node* newnode = new node;
		node* cur = new node;
		newnode->data = idx;
		cur = head->next;
		while (c != idx)
		{
			cur = cur->next;
			c++;
		}

		cur->prev->next = newnode;
		newnode->prev = cur->prev;
		newnode->next = cur;
		cur->prev = newnode;
		size++;
	}

	void remove(int position)
	{
		if (isEmpty() == true)
		{
			cout << "Empty\n";
			return;
		}
		if (position >= size)
		{
			cout << "inappropriate position\n";
			return;
		}

		node* cur = new node;
		cur = head->next;
		int c = 0;
		while (c != position)
		{
			cur = cur->next;
			c++;
		}

		cur->prev->next = cur->next;
		cur->next->prev = cur->prev;
		delete cur;
		size--;
	}

	bool isEmpty()
	{
		if (size == 0) return true;
		else return false;
	}

	void print()
	{
		if (isEmpty() == true)
		{
			cout << "Empty";
		}

		node* cur = new node;
		cur = head->next;
		while (cur != tail)
		{
			cout << cur->data << " ";
			cur = cur->next;
		}
		cout << "\n";
	}

};


int t;
string str;
int n;
d_linked_list ll;
int p;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> str;
		if (str == "pb")
		{
			cin >> n;
			ll.push_back(n);
		}
		else if (str == "pf")
		{
			cin >> n;
			ll.push_front(n);
		}
		else if (str == "insert")
		{
			cin >> n >> p;
			ll.insert_node_at(n, p);
		}
		else if (str == "remove")
		{
			cin >> p;
			ll.remove(p);
		}
		else if (str == "print")
		{
			ll.print();
		}
	}
	return 0;
}