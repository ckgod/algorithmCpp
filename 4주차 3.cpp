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
stack s(101);
int tmp1, tmp2;
int res;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		for (int j = 0; j < str.size(); j++)
		{
			if (str[j] >= '1' && str[j] <= '9')
			{
				s.push(str[j] - '0');
			}
			else if (str[j] == '*')
			{
				tmp2 = s.top();
				s.pop();
				tmp1 = s.top();
				s.pop();
				res = tmp1 * tmp2;
				s.push(res);
			}
			else if (str[j] == '+')
			{
				tmp2 = s.top();
				s.pop();
				tmp1 = s.top();
				s.pop();
				res = tmp1 + tmp2;
				s.push(res);
			}
			else if (str[j] == '-')
			{
				tmp2 = s.top();
				s.pop();
				tmp1 = s.top();
				s.pop();
				res = tmp1 - tmp2;
				s.push(res);
			}
		}
		cout << s.top() << "\n";
		while (!s.empty())
		{
			s.pop();
		}
	}


	return 0;
}