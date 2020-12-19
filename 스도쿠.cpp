#include <iostream>
#include <vector>
#include <string>
using namespace std;


bool vertical[10][10];
bool horizontal[10][10];
bool dgs[10][10];
int map[10][10];
bool box[10][10];

int boxNum(int x, int y) {
	if (x >= 1 && x <= 3) {
		if (y >= 1 && y <= 3) {
			return 1;
		}
		if (y >= 4 && y <= 6) {
			return 2;
		}
		if (y >= 7 && y <= 9) {
			return 3;
		}
	}
	else if (x >= 4 && x <= 6) {
		if (y >= 1 && y <= 3) {
			return 4;
		}
		if (y >= 4 && y <= 6) {
			return 5;
		}
		if (y >= 7 && y <= 9) {
			return 6;
		}
	}
	else if (x >= 7 && x <= 9) {
		if (y >= 1 && y <= 3) {
			return 7;
		}
		if (y >= 4 && y <= 6) {
			return 8;
		}
		if (y >= 7 && y <= 9) {
			return 9;
		}
	}
}

bool dfs(int x,int y) {
	if (y > 9) {
		y = 1;
		x++;
		if (x > 9) {
			
			return true;
		}
	}

	if (map[x][y] != 0) {
		return dfs(x, y + 1);
	}
	else {
		for (int i = 1; i <= 9; i++) {
			if (vertical[x][i] == false && horizontal[y][i] == false && box[boxNum(x, y)][i] == false) {
				vertical[x][i] = true;
				horizontal[y][i] = true;
				box[boxNum(x, y)][i] = true;
				map[x][y] = i;
				bool flag = dfs(x, y + 1);
				if (!flag) {
					vertical[x][i] = false;
					horizontal[y][i] = false;
					box[boxNum(x, y)][i] = false;
					map[x][y] = 0;
				}
				else {
					return true;
				}
			}
		}
		return false;
	}
}


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	for (int i = 1; i <= 9; i++) {
		string str;
		cin >> str;
		for (int j = 1; j <= 9; j++) {
			map[i][j] = str[j-1]-'0';
			if (map[i][j] != 0) {
				vertical[i][map[i][j]] = true;
				horizontal[j][map[i][j]] = true;
				box[boxNum(i, j)][map[i][j]] = true;
			}
		}
	}

	dfs(1, 1);
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			cout << map[i][j];

		}
		cout << "\n";
	}


	return 0;
}