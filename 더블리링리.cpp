#include<iostream>
using std::cerr;
using std::cout;
using std::cin;

class DoubleLinkedList {
private:
	int size;
	class Node {
	private:
		int value;
		Node* next;
		Node* prev;
		friend DoubleLinkedList;
	public:
		Node(int v) {
			value = v;
		}
	};
	typedef Node* NodePtr;

	NodePtr head;
	NodePtr tail;

public:
	DoubleLinkedList() {
		size = 0;
		head = new Node(-1);
		tail = new Node(-1);
		head->next = tail;
		tail->prev = head;
	}

	~DoubleLinkedList() {
		if (isEmpty())
			return;

		NodePtr current = head->next;
		NodePtr temp;
		while (current != tail) {
			temp = current;
			current = current->next;
			delete temp;
		}
		delete head;
		delete tail;
	}

	bool isEmpty() {
		if (size == 0)
			return true;
		else
			return false;
	}

	void push_back(int value) {
		NodePtr newNode = new Node(value);

		tail->prev->next = newNode;
		newNode->prev = tail->prev;
		newNode->next = tail;
		tail->prev = newNode;
		size++;
	}

	void insert(int value, int position) {
		if (position > size) {
			printf("inappropriate position\n");
			return;
		}

		int c = 0;
		NodePtr current = head->next;
		NodePtr newNode = new Node(value);

		while (c != position) {
			current = current->next;
			c++;
		}

		newNode->prev = current->prev;
		newNode->next = current;
		current->prev->next = newNode;
		current->prev = newNode;

		size++;
	}

	void remove(int position) {
		if (isEmpty()) {
			cerr << "list is empty\n";
			return;
		}
		if (position >= size) {
			printf("inappropriate position\n");
			return;
		}

		int c = 0;

		NodePtr current = head->next;
		while (c != position) {
			current = current->next;
			c++;
		}

		current->prev->next = current->next;
		current->next->prev = current->prev;

		delete current;
		size--;
	}

	void printAll() {
		if (isEmpty()) {
			cerr << "list is empty\n";
			return;
		}

		int position = 0;

		cout << "---------------------------------------\n";
		cout << "list = (";
		NodePtr current = head->next;
		cout << current->value;
		current = current->next;

		while (current != tail) {
			cout << ", " << current->value;
			current = current->next;
		}
		cout << ")\n\n";

		current = head->next;
		while (current != tail) {
			printf("value = %d, pos = %d, addr = %d, prev addr = %d, next addr = %d\n",
				current->value, position, current, current->prev, current->next);
			current = current->next;
			position++;
		}
		cout << "---------------------------------------\n";
		printf("\n");
	}
};

int main() {
	cout << "C++ double linked list program\n";
	int select = 0;
	int value = 0;
	int position = 0;

	DoubleLinkedList list;

	while (true) {
		cout << "=======================================\n";
		cout << "1. push_back\n";
		cout << "2. insert\n";
		cout << "3. remove\n";
		cout << "4. exit\n";
		cout << "=======================================\n";
		cout << "answer : ";
		cin >> select;

		switch (select) {
		case 1:
			cout << "input (value) : ";
			cin >> value;
			list.push_back(value);
			list.printAll();
			break;
		case 2:
			cout << "input (value position) : ";
			cin >> value >> position;
			list.insert(value, position);
			list.printAll();

			break;
		case 3:
			cout << "input (position) : ";
			cin >> position;
			list.remove(position);
			list.printAll();
			break;
		default:
			return 0;
		}
	}

	return 0;
}