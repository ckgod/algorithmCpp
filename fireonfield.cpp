#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001];
int n;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n;
	dp[0] = 1; dp[1] = 1;
	for (int i = 2; i <= 1000; i++) {
		int v = 1;
		while (1) {
			dp[i] = v;
			int k = 1;
			bool flag = false;
			while (!flag) {
				if (dp[i] - dp[i - k] == dp[i - k] - dp[i - 2 * k]) break;
				k++;
				if (i - 2 * k < 0) {
					flag = true;
				}
			}
			if (flag) break;
			else v++;
		}
	}

	cout << dp[n];

	return 0;
}