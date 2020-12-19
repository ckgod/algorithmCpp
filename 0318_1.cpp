#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, q;
int arr[300001];
int l, r;
int dp[300001];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	dp[0] = arr[0];
	for (int i = 1; i < n; i++) {
		dp[i] += arr[i] + dp[i - 1];
	}

	while (q--) {
		int result = 0;
		cin >> l >> r;
		if (l == 1) {
			result = dp[r-1];
		}
		else {
			result = dp[r - 1] - dp[l - 2];
		}
		cout << result << "\n";
	}

	return 0;
}