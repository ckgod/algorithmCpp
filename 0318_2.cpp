#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define INF 99999999

int n, m;
int map[301][301];
bool visit[301][301];
int dis[301][301];
int cnt;
int mx[] = { 0,1 };
int my[] = { 1,0 };
queue<pair<int, int>> q;
int result = INF;
int curN2O = 0;

void init() {
	for (int i = 0; i < 301; i++) {
		for (int j = 0; j < 301; j++) {
			dis[i][j] = INF;
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	init();
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	q.push({ 0,0 });
	dis[0][0] = 0;
	visit[0][0] = true;
	while (!q.empty()) {
		int curx = q.front().first;
		int cury = q.front().second;
		curN2O = map[curx][cury];
		q.pop();
		
		for (int i = 0; i < 2; i++) {
			int nextx = curx;
			int nexty = cury;
			for (int j = 0; j < curN2O; j++) {
				nextx += mx[i];
				nexty += my[i];
				if (visit[nextx][nexty] == true || nextx >= n || nexty >= m) {
					continue;
				}
				q.push({ nextx,nexty });
				visit[nextx][nexty] = true;
				dis[nextx][nexty] = min(dis[curx][cury] + 1, dis[nextx][nexty]);
			}
		}
	}
	cout << dis[n - 1][m - 1];


	return 0;
}