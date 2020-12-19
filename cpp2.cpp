#include<iostream>
using namespace std;

int t;


struct node {
	int v;
	node* next = NULL;
};


struct linked_list {
	node* head = new node;
};


void add_node(int x, linked_list ll) { //?
	node* newnode = new node;
	node* ptr = ll.head;
	while (ptr->next != NULL) {
		ptr = ptr->next;
	}
	ptr->next = newnode;
	newnode->v = x;



}


void print_list(linked_list ll) {
	node* ptr = ll.head;
	while (ptr->next != NULL) {
		ptr = ptr->next;
		cout << ptr->v << " ";
	}
}


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	linked_list ll;
	ll.head->next = NULL;
	cin >> t;
	while (t--) {
		int x;
		cin >> x;
		add_node(x, ll);
	}
	print_list(ll);
	return 0;
}