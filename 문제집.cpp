#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, m;
int ind[32001];
bool visit[32001];
vector<int> g[32001];
priority_queue<int> pq;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		ind[b]++;
	}
	for (int i = 1; i <= n; i++) {
		if (ind[i] == 0) {
			pq.push(-i);
		}
	}
	while (!pq.empty()) {
		int cur = -pq.top();
		pq.pop();
		cout << cur << " ";
		for (int i = 0; i < g[cur].size(); i++) {
			int next = g[cur][i];
			ind[next]--;
			if (ind[next] == 0) {
				pq.push(-next);
			}
		}
	}


	return 0;
}