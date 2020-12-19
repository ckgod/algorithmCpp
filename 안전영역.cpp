#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int mp[101][101];
bool visit[101][101];
int cnt;
int maxH = 0;
int mx[] = { 0,0,1,-1 };
int my[] = { 1,-1,0,0 };
int ans = 1;

void dfs(int x, int y, int h) {
	if (visit[x][y]) return;
	visit[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + mx[i];
		int ny = y + my[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
		if (visit[nx][ny]) continue;
		if (mp[nx][ny] > h) {
			dfs(nx, ny, h);
		}
	}
}

void init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visit[i][j] = false;
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mp[i][j];
			maxH = max(maxH, mp[i][j]);
		}
	}
	for (int h = 1; h <= maxH; h++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (mp[i][j] > h && !visit[i][j]) {
					dfs(i, j, h);
					cnt++;
				}
			}
		}
		ans = max(cnt, ans);
		cnt = 0;
		init();
	}
	cout << ans;

	return 0;
}