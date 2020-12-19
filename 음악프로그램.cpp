#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<int> PD[101];
vector<int> g[1001];
int ind[1001];
bool impos;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a;
		cin >> a;
		for (int j = 0; j < a; j++) {
			int t;
			cin >> t;
			PD[i + 1].push_back(t);
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j < PD[i].size(); j++) {
			g[PD[i][j - 1]].push_back(PD[i][j]);
			ind[PD[i][j]]++;
		}
	}
	queue<int> q;
	vector<int> ans;
	for (int i = 1; i <= n; i++) {
		if (ind[i] == 0) {
			q.push(i);
		}
	}
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		ans.push_back(cur);
		for (int i = 0; i < g[cur].size(); i++) {
			int next = g[cur][i];
			ind[next]--;
			if (ind[next] < 0) {
				impos = true;
			}
			if (ind[next] == 0) {
				q.push(next);
			}
		}
	}
	if (ans.size() != n) {
		cout << 0;
	}
	else {
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << "\n";
		}
	}

	return 0;
}