#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
int map[1001][1001];
int dp[1001][1001];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
		}
	}
	dp[1][1] = map[1][1];
	for (int i = 2; i <= m; i++) {
		dp[1][i] = map[1][i] + dp[1][i - 1];
	}
	for (int i = 2; i <= n; i++) {
		dp[i][1] = map[i][1] + dp[i - 1][1];
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= m; j++) {
			dp[i][j] = map[i][j] + max(dp[i][j - 1], max(dp[i - 1][j], dp[i - 1][j - 1]));
		}
	}
	cout << dp[n][m];

	return 0;
}
