#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long

int n, c;
vector<ll> x;
ll maxD;
ll ans;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		ll t;
		cin >> t;
		x.push_back(t);
		maxD = max(t, maxD);
	}
	sort(x.begin(), x.end());
	ll left = 1;
	ll right = x[n-1];
	ll mid = (left + right) / 2;

	while (right >= left)
	{
		mid = (left + right) / 2;
		ll curP = x[0];
		int cnt = 1;
		for (int i = 1; i < x.size(); i++) {
			ll dis = x[i] - curP;
			if (dis >= mid) {
				curP = x[i];
				cnt++;
			}
		}
		if (cnt < c) {
			right = mid - 1;
		}
		else {
			ans = mid;
			left = mid + 1;
		}
	}
	cout << ans;

	return 0;
}