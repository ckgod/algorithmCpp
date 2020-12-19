#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int mx[] = { 0,0,1,-1 };
int my[] = { 1,-1,0,0 };
int visit[51][51];
int paper[51][51];
int n, m, t, k;
int cnt;

void init() {
	for (int i = 0; i < 51; i++) {
		for (int j = 0; j < 51; j++) {
			visit[i][j] = false;
			paper[i][j] = 0;
		}
	}
	cnt = 0;
}

void dfs(int x, int y) {
	if (visit[x][y]) return;
	visit[x][y] = true;
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
	cin >> t;
	while (t--) {
		cin >> n >> m >> k;
		for (int i = 0; i < k; i++) {
			int a, b;
			cin >> a >> b;
			paper[a][b] = 1;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!visit[i][j] && paper[i][j] == 1) {
					dfs(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << "\n";
		init();
	}
	

	return 0;
}