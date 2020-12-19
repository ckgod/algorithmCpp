#include <iostream>
using namespace std;


struct node {
	int value;
	struct node* next;
};


struct list {
	node* head = new node;
	node* tail = new node;
};


void add_node(int x, list ll)
{
	node* newnode = new node;
	newnode->next = ll.tail;
	newnode->value = x;

	
}


void print(list)
{
	node* ptr = new node;

	delete ptr;
}


int t;


int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	list ll;
	ll.head = NULL;
	node* n = new node;
	ll.head = n;
	ll.tail = n;


	cin >> t;
	while (t--)
	{
		int x;
		cin >> x;
		add_node(x, ll);
	}



	return 0;
}