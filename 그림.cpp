#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int mx[] = { 0,0,1,-1 };
int my[] = { 1,-1,0,0 };
int visit[501][501];
int paper[501][501];
int n, m;
int cnt;
int maxB;
int tmpB;

void dfs(int x, int y) {
	if (visit[x][y]) return;
	visit[x][y] = true;
	tmpB++;
	for (int i = 0; i < 4; i++) {
		int nx = x + mx[i];
		int ny = y + my[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
		if (visit[nx][ny]) continue;
		if (paper[nx][ny] == 0) continue;
		dfs(nx, ny);
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> paper[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visit[i][j] && paper[i][j] == 1) {
				dfs(i, j);
				cnt++;
				maxB = max(tmpB, maxB);
				tmpB = 0;
			}
		}
	}
	cout << cnt << "\n" << maxB;

	return 0;
}