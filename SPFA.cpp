#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX_V 501
#define INF 99999999

int dis[MAX_V];
int cost[MAX_V];
bool inQ[MAX_V];

int cycle[MAX_V];

vector<pair<int, int>> g[MAX_V];
int n, m;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		g[a].push_back({ b,c });
	}

	for (int i = 0; i < MAX_V; i++) {
		dis[i] = INF;
	}

	queue<int> q;
	dis[1] = 0;
	inQ[1] = true;

	q.push(1);
	cycle[1]++;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		inQ[cur] = false;

		for (int i = 0; i < g[cur].size(); i++) {
			int next = g[cur][i].first;
			int cost = g[cur][i].second;

			if (dis[next] > dis[cur] + cost) {
				dis[next] = dis[cur] + cost;
				if (!inQ[next]) {
					cycle[next]++;
					if (cycle[next] >= n) {
						cout << "-1\n";
						return 0;
					}

					q.push(next);
					inQ[next] = true;
				}
			}

		}
	}

	for (int i = 2; i <= n; i++) {
		if (dis[i] == INF) cout << "-1\n";
		else cout << dis[i] << "\n";
	}


	return 0;
}