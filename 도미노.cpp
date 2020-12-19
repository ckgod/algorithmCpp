#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

int n, m;
vector<int> graph[100001];
bool visitF[100001];
bool visitS[100001];
stack<int> finished;
int cnt;
int t;

void dfsFirst(int v) {
	visitF[v] = true;
	for (int i = 0; i < graph[v].size(); i++) {
		if (visitF[graph[v][i]]) continue;
		visitF[graph[v][i]] = true;
		dfsFirst(graph[v][i]);
	}
	finished.push(v);
	return;
}

void dfsSecond(int leader, int v) {
	visitS[v] = true;
	for (int i = 0; i < graph[v].size(); i++) {
		if (visitS[graph[v][i]]) continue;
		dfsSecond(leader, graph[v][i]);
	}
	return;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			graph[a].push_back(b);
		}

		for (int i = 1; i <= n; i++) {
			if (!visitF[i]) {
				dfsFirst(i);
			}
		}

		while (!finished.empty()) {
			int cur = finished.top();
			finished.pop();
			if (visitS[cur]) continue;

			dfsSecond(cur, cur);
			cnt++;
		}
		
		for (int i = 0; i <= n; i++) {
			visitF[i] = false;
			visitS[i] = false;
			graph[i].clear();
		}
	
		cout << cnt << "\n";
		cnt = 0;
	}


	return 0;
}