#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
#define INF 99999999

struct edge {
	int n1;
	int n2;
	long long w;
};

int n, m;
long long dist[501];
vector<edge> bus;
bool flag;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	for (int i = 2; i < 501; i++) {
		dist[i] = INF;
	}
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		bus.push_back({ a,b,c });
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < bus.size(); j++) {
			if (dist[bus[j].n1] == INF) continue;
			if (dist[bus[j].n2] > dist[bus[j].n1] + bus[j].w) {
				dist[bus[j].n2] = dist[bus[j].n1] + bus[j].w;
			}
		}
	}
	for (int i = 0; i < bus.size(); i++) {
		if (dist[bus[i].n1] == INF) continue;
		if (dist[bus[i].n2] > dist[bus[i].n1] + bus[i].w) {
			flag = true;
		}
	}
	if (flag) {
		cout << -1;
	}
	else {
		for (int i = 2; i <= n; i++) {
			if (dist[i] == INF) {
				cout << "-1\n";
			}
			else {
				cout << dist[i] << "\n";
			}
		}
	}

	return 0;
}