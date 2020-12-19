#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n, m;
int map[51][51];
int dis;
bool getResult;
int result;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < m; j++) {
			map[i][j] = str[j];
		}
	}

	dis = min(n, m) - 1;

	while (1) {
		for (int i = 0; i < n - dis; i++) {
			for (int j = 0; j < m - dis; j++) {
				if (map[i][j] == map[i + dis][j + dis] &&
					map[i][j] == map[i][j + dis] &&
					map[i][j] == map[i + dis][j]) {
					getResult = true;
					result = dis;
				}
			}
		}
		if (getResult) {
			break;
		}
		else {
			dis--;
		}
	}
	result++;
	cout << result * result;


	return 0;
}