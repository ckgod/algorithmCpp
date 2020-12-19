#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> worker[1001];
int task[1001];
bool visit[1001];
int cnt;

bool dfs(int curWorker) {
	if (visit[curWorker]) return false;
	visit[curWorker] = true;
	for (int i = 0; i < worker[curWorker].size(); i++) {
		int curTask = worker[curWorker][i];
		if (task[curTask] == 0) {
			task[curTask] = curWorker;
			return true;
		}
		else if (dfs(task[curTask])) {
			task[curTask] = curWorker;
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
			worker[i].push_back(b);
		}
	}

	for (int i = 1; i <= n; i++) {
		dfs(i);
		for (int j = 1; j <= n; j++) {
			visit[j] = false;
		}
	}
	for (int i = 1; i <= m; i++) {
		if (task[i] != 0) cnt++;
	}
	cout << cnt;



	return 0;
}