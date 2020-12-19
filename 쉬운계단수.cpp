#include <iostream>
#include <algorithm>
using namespace std;
#define m 1000000000

long long dp[101][10];
int n;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i < 10; i++) {
		dp[1][i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0) {
				dp[i][j] = dp[i - 1][j + 1] % m;
			}
			else if (j == 9) {
				dp[i][j] = dp[i - 1][j - 1] % m;
			}
			else {
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % m;
			}
		}
	}

	long long result = 0;
	for (int i = 0; i < 10; i++) {
		result += dp[n][i];
	}
	cout << result % m;
	return 0;
}