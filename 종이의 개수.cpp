#include <iostream>
using namespace std;

int n;
int map[2188][2188];
int cnt1,cnt2,cnt3;
int ans[3];

void cut(int n,int x, int y) {
	int curN = map[x][y];
	bool same = true;
	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			if (map[i][j] != curN) {
				same = false;
			}
		}
	}
	if (same) {
		ans[curN + 1]++;
		return;
	}
	int m = n / 3;
	cut(m, x, y);
	cut(m, x, y + m);
	cut(m, x, y + m * 2);

	cut(m, x + m, y);
	cut(m, x + m, y + m);
	cut(m, x + m, y + m * 2);

	cut(m, x + m*2, y);
	cut(m, x + m*2, y + m);
	cut(m, x + m*2, y + m * 2);
}


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	cut(n, 0, 0);
	for (int i = 0; i < 3; i++) {
		cout << ans[i] << "\n";
	}

	return 0;
}