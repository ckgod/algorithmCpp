#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int m, n;
int map[31][31];
int dp[31][31][31][31];
int bangSuk[31][31];
long long cnt[31][31];
int s1, s2, e1, e2;

int mx[8] = { -2,-2,-1,-1,1,1,2,2 };
int my[8] = { -1,1,-2,2,-2,2,-1,1 };
queue<pair<int, int> > q;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 3) {
				map[i][j] = 0;
				s1 = i;
				s2 = j;
			}
			if (map[i][j] == 4) {
				map[i][j] = 0;
				e1 = i;
				e2 = j;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 0) {
				q.push({ i, j });
				dp[i][j][i][j] = 1;
				while (!q.empty()) {
					int curx = q.front().first;
					int cury = q.front().second;
					q.pop();
					for (int k = 0; k < 8; k++) {
						int nextx = curx + mx[k];
						int nexty = cury + my[k];
						if (nextx < 0 || nexty < 0 || nextx >= m || nexty >= n) continue;
						if (map[nextx][nexty] == 1) {
							q.push({ nextx, nexty });
							dp[i][j][nextx][nexty] = 1;
						}
					}
				}
				for (int r = 0; r < m; r++) {
					for (int l = 0; l < n; l++) {
						if (dp[i][j][r][l] == 1) {
							for (int k = 0; k < 8; k++)
							{
								int xpos = r + mx[k];
								int ypos = l + my[k];
								if (xpos < 0 || ypos < 0 || xpos >= m || ypos >= n) continue;
								if (map[xpos][ypos] == 0 && dp[i][j][xpos][ypos] == 0) {
									dp[i][j][xpos][ypos] = 2;
								}
							}
						}
					}
				}
			}
		}
	}


	for (int i = 0; i < 31; i++) {
		for (int j = 0; j < 31; j++) {
			bangSuk[i][j] = -1;
		}
	}

	bangSuk[s1][s2] = 0;
	cnt[s1][s2] = 1;
	q.push({ s1, s2 });

	while (!q.empty()) {
		int curx = q.front().first;
		int cury = q.front().second;
		q.pop();
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (dp[curx][cury][i][j] == 2) {
					if (bangSuk[i][j] == -1) {
						bangSuk[i][j] = bangSuk[curx][cury] + 1;
						cnt[i][j] = cnt[curx][cury];
						q.push({ i, j });
					}
					else {
						if (bangSuk[i][j] == bangSuk[curx][cury] + 1) {
							cnt[i][j] += cnt[curx][cury];
						}
					}
				}
			}
		}
	}

	if (bangSuk[e1][e2] == -1) {
		cout << -1 << endl;
	}
	else {
		cout << bangSuk[e1][e2] - 1 << endl << cnt[e1][e2] << endl;
	}

	return 0;
}