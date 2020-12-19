#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define horizontal 1
#define vertical 2
#define dgs 3

int n;
int map[17][17];
bool visit[17][17];
int result[17][17];
int curState = 1;
int cnt;
pair<int, int> moveRight = { 0,1 };
pair<int, int> moveDown = { 1,0 };
pair<int, int> moveDiagonal = { 1,1 };


bool checkE(int x, int y, int n) {
	if (x >= n || y >= n) return true;
	else return false;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	queue<pair<int, pair<int, int>>> q;
	q.push({ curState,{0,1} });
	while (!q.empty()) {
		int curx = q.front().second.first;
		int cury = q.front().second.second;
		int state = q.front().first;

		q.pop();

		result[curx][cury]++;

		int nextx;
		int nexty;

		if (state == horizontal) { // 가로
			for (int i = 0; i < 2; i++) {
				if (i == 0) {
					nextx = curx + moveRight.first;
					nexty = cury + moveRight.second;
					state = horizontal;

					if (checkE(nextx, nexty, n)) continue;
					if (map[nextx][nexty] == 1) continue;

					
					q.push({ state,{nextx,nexty} });
				}
				else {
					nextx = curx + moveDiagonal.first;
					nexty = cury + moveDiagonal.second;
					state = dgs;

					if (checkE(nextx, nexty, n)) continue;
					if (map[nextx][nexty] == 1 || 
						map[nextx-1][nexty] == 1 || 
						map[nextx][nexty-1] == 1) continue;

					q.push({ state,{nextx,nexty} });
				}
			}
		}
		else if (state == vertical) { // 세로
			for (int i = 0; i < 2; i++) {
				if (i == 0) {
					nextx = curx + moveDown.first;
					nexty = cury + moveDown.second;
					state = vertical;

					if (checkE(nextx, nexty, n)) continue;
					if (map[nextx][nexty] == 1) continue;


					q.push({ state,{nextx,nexty} });
				}
				else {
					nextx = curx + moveDiagonal.first;
					nexty = cury + moveDiagonal.second;
					state = dgs;

					if (checkE(nextx, nexty, n)) continue;
					if (map[nextx][nexty] == 1 ||
						map[nextx - 1][nexty] == 1 ||
						map[nextx][nexty - 1] == 1) continue;

					q.push({ state,{nextx,nexty} });
				}
			}
		}
		else if (state == dgs) { // 대각선
			for (int i = 0; i < 3; i++) {
				if (i == 0) {
					nextx = curx + moveRight.first;
					nexty = cury + moveRight.second;
					state = horizontal;

					if (checkE(nextx, nexty, n)) continue;
					if (map[nextx][nexty] == 1) continue;


					q.push({ state,{nextx,nexty} });
				}
				else if (i == 1) {
					nextx = curx + moveDown.first;
					nexty = cury + moveDown.second;
					state = vertical;

					if (checkE(nextx, nexty, n)) continue;
					if (map[nextx][nexty] == 1) continue;


					q.push({ state,{nextx,nexty} });
				}
				else {
					nextx = curx + moveDiagonal.first;
					nexty = cury + moveDiagonal.second;
					state = dgs;

					if (checkE(nextx, nexty, n)) continue;
					if (map[nextx][nexty] == 1 ||
						map[nextx - 1][nexty] == 1 ||
						map[nextx][nexty - 1] == 1) continue;

					q.push({ state,{nextx,nexty} });
				}
			}
		}
	}
	
	cout << result[n - 1][n - 1];

	return 0;
}