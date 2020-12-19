#include <iostream>
#include <algorithm>
using namespace std;


int st[10001];
int dp[10001][3]; 
int n;


int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;
	st[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> st[i];
	}
	dp[1][1] = st[1];
	dp[1][2] = st[1];
	dp[2][2] = st[1] + st[2];
	dp[2][1] = max(st[1], st[2]);
	for (int i = 3; i <= n; i++) {
		dp[i][1] = max(max(dp[i - 1][2], dp[i - 2][1] + st[i]), dp[i - 2][2] + st[i]);
		dp[i][2] = dp[i - 1][1] + st[i];
	}
	int result = max(dp[n][1], dp[n][2]);
	cout << result;

	return 0;
}