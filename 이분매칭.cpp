#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int r, c;
char map[51][51];
bool visit[51][51];
int dist[51][51];
int dp[51][51];
vector<pair<int, int>> car;
vector<pair<int, int>> park;
int mx[] = { 0,0,1,-1 };
int my[] = { 1,-1,0,0 };

void init() {
	for (int i = 0; i < 51; i++) {
		for (int j = 0; j < 51; j++) {
			dist[i][j] = 0;
			visit[i][j] = false;
		}
	}
}

void bfs(int sx, int sy) {
	queue<pair<int, int>> q;
	q.push({ sx,sy });
	visit[sx][sy] = true;
	while (!q.empty()) {
		int curx = q.front().first;
		int cury = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nextx = curx + mx[i];
			int nexty = cury + my[i];
			if (nextx < 0 || nexty < 0 || nextx >= r || nexty >= c) continue;
			if (visit[nextx][nexty]) continue;
			if (map[nextx][nexty] == '.') continue;
			visit[nextx][nexty] = true;
			q.push({ nextx,nexty });
			dist[nextx][nexty] = dist[curx][cury] + 1;
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'C') {
				car.push_back({ i,j });
			}
			else if (map[i][j] == 'P') {
				park.push_back({ i,j });
			}
		}
	}

	for (int i = 0; i < car.size(); i++) {
		bfs(car[i].first, car[i].second);
		for (int j = 0; j < park.size(); j++) {
			dp[i][j] = dist[park[j].first][park[j].second];
		}
		for (int k = 0; k < r; k++) {
			for (int l = 0; l < c; l++) {
				cout << dist[k][l] << " ";
			}
			cout << endl;
		}
		cout << endl;
		init();
	}

	/*for (int i = 0; i < car.size(); i++) {
		for (int j = 0; j < park.size(); j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}*/




	return 0;
}