#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define vertical 1
#define horizontal 0

int n, m;
char map[26][26];
queue<pair<int, int>> q;
bool curState;
int mx[] = { 0,0,1,-1 };
int my[] = { 1,-1,0,0 };

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'M') {
				q.push({ i,j });
			}
		}
	}
	while (!q.empty()) {
		int curx = q.front().first;
		int cury = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nextx = curx + mx[i];
			int nexty = cury + my[i];

		}
	}


	return 0;
}