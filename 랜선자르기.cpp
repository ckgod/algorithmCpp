#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int n;
int ndL;
ll LL[10000];
ll ans;

bool check(ll mL, int need)
{
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		cnt += LL[i] / mL;
	}
	if (cnt >= need)
	{
		ans = mL;
		return true;
	}
	else return false;
}

int maxL(ll l, ll r, int need)
{
	ll left = l;
	ll right = r;
	while (left <= right)
	{
		ll mid = (left + right) / 2;
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

ll jL;

int main()
{
	cout.tie(0);
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> ndL;
	for (int i = 0; i < n; i++)
	{
		cin >> LL[i];
		jL = max(LL[i], jL);
	}

	cout << maxL(1, jL, ndL);
	return 0;
}