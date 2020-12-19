#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n;
int time[10001];
vector<int> g[10001];
int ind[10001];
int total[10001];
int ans;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		time[i + 1] = a;
		for (int j = 0; j < b; j++) {
			int t;
			cin >> t;
			g[t].push_back(i + 1);
			ind[i + 1]++;
		}
	}
	queue<int> q;
	vector<int> topo;
	for (int i = 1; i <= n; i++) {
		if (ind[i] == 0) {
			q.push(i);
			total[i] = time[i];
		}
	}
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		topo.push_back(cur);
		for (int i = 0; i < g[cur].size(); i++) {
			int next = g[cur][i];
			ind[next]--;
			total[next] = max(total[next], time[next] + total[cur]);
			if (ind[next] == 0) {
				q.push(next);
			}
		}
	}
	for (int i = 0; i < topo.size(); i++) {
		ans = max(ans, total[topo[i]]);
	}
	cout << ans;

	return 0;
}