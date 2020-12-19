#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> graph[1001];
bool visit[1001];
int cnt;

void dfs(int v) {
	if (visit[v]) return;
	visit[v] = true;
	for (int i = 0; i < graph[v].size(); i++) {
		if (!visit[graph[v][i]]) {
			dfs(graph[v][i]);
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		if (!visit[i]) {
			dfs(i);
			cnt++;
		}
	}
	cout << cnt;

	return 0;
}