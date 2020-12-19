#include <iostream>
#include <vector>
using namespace std;

int n, m, k;
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

	cin >> n >> m >> k;
	int goodWorker = k;
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
		cnt += dfs(i);
		for (int j = 1; j <= n; j++) {
			visit[j] = false;
		}
	}


	for (int i = 1; i <= n; i++) {
		if (goodWorker == 0) break;
		if (worker[i].size() < 2) continue;
		if (dfs(i)) {
			goodWorker--;
			cnt += 1;
		}
		for (int j = 1; j <= n; j++) {
			visit[j] = false;
		}
	}
	/*for (int i = 1; i <= m; i++) {
		cout << task[i] << " ";
	}*/
	cout << cnt;
	return 0;
}