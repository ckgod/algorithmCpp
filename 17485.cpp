#include <iostream>
#include <algorithm>
using namespace std;
#define INF 99999999
#define vertical 0
#define rdgs 1
#define ldgs 2

int n, m;
int map[1001][1001];
int dp[1001][1001];
int ans = INF;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 1; i <= m; i++) {
		dp[1][i].first = map[1][i];
	}
	for (int i = 1; i <= m; i++) {
		if (i == 1) {
			dp[2][i] = map[2][i] + min(map[1][i + 1], map[1][i]);
		}
		else if (i == m) {
			dp[2][i] = map[2][i] + min(map[1][i - 1], map[1][i]);
		}
		else {
			dp[2][i] = map[2][i] + min(map[1][i - 1], min(map[1][i], map[1][i + 1]));
		}
	}

	for (int i = 3; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (j == 1) {
				int tc[3];
				int minT = INF;
				tc[0] = dp[i - 2][j] + map[i - 1][j + 1];
				tc[1] = dp[i - 2][j + 1] + map[i - 1][j];
				tc[2] = dp[i - 2][j + 1] + map[i - 1][j + 1];
				for (int k = 0; k < 3; k++) {
					minT = min(minT, tc[k]);
				}
				dp[i][j] = map[i][j] + minT;
			}
			else if (j == m) {
				int tc[3];
				int minT = INF;
				tc[0] = dp[i - 2][j - 1] + map[i - 1][j - 1];
				tc[1] = dp[i - 2][j - 1] + map[i - 1][j];
				tc[2] = dp[i - 2][j] + map[i - 1][j - 1];
				for (int k = 0; k < 3; k++) {
					minT = min(minT, tc[k]);
				}
				dp[i][j] = map[i][j] + minT;
			}
			else {
				int tc[6];
				int minT = INF;
				tc[0] = dp[i - 2][j - 1] + map[i - 1][j - 1];
				tc[1] = dp[i - 2][j - 1] + map[i - 1][j];
				tc[2] = dp[i - 2][j] + map[i - 1][j - 1];
				tc[3] = dp[i - 2][j] + map[i - 1][j + 1];
				tc[4] = dp[i - 2][j + 1] + map[i - 1][j];
				tc[5] = dp[i - 2][j + 1] + map[i - 1][j + 1];
				for (int k = 0; k < 6; k++) {
					minT = min(minT, tc[k]);
				}
				dp[i][j] = map[i][j] + minT;
			}
		}
	}
	
	for (int i = 1; i <= m; i++) {
		ans = min(ans, dp[n][i]);
	}
	cout << ans;


	return 0;
}