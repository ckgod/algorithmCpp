#include <iostream>
#include <algorithm>
using namespace std;

long long dp[1001][10];
int n;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < 10; i++) {
		dp[1][i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 10; k++) {
				if (j <= k) {
					dp[i][j] += dp[i-1][k]%10007;
				}
			}
		}
	}
	long long result = 0;
	for (int i = 0; i < 10; i++) {
		result += dp[n][i];
	}

	cout << result % 10007;

	return 0;
}