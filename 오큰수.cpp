#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int arr[1000001];
int n;
int ans[1000001];
stack<int> s;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (int i = n - 1; i >= 0; i--)
	{
		if (s.empty())
		{
			ans[i] = -1;
			s.push(arr[i]);
		}
		else if (arr[i] >= s.top())
		{
			while (1)
			{
				if (s.empty() || arr[i] < s.top())
				{
					break;
				}
				s.pop();
			}
			if (s.empty())
			{
				ans[i] = -1;
				s.push(arr[i]);
			}
			else
			{
				ans[i] = s.top();
				s.push(arr[i]);
			}
		}
		else if (arr[i] < s.top())
		{
			ans[i] = s.top();
			s.push(arr[i]);
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << ans[i] << " ";
	}

	return 0;
}