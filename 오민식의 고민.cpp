#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define INF -99999999999
#define CHK 9999999999
#define ll long long
// 벨만포드 반대로 뒤집어서 생각 음수 양수

struct edge {
	int n1;
	int n2;
	int w;
};

int n, m, s, e;
int getMoney[101];
vector<edge> g;
vector<int> tmp[101];
ll cost[101];
bool flag;
bool visitE[101];


void chkEnd(int s) {
	if (visitE[s]) return;
	visitE[s] = true;
	for (int i = 0; i < tmp[s].size(); i++) {
		if (!visitE[tmp[s][i]]) {
			chkEnd(tmp[s][i]);
		}
	}
}

void clearE() {
	for (int i = 0; i < 101; i++) {
		visitE[i] = false;
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> s >> e >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		g.push_back({ a,b,-c });
		tmp[a].push_back(b);
	}
	for (int i = 0; i < n; i++) {
		cin >> getMoney[i];
	}
	for (int i = 0; i < 101; i++) {
		if (i == s) {
			cost[i] = getMoney[i];
		}
		else {
			cost[i] = INF;
		}
	}

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < g.size(); j++) {
			int from = g[j].n1;
			int to = g[j].n2;
			int co = g[j].w;
			if (cost[from] == INF) continue;
			if (cost[to] < cost[from] + co + getMoney[to]) {
				cost[to] = cost[from] + co + getMoney[to];
			}
		}
	}
	for (int j = 0; j < g.size(); j++) {
		int from = g[j].n1;
		int to = g[j].n2;
		int co = g[j].w;
		if (cost[from] == INF) {
			continue;
		}
		if (cost[to] < cost[from] + co + getMoney[to]) {
			cost[to] = CHK;
			chkEnd(to);
			if (visitE[e]) {
				flag = true;
				cout << "Gee";
				return 0;
			}
			clearE();
		}
	}

	if (cost[e] == INF) {
		cout << "gg";
	}
	else {
		cout << cost[e];
	}


	return 0;
}