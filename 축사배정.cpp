#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int n, m;
vector<int> cow[201];
int house[201];
bool visit[201];
int cnt;

bool dfs(int curCow) {
	if (visit[curCow]) return false;
	visit[curCow] = true;

	for (int i = 0; i < cow[curCow].size(); i++) {
		int curHouse = cow[curCow][i];
		if (house[curHouse] == 0) {
			house[curHouse] = curCow;
			return true;
		}
		else if (dfs(house[curHouse])) {
			house[curHouse] = curCow;
			return true;
		}
	}
	return false;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		for (int j = 0; j < a; j++) {
			int b;
			cin >> b;
			cow[i].push_back(b);
		}
	}
	for (int i = 1; i <= n; i++) {
		dfs(i);
		for (int j = 1; j <= n; j++) {
			visit[j] = false;
		}
	}
	for (int i = 1; i <= m; i++) {
		if (house[i] != 0) cnt++;
	}
	cout << cnt;

	return 0;
}