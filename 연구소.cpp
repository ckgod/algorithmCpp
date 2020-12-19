#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
int map[9][9];
bool visit[9][9];
int virus[9][9];
queue<pair<int, int>> q;
int mx[] = { 0,0,1,-1 };
int my[] = { 1,-1,0,0 };
int safeZone;
int ans;
vector<pair<int, int>> pos;
vector<int> combi;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			virus[i][j] = map[i][j];
			if (map[i][j] == 0) {
				pos.push_back({ i,j });
			}
			if (map[i][j] == 2) {
				q.push({ i,j });
				visit[i][j] = true;
			}
		}
	}
	for (int i = 0; i < pos.size(); i++) {
		if (i < 3) {
			combi.push_back(1);
		}
		else {
			combi.push_back(0);
		}
	}
	sort(combi.begin(), combi.end());

	do {
		for (int i = 0; i < combi.size(); i++) {
			if (combi[i] == 1) {
				map[pos[i].first][pos[i].second] = 1;
			}
		}
		while (!q.empty()) {
			int curx = q.front().first;
			int cury = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nextx = curx + mx[i];
				int nexty = cury + my[i];
				if (nextx < 0 || nexty < 0 || nextx >= n || nexty >= m) continue;
				if (visit[nextx][nexty]) continue;
				if (map[nextx][nexty] == 1) continue;
				visit[nextx][nexty] = true;
				q.push({ nextx,nexty });
				map[nextx][nexty] = 2;
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] == 0) safeZone++;
				map[i][j] = virus[i][j];
				visit[i][j] = false;
				if (map[i][j] == 2) {
					q.push({ i,j });
					visit[i][j] = true;
				}
			}
		}
		ans = max(ans, safeZone);
		safeZone = 0;
	} while (next_permutation(combi.begin(), combi.end()));

	
	cout << ans;


	return 0;
}