#include <iostream>
#include <algorithm>
using namespace std;

int pri[10001];
int n;
int total;
int li;
int ans;

bool check(int limit, int t)
{
	for (int i = 0; i < n; i++)
	{
		if (limit < pri[i])
		{
			t -= limit;
		}
		else if (limit >= pri[i])
		{
			t -= pri[i];
		}
	}
	if (t < 0)
	{
		return false;
	}
	else
	{
		ans = limit;
		return true;
	}
}


int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> pri[i];
	}
	sort(pri, pri + n);
	cin >> total;

	int left = 0;
	int right = pri[n-1];

	while (left<=right)
	{
		int mid = (left + right) / 2;

		if (check(mid, total) == true)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	cout << ans;

	return 0;
}