#include <iostream>
using namespace std;


int n;
long long dp[91];

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;
	dp[1] = 1, dp[2] = 1, dp[3] = 2;

	for (int i = 4; i <= n; i++)
	{
		for (int j = 1; j <= i - 2; j++)
		{
			dp[i] += dp[j];
		}
		dp[i]++;
	}

	cout << dp[n];




	return 0;
}