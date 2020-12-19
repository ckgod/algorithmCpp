#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

int n, m;
vector<int> graph[10001];
bool visitF[10001];
vector<int> reverseGraph[10001];
bool visitS[10001];
stack<int> finished;
vector<int> scc[10001];
vector<int> realScc[10001];
int cnt;

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
	scc[leader].push_back(v);
	for (int i = 0; i < reverseGraph[v].size(); i++) {
		if (visitS[reverseGraph[v][i]]) continue;
		dfsSecond(leader, reverseGraph[v][i]);
	}
	return;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		reverseGraph[b].push_back(a);
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
	}
	for (int i = 1; i < 10001; i++) {
		if (scc[i].size() != 0) {
			cnt++;
			sort(scc[i].begin(), scc[i].end());
			for (int j = 0; j < scc[i].size(); j++) {
				realScc[scc[i][0]].push_back(scc[i][j]);
			}
		}
	}
	cout << cnt << "\n";
	for (int i = 1; i < 10001; i++) {
		if (realScc[i].size() != 0) {
			for (int j = 0; j < realScc[i].size(); j++) {
				cout << realScc[i][j] << " ";
			}
			cout << "-1\n";
		}
	}

	return 0;
}