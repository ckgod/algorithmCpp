#include <iostream>
using namespace std;

int n, k;
long long dp[1001][1001];
long long dpc[1001][1001];

long long nCk(int n, int k)
{
	if (dp[n][k] > 0) return dp[n][k];
	if (k == 0 || n == k)
	{
		return dp[n][k] = 1;
	}

	return dp[n][k] = (nCk(n - 1, k - 1) + nCk(n - 1, k));
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> k;
	cout << nCk(n, k);

	return 0;
}