#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<pair<int, int>> g[1001];
bool visit[1001];
int parent[1001];
int cnt;
int dis[1001];

int find(int node) {
	if (parent[node] == node) return node;
	else return parent[node] = find(parent[node]);
}

void merge(int n1, int n2) {
	int p1 = find(n1);
	int p2 = find(n2);
	if (p1 != p2) {
		parent[p2] = p1;
	}
}

bool comp(pair<int, int> p1, pair<int, int> p2) {
	return p1.second < p2.second;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	for (int i = 0; i < 1001; i++) {
		parent[i] = i;
		dis[i] = -1;
	}
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		g[a].push_back({ b,c });
		g[b].push_back({ a,c });
	}
	for (int i = 1; i <= n; i++) {
		sort(g[i].begin(), g[i].end(), comp);
	}
	vector<pair<int, int>> ans;
	priority_queue<pair<int, pair<int,int>>> pq;
	pq.push({ 0, { 1, 1 } });
	while (!pq.empty()) {
		int prevN = pq.top().second.second;
		int curN = pq.top().second.first;
		int curCost = -pq.top().first;
		pq.pop();

		if (dis[curN] != -1) continue;
		dis[curN] = curCost;
		if (find(curN) != find(prevN)) {
			merge(curN, prevN);
			ans.push_back({prevN, curN});
			cnt++;
		}

		for (int i = 0; i < g[curN].size(); i++) {
			int nextN = g[curN][i].first;
			int nextCost = -curCost - g[curN][i].second;

			if (dis[nextN] != -1) continue;

			pq.push({ nextCost, { nextN, curN } });
		}
	}
	cout << cnt << "\n";
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i].first << " " << ans[i].second << "\n";
	}

	return 0;
}