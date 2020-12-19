#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
const long long INF = 99999999999;

struct edge {
	int n1;
	int n2;
	int w;
};


int t, n, m, w;
vector<edge> road;
long long dist[501];

void init() {
	dist[1] = 0;
	for (int i = 2; i < 501; i++) {
		dist[i] = INF;
	}
	road.clear();
}


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> t;
	while (t--) {
		init();
		bool flag = false;
		cin >> n >> m >> w;
		for (int i = 0; i < m; i++) {
			int s, e, t;
			cin >> s >> e >> t;
			road.push_back({ s,e,t });
			road.push_back({ e,s,t });
		}
		for (int i = 0; i < w; i++) {
			int s, e, t;
			cin >> s >> e >> t;
			road.push_back({ s,e,-t });
		}
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < road.size(); j++) {
				//if (dist[road[j].n1] == INF) continue;
				if (dist[road[j].n2] > dist[road[j].n1] + road[j].w) {
					dist[road[j].n2] = dist[road[j].n1] + road[j].w;
				}
			}
		}
		for (int j = 0; j < road.size(); j++) {
			//if (dist[road[j].n1] == INF) continue;
			if (dist[road[j].n2] > dist[road[j].n1] + road[j].w) {
				flag = true;
				//dist[road[j].n2] = dist[road[j].n1] + road[j].w;
			}
		}
		if (flag) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}

	return 0;
}