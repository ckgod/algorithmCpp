#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define INF -999999999
#define ll long long

struct edge {
	int n1, n2, w;
};

int n, m;
vector<edge> g;
vector<int> tmp[101];
ll dist[101];
bool cyc;
bool visit[101];
int pre[101];

void dfs(int n) {
	if (visit[n]) return;
	visit[n] = true;
	for (int i = 0; i < tmp[n].size(); i++) {
		if (!visit[tmp[n][i]]) {
			dfs(tmp[n][i]);
		}
	}
}

void clearV() {
	for (int i = 0; i < 101; i++) {
		visit[i] = false;
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	for (int i = 2; i <= 100; i++) {
		dist[i] = INF;
	}
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		g.push_back({ a,b,c });
		tmp[a].push_back(b);
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < g.size(); j++) {
			int from = g[j].n1;
			int to = g[j].n2;
			int cost = g[j].w;
			if (dist[from] == INF) continue;
			if (dist[to] < dist[from] + cost) {
				dist[to] = dist[from] + cost;
				pre[to] = from;
			}
		}
	}
	for (int i = 0; i < g.size(); i++) {
		int from = g[i].n1;
		int to = g[i].n2;
		int cost = g[i].w;
		if (dist[from] == INF) continue;
		if (dist[to] < dist[from] + cost) {
			dfs(to);
			if (visit[n]) {
				cyc = true;
			}
			clearV();
		}
	}
	if (cyc) {
		cout << -1;
	}
	else if (dist[n] == INF) {
		cout << -1;
	}
	else if (pre[n] == 0) {
		cout << -1;
	}
	else {
		vector<int> ans;
		ans.push_back(n);
		for (int i = n; i != 1; i = pre[i]) {
			if (pre[i] == 0) {
				cout << -1;
				return 0;
			}
			ans.push_back(pre[i]);
		}
		for (int i = ans.size() - 1; i >= 0; i--) {
			cout << ans[i] << " ";
		}
	}


	return 0;
}