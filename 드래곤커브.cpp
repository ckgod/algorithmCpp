#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int n;
int mx[] = { 1,0,-1,0 };
int my[] = { 0,-1,0,1 };
vector<pair<int, int>> spos;
vector<int> dragon[21];
int board[102][102];
int ans;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y, d, a;
		cin >> x >> y >> d >> a;
		spos.push_back({ x,y });
		dragon[i].resize((int)pow(2, a));
		dragon[i][0] = d;
		for (int j = 0; j < a; j++) {
			int leftIndex = 0;
			int rightIndex = (int)pow(2, j + 1) - 1;
			for (int k = 0; k < (int)pow(2, j); k++) {
				if (dragon[i][leftIndex] == 3) {
					dragon[i][rightIndex] = 0;
				}
				else {
					dragon[i][rightIndex] = dragon[i][leftIndex] + 1;
				}
				rightIndex--;
				leftIndex++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		int sx = spos[i].first;
		int sy = spos[i].second;
		board[sx][sy] = 1;
		//cout << sx << " " << sy << "\n";
		for (int j = 0; j < dragon[i].size(); j++) {
			//cout << dragon[i][j] << " ";
			int nextX = sx + mx[dragon[i][j]];
			int nextY = sy + my[dragon[i][j]];
			if (nextX > 100 || nextY > 100 || nextX < 0 || nextY < 0) continue;
			board[nextX][nextY] = 1;
			//cout << nextX << " " << nextY << "\n";
			sx = nextX;
			sy = nextY;
		}
		//cout << endl;
	}

	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			//cout << board[i][j] << " ";
			if (board[i][j] == 1 && board[i + 1][j] == 1 && board[i][j + 1] == 1 && board[i + 1][j + 1]) {
				ans++;
			}
		}
		//cout << endl;
	}

	cout << ans;

	return 0;
}