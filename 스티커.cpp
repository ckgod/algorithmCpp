#include <iostream>
#include <algorithm>
using namespace std;

int st[2][100001];
int dp[2][100001];
int tc;
int n;


int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> tc;

	while (tc--)
	{
		cin >> n;
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> st[i][j];
			}
		}
		dp[0][0] = st[0][0];
		dp[1][0] = st[1][0];
		dp[0][1] = dp[1][0] + st[0][1];
		dp[1][1] = dp[0][0] + st[1][1];
		for (int i = 2; i < n; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				if (j == 0)
				{
					dp[j][i] = max(dp[j + 1][i - 1],dp[j + 1][i - 2]) + st[j][i];
				}
				else
				{
					dp[j][i] = max(dp[j - 1][i - 1], dp[j - 1][i - 2]) + st[j][i];
				}
			}
		}
		cout << max(max(dp[0][n - 1], dp[0][n - 2]), max(dp[1][n - 1], dp[1][n - 2])) << "\n";
	}

	return 0;
}