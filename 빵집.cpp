#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int r, c;
char map[10001][501];
bool visit[10001][501];
int path[10001][501];
queue<pair<int,pair<int, int>>> startBread;
int mx[] = { -1,0,1 };
int my[] = { 1,1,1 };
int cnt;

bool flag = false;

void dfs(int x, int y, int point) {
	if (visit[x][y]) return;
	if (flag) {
		return;
	}
	visit[x][y] = true;
	int curx = x;
	int cury = y;
	for (int i = 0; i < 3; i++) {
		if (flag) break;
		int nextx = curx + mx[i];
		int nexty = cury + my[i];
		if (nextx < 0 || nexty < 0 || nextx >= r || nexty >= c) continue;
		if (map[nextx][nexty] == 'x') continue;
		if (visit[nextx][nexty]) continue;
		path[nextx][nexty] = point;
		if (nexty == c - 1) {
			flag = true;
			cnt++;
			return;
		}
		dfs(nextx, nexty, point);
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];
			if (j == 0) {
				startBread.push({ i+1,{ i,j } });
			}
		}
	}

	for (int i = 0; i < r; i++) {
		dfs(i, 0, i + 1);
		flag = false;
	}
	
	
	cout << cnt;

	return 0;
}