#include <iostream>
#include <string>
using namespace std;

class stack
{
public:
	int* S;
	int capacity;
	int head;

	stack(int capacity)
	{
		this->capacity = capacity;
		this->S = new int[capacity];
		this->head = -1;
	}
	int size()
	{
		return head + 1;
	}
	bool empty()
	{
		if (head == -1)
		{
			return true;
		}
		else return false;
	}
	int top()
	{
		if (head == -1)
		{
			return -1;
		}
		else
		{
			return S[head];
		}
	}
	void push(int v)
	{
		if (head + 1 == this->capacity)
		{
			cout << "full\n";
		}
		else
		{
			head++;
			S[head] = v;
		}
	}
	int pop()
	{
		if (head == -1)
		{
			return -1;
		}
		else
		{
			int tmp = S[head];
			head--;
			return tmp;
		}
	}

};

string str;
int n;
int v;

int main()
{
	cin >> n;
	stack s(n + 1);
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		if (str == "empty")
		{
			cout << s.empty() << "\n";
		}
		else if (str == "top")
		{
			cout << s.top() << "\n";
		}
		else if (str == "push")
		{
			cin >> v;
			s.push(v);
		}
		else if (str == "pop")
		{
			cout << s.pop() << "\n";
		}
		else if (str == "size")
		{
			cout << s.size() << "\n";
		}
	}




	return 0;
}