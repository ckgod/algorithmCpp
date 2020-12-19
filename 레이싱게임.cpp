#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 99999999

struct edge {
	int n1, n2, w;
};

int n, m;
vector<edge> e;
int dist[201];

int main() {
	for (int i = 2; i < 201; i++) {
		dist[i] = INF;
	}
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		e.push_back({ a,b,c });
	}
	for (int i = 0; i < n - 1; i++) {
		for (int k = 0; k < e.size(); k++) {
			int from = e[k].n1;
			int to = e[k].n2;
			int cost = e[k].w;
			if (dist[from] == INF) continue;
			if (dist[to] > dist[from] + cost) {
				dist[to] = dist[from] + cost;
			}
		}
	}
	bool bug = false;
	for (int k = 0; k < e.size(); k++) {
		int from = e[k].n1;
		int to = e[k].n2;
		int cost = e[k].w;
		if (dist[from] == INF) continue;
		if (dist[to] > dist[from] + cost) {
			cout << "bug";
			return 0;
		}
	}
	if (dist[n] == INF) {
		cout << "bug";
	}
	else {
		cout << dist[n];
	}

	return 0;
}