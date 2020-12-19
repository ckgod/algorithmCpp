#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int a, b, d, n;
int ans, cal, tmp;
int dp[10001];

int idx(int a, int b) {
	return (a + b) % 10001;
}

int main() { 
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> a >> b >> d >> n;

	dp[1] = 1;
	ans = 1;
	tmp = 1;
	cal = 0;

	for (int i = 1; i <= n; i++) {
		tmp = (tmp - 1 + 10001) % 10001;
		cal = (cal + dp[idx(a, tmp)] - dp[idx(b, tmp)] + 1000) % 1000;
		dp[tmp] = cal;
		ans = (ans - dp[idx(d, tmp)] + dp[tmp] + 1000) % 1000;
		dp[idx(d, tmp)] = 0;
	}
	cout << ans;
	return 0;
}