#include <iostream>
#include <string>
using namespace std;

string str;
int tmp[10001];
int t;
int idx, x;

class Array
{
public:
	int n;
	int* arr;

	Array(int size)
	{
		this->n = 0;
		this->arr = new int[size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = 0;
		}
	}

	int at(int idx)
	{
		if (arr[idx] == 0)
		{
			return 0;
		}
		return arr[idx];
	}
	void set(int idx, int x)
	{
		if(arr[idx] != 0)
		{
			arr[idx] = x;
		}
		else
		{
			cout << "0\n";
			arr[idx] = x;
		}
	}
	void add(int idx, int num)
	{
		if(arr[idx] == 0)
		{
			for (int i = 9999; i >= 0; i--)
			{
				if (arr[i] != 0)
				{
					arr[i + 1] = num;
					return;
				}
			}
			arr[0] = num;
			return;
		}
		else
		{
			for (int i = idx; i < 10000; i++)
			{
				tmp[i + 1] = arr[i];
			}
			arr[idx] = num;
			for (int i = idx+1; i < 10000; i++)
			{
				arr[i] = tmp[i];
			}
			return;
		}

	}
};


int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	Array A(10000);

	cin >> t;
	while (t--)
	{
		cin >> str >> idx;
		if (str == "at")
		{
			cout << A.at(idx) << endl;
		}
		else if (str == "set")
		{
			cin >> x;
			A.set(idx, x);
		}
		else if (str == "add")
		{
			cin >> x;
			A.add(idx, x);
		}
		else
		{
			break;
		}
	}
	
	return 0;
}