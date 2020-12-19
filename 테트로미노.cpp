#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int board[501][501];
int n, m;

int mx[] = { 0,0,1,-1,-1,1,-1 };
int my[] = { 1,-1,0,0,1,-1,-1 };

// 막대기
int t1[2][3] = { { 0,0,0 },{2,2,2} };
// 정사각형
int t2[3] = { 0,2,1 };
// 기억자
int t3[8][3] = { { 2,2,0 },{2,2,1},{3,3,0},{3,3,1},{2,0,0},{0,0,3},{3,0,0},{0,0,2} };
// 빠큐모양
int t4[4][3] = { {0,0,6},{0,0,5},{2,2,6},{2,2,4} };
// 지렁이모양
int t5[4][3] = { {2,0,2},{2,1,2},{0,2,0},{0,3,0} };

// 다합친거
int t6[19][3] = { { 0,0,0 },{2,2,2},{ 0,2,1 },{ 2,2,0 },
				{2,2,1},{3,3,0},{3,3,1},{2,0,0},{0,0,3},{3,0,0},{0,0,2},
				{0,0,6},{0,0,5},{2,2,6},{2,2,4},{2,0,2},{2,1,2},{0,2,0},
				{0,3,0} };

int maxN;

void sumN(int num) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int sum = board[i][j];
			int curx = i;
			int cury = j;
			for (int k = 0; k < 3; k++) {
				int nextx = curx + mx[t6[num][k]];
				int nexty = cury + my[t6[num][k]];
				if (nextx < 0 || nexty < 0 || nextx >= n || nexty >= m) break;
				sum += board[nextx][nexty];
				curx = nextx;
				cury = nexty;
			}
			maxN = max(sum, maxN);
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < 19; i++) {
		sumN(i);
	}
	cout << maxN;


	return 0;
}