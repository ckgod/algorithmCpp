#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
vector<int> tree[50001];
bool visit[50001];
int depth[50001];
int dp[50001][21];

void dfs(int n, int d) {
	visit[n] = true;
	depth[n] = d;
	for (int i = 0; i < tree[n].size(); i++) {
		int next = tree[n][i];
		if (visit[next]) continue;
		dp[next][0] = n;
		dfs(next, d + 1);
	}
}

void init() {
	for (int j = 1; j < 21; j++) {
		for (int i = 1; i <= n; i++) {
			dp[i][j] = dp[dp[i][j - 1]][j - 1];
		}
	}
}

int lca(int a, int b) {
	if (depth[a] > depth[b]) {
		swap(a, b);
	}
	for (int i = 20; i >= 0; i--) {
		if (depth[b] - depth[a] >= (1 << i)) {
			b = dp[b][i];
		}
	}
	if (a == b) return a;
	for (int i = 20; i >= 0; i--) {
		if (dp[a][i] != dp[b][i]) {
			a = dp[a][i];
			b = dp[b][i];
		}
	}
	return dp[a][0];
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n-1; i++) {
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	dfs(1, 0);
	init();
	cin >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;
		cout << lca(a, b) << "\n";
	}


	return 0;
}