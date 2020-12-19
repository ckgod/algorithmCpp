#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n;
char map[101][101];
bool visit[101][101];
int normal[101][101];
int sick[101][101];
int mx[] = { 0,0,1,-1 };
int my[] = { 1,-1,0,0 };
int cnt;
queue<pair<int, int>> st;


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	queue<pair<int, int>> q;
	q.push({ 0,0 });
	visit[0][0] = true;

	while (!q.empty()) {
		int startx = q.front().first;
		int starty = q.front().second;
		q.pop();
		cnt++;
		st.push({ startx,starty });
		while (!st.empty()) {
			int curx = st.front().first;
			int cury = st.front().second;
			char curClr = map[curx][cury];
			st.pop();
			for (int i = 0; i < 4; i++) {
				int nextx = curx + mx[i];
				int nexty = cury + my[i];
				if (nextx < 0 || nexty > 0 || nextx >= n || nexty >= n) continue;
				if (visit[nextx][nexty]) continue;
				if (map[nextx][nexty] != curClr) {
					q.push({ nextx,nexty });
					visit[nextx][nexty] = true;
					continue;
				}
				visit[nextx][nexty] = true;
				st.push({ nextx,nexty });
			}
		}
	}
	cout << cnt;

	return 0;
}