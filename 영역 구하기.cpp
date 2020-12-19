#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, k;
vector<int> ans;
int mp[101][101];
bool visit[101][101];
int mx[] = { 0,0,1,-1 };
int my[] = { 1,-1,0,0 };
int stB = 0;
int cnt = 0;

void dfs(int x, int y) {
	if (visit[x][y]) return;
	visit[x][y] = true;
	stB++;
	for (int i = 0; i < 4; i++) {
		int nx = x + mx[i];
		int ny = y + my[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
		if (visit[nx][ny]) continue;
		if (mp[nx][ny] == 0) {
			dfs(nx, ny);
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		for (int j = b; j <= d-1; j++) {
			for (int k = a; k <= c - 1; k++) {
				mp[j][k]++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mp[i][j] == 0 && !visit[i][j]) {
				dfs(i, j);
				cnt++;
				ans.push_back(stB);
				stB = 0;
			}
		}
	}
	sort(ans.begin(), ans.end());
	cout << cnt << "\n";
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}

	return 0;
}