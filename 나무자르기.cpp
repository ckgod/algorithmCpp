#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int n;
ll ndh;
int hi[1000001];
int ans;

bool check(int limit, ll need)
{
	ll cutN = 0;
	for (int i = 0; i < n; i++)
	{
		if (hi[i] > limit)
		{
			cutN += hi[i] - limit;
		}
	}
	if (cutN >= need)
	{
		ans = limit;
		return true;
	}
	else return false;
}

int maxH(int l, int r, ll need)
{
	int left = l;
	int right = r;
	while (right >= left)
	{
		int mid = (left + right) / 2;
		if (check(mid, need) == true)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	return ans;
}

int jN;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> ndh;
	for (int i = 0; i < n; i++)
	{
		cin >> hi[i];
		jN = max(hi[i], jN);
	}
	cout << maxH(0, jN, ndh);

	return 0;
}