#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;


int n, m, Q;
char map[1001][1001];
int nodeNum[1001][1001];
bool visit[1001][1001];
int tCnt[1001][1001];
int s1, s2, e1, e2;
vector<int> graph[1000001];

int mx[] = { 0,0,1,-1 };
int my[] = { 1,-1,0,0 };//©Л,аб,го,╩С

void init() {
	int num = 1;
	for (int i = 1; i <= 1000; i++) {
		for (int j = 1; j <= 1000; j++) {
			nodeNum[i][j] = num;
			num++;
		}
	}
}


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	init();

	cin >> n >> m >> Q;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'D') {
				if (i - 1 >= 1 && i - 1 <= n && j >= 1 && j <= m) {
					graph[nodeNum[i][j]].push_back(nodeNum[i - 1][j]);
				}
				if (i >= 1 && i <= n && j >= 1 && j <= m) {
					graph[nodeNum[i][j]].push_back(nodeNum[i][j - 1]);
				}
				if (i >= 1 && i <= n && j + 1 >= 1 && j + 1 <= m) {
					graph[nodeNum[i][j]].push_back(nodeNum[i][j + 1]);
				}
			}
			else if (map[i][j] == 'R') {
				if (i - 1 >= 1 && i - 1 <= n && j >= 1 && j <= m) {
					graph[nodeNum[i][j]].push_back(nodeNum[i - 1][j]);
				}
				if (i + 1 >= 1 && i + 1 <= n && j >= 1 && j <= m) {
					graph[nodeNum[i][j]].push_back(nodeNum[i + 1][j]);
				}
				if (i >= 1 && i <= n && j >= 1 && j <= m) {
					graph[nodeNum[i][j]].push_back(nodeNum[i][j - 1]);
				}
			}
			else if (map[i][j] == 'L') {
				if (i - 1 >= 1 && i - 1 <= n && j >= 1 && j <= m) {
					graph[nodeNum[i][j]].push_back(nodeNum[i - 1][j]);
				}
				if (i + 1 >= 1 && i + 1 <= n && j >= 1 && j <= m) {
					graph[nodeNum[i][j]].push_back(nodeNum[i + 1][j]);
				}
				if (i >= 1 && i <= n && j + 1 >= 1 && j + 1 <= m) {
					graph[nodeNum[i][j]].push_back(nodeNum[i][j + 1]);
				}
			}
			else if (map[i][j] == 'U') {
				if (i + 1 >= 1 && i + 1 <= n && j >= 1 && j <= m) {
					graph[nodeNum[i][j]].push_back(nodeNum[i + 1][j]);
				}
				if (i >= 1 && i <= n && j >= 1 && j <= m) {
					graph[nodeNum[i][j]].push_back(nodeNum[i][j - 1]);
				}
				if (i >= 1 && i <= n && j + 1 >= 1 && j + 1 <= m) {
					graph[nodeNum[i][j]].push_back(nodeNum[i][j + 1]);
				}
			}
		}
	}
	while (Q--) {
		cin >> s1 >> s2 >> e1 >> e2;
		int cnt = 0;
		queue<pair<int, int>> q;
		q.push({ s1,s2 });

		visit[s1][s2] = true;
		tCnt[s1][s2] = 1;
		while (!q.empty()) {
			int curx = q.front().first;
			int cury = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nextx = curx + mx[i];
				int nexty = cury + my[i];
				if (nextx < 1 || nexty < 1 || nextx > n || nexty > m) continue;
				if (map[curx][cury] == 'R' && i == 0) continue;
				else if (map[curx][cury] == 'L' && i == 1) continue;
				else if (map[curx][cury] == 'D' && i == 2) continue;
				else if (map[curx][cury] == 'U' && i == 3) continue;
				if (visit[nextx][nexty]) continue;
				visit[nextx][nexty] = true;
				q.push({ nextx,nexty });
				tCnt[nextx][nexty]++;
			}
		}
		if (tCnt[e1][e2] == 0) {
			cout << 0 << "\n";
		}
		else {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= m; j++) {
					//cout << tCnt[i][j] << " ";
					if (tCnt[i][j] == 1) {
						cnt++;
					}
					tCnt[i][j] = 0;
					visit[i][j] = false;
				}
				//cout << endl;
			}
			cout << cnt << "\n";
		}
	}

	return 0;
}