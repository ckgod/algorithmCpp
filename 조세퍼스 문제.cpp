#include <iostream>
#include <queue>
#include <string>
using namespace std;

int n, k;
int ans[5001];
queue<int> q;
queue<int> tmp;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		q.push(i + 1);
	}
	
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < k; i++)
		{
			if (i == k - 1)
			{
				tmp.push(q.front());
				q.pop();
				break;
			}
			q.push(q.front());
			q.pop();
		}
	}

	for (int i = 0; i < n; i++)
	{
		ans[i] = tmp.front();
		tmp.pop();
	}

	cout << "<";
	for (int i = 0; i < n; i++)
	{
		if (i == n - 1)
		{
			cout << ans[i] << ">";
		}
		else
		{
			cout << ans[i] << ", ";
		}
	}
	return 0;
}