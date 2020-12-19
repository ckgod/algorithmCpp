#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

int r, c;
char board[1501][1501];
bool visit[1501][1501];
bool Rvisit[1501][1501];
int day[1501][1501];
pair<int, int> fl, sl;
bool checkf = false;
int mx[] = { 0,0,1,-1 };
int my[] = { 1,-1,0,0 };
queue<pair<int, int>> Rq;
int cnt;

void init(int r, int c) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			visit[i][j] = false;
		}
	}
}

bool checkArrive(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x,y });
	visit[x][y] = true;
	while (!q.empty()) {
		int curx = q.front().first;
		int cury = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nextx = curx + mx[i];
			int nexty = cury + my[i];
			if (nextx < 0 || nexty < 0 || nextx >= r || nexty >= c) continue;
			if (visit[nextx][nexty]) continue;
			if (board[nextx][nexty] == 'X') continue;
			if (board[nextx][nexty] == 'L' && nextx == sl.first && nexty == sl.second) {
				init(r,c);
				return true;
			}
			visit[nextx][nexty] = true;
			q.push({ nextx,nexty });
		}
	}
	init(r, c);
	return false;
}

void dayPlus(int x, int y) {
	while (!Rq.empty()) {
		int curx = Rq.front().first;
		int cury = Rq.front().second;
		Rq.pop();
		for (int i = 0; i < 4; i++) {
			int nextx = curx + mx[i];
			int nexty = cury + my[i];
			if (nextx < 0 || nexty < 0 || nextx >= r || nexty >= c) continue;
			if (Rvisit[nextx][nexty]) continue;
			if (board[nextx][nexty] == 'X') {
				Rq.push({ nextx,nexty });
				day[nextx][nexty] = day[curx][cury] + 1;
				Rvisit[nextx][nexty] = true;
			}
			else {
				Rq.push({ nextx,nexty });
				Rvisit[nextx][nexty] = true;
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		string str;
		for (int j = 0; j < c; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'L' && !checkf) {
				fl.first = i;
				fl.second = j;
				checkf = true;
			}
			else if (board[i][j] == 'L' && checkf) {
				sl.first = i;
				sl.second = j;
			}
		}
	}

	//while (!checkArrive(fl.first, fl.second)) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (board[i][j] == '.' && Rvisit[i][j] == false) {
				Rq.push({ i,j });
				Rvisit[i][j] = true;
				dayPlus(i, j);
			}
		}
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << day[i][j];
		}
		cout << endl;
	}

	//}
	//cout << checkArrive(fl.first, fl.second);

	return 0;
}