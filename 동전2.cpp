#include <iostream>
#include <algorithm>
using namespace std;


int n, k;
int c[101];
int me[10001];

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> k;

	for (int i = 1; i <= k; i++)
	{
		me[i] = 100001;
	}

	for (int i = 0; i < n; i++)
	{
		cin >> c[i];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = c[i]; j <= k; j++)
		{
			me[j] = min(me[j], me[j - c[i]] + 1);
		}
	}
	if (me[k] == 100001)
	{
		cout << "-1";
	}
	else
	{
		cout << me[k];
	}

	return 0;
}