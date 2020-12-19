#include <iostream>
using namespace std;


struct node
{
	int value;
	struct node* next = NULL;
};

struct Linkedlist
{
	node* head = new node;
	node* tail = new node;
};

void addhead (int x, Linkedlist ll)
{
	node* newnode = new node;
	newnode->value = x;
	newnode->next = ll.head->next;
	ll.head->next = newnode;
}

void delhead(Linkedlist ll)
{
	node* tmp = new node;
	tmp = ll.head->next;
	ll.head->next = tmp->next;
	delete tmp;
}

void addtail(int x, Linkedlist ll)
{
	node* newnode = new node;
	ll.tail->next = ll.head->next;
	while (ll.tail->next != NULL)
	{
		ll.tail = ll.tail->next;
	}
	ll.tail->next = newnode;
	newnode->value = x;
}


int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	Linkedlist ll;

	addhead(10, ll);
	addhead(20, ll);
	addhead(30, ll);


	node* ptr = new node;
	ptr = ll.head->next;
	while (ptr != NULL)
	{
		cout << ptr->value << endl;
		ptr = ptr->next;
	}

	cout << "\n---\n\n";
	delhead(ll);
	delhead(ll);

	ptr = ll.head->next; 
	while (ptr != NULL)
	{
		cout << ptr->value << endl;
		ptr = ptr->next;
	}

	cout << "\n---\n\n";
	addtail(20, ll);
	addtail(30, ll);

	ptr = ll.head->next;
	while (ptr != NULL)
	{
		cout << ptr->value << endl;
		ptr = ptr->next;
	}



	return 0;
}