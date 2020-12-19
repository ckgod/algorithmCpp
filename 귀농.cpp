#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define INF 99999999

int n, K;
int light[201];
int dp[201][201];

void init() {
	for (int i = 0; i < 201; i++) {
		for (int j = 0; j < 201; j++) {
			if (i == j) {
				dp[i][j] = 0;
			}
			else {
				dp[i][j] = INF;
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	init();
	cin >> n >> K;
	for (int i = 1; i <= n; i++) {
		cin >> light[i];
	}
	for (int i = 1; i < n; i++) {
		if (light[i] == light[i + 1]) {
			dp[i][i + 1] = 0;
		}
		else {
			dp[i][i + 1] = 1;
		}
	}

	int size = 2;
	while (1) {
		if (n == 1) break;
		for (int i = 1; i <= n - size; i++) {
			for (int j = 0; j < size; j++) {
				if (light[i] != light[i + size]) {
					dp[i][i + size] = min(dp[i][i + size], dp[i][i + j] + dp[i + j + 1][i + size] + 1);
				}
				else {
					dp[i][i + size] = min(dp[i][i + size], dp[i][i + j] + dp[i + j + 1][i + size]);
				}
			}
		}
		if (size == n - 1) break;
		size++;
	}

	cout << dp[1][n];



	return 0;
}