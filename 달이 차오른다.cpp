#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
bool visit[51][51][64];
int dis[51][51][64];
char map[51][51];
int allKey;
queue<pair<int, pair<int, int>>> q;
int sx, sy;
int mx[] = { 0,0,1,-1 };
int my[] = { 1,-1,0,0 };
int ans;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == '0') {
				sx = i;
				sy = j;
			}
			if (map[i][j] >= 'a' && map[i][j] <= 'f') {
				allKey |= (1 << (map[i][j] - 'a'));
			}
		}
	}
	q.push({ 0,{sx,sy} });
	visit[sx][sy][0] = true;
	while (!q.empty()) {
		int curx = q.front().second.first;
		int cury = q.front().second.second;
		int key = q.front().first;
		q.pop();
		if (map[curx][cury] == '1') {
			ans = dis[curx][cury][key];
			cout << ans;
			return 0;
		}
		for (int i = 0; i < 4; i++) {
			int nextx = curx + mx[i];
			int nexty = cury + my[i];
			int nextKey = key;
			if (nextx < 0 || nexty < 0 || nextx >= n || nexty >= m) continue;
			if (visit[nextx][nexty][nextKey]) continue;
			if (map[nextx][nexty] == '#') continue;
			if (map[nextx][nexty] >= 'a' && map[nextx][nexty] <= 'f') {
				nextKey |= (1 << (map[nextx][nexty] - 'a'));
			}
			else if (map[nextx][nexty] >= 'A' && map[nextx][nexty] <= 'F') {
				int check = nextKey & (1 << (map[nextx][nexty] - 'A'));
				if (check == 0) continue;
			}
			visit[nextx][nexty][nextKey] = true;
			q.push({ nextKey,{nextx,nexty} });
			dis[nextx][nexty][nextKey] = dis[curx][cury][key] + 1;
		}
	}
	cout << -1;

	return 0;
}

