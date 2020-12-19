#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int t;
int n;
int sx, sy;
int ex, ey;
int map[301][301];
bool visit[301][301];
int countM[301][301];
int mx[] = { -2,-2,-1,-1,1,1,2,2 };
int my[] = { -1,1,-2,2,-2,2,-1,1 };

void init() {
	for (int i = 0; i < 301; i++) {
		for (int j = 0; j < 301; j++) {
			visit[i][j] = false;
			countM[i][j] = 0;
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> t;
	while (t--) {
		cin >> n;
		cin >> sx >> sy;
		cin >> ex >> ey;
		queue<pair<int, int>> q;
		q.push({ sx,sy });
		visit[sx][sy] = true;
		while (!q.empty()) {
			int curx = q.front().first;
			int cury = q.front().second;
			q.pop();

			for (int i = 0; i < 8; i++) {
				int nextx = curx + mx[i];
				int nexty = cury + my[i];
				if (nextx < 0 || nexty < 0 || nextx >= n || nexty >= n) {
					continue;
				}
				if (visit[nextx][nexty]) continue;
				visit[nextx][nexty] = true;
				q.push({ nextx,nexty });
				countM[nextx][nexty] = countM[curx][cury] + 1;
			}
		}
		
		cout << countM[ex][ey] << "\n";
		init();
	}


	return 0;
}