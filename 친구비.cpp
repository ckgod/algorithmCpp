#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define Jun 10001

int n, m, k;
int parent[10002];
vector<pair<int, int>> cost;
int ans;
int find(int n) {
	if (parent[n] == n) return n;
	else return parent[n] = find(parent[n]);
}

void merge(int n1, int n2) {
	n1 = find(n1);
	n2 = find(n2);

	if (n1 != n2) {
		parent[n2] = n1;
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	for (int i = 0; i < 10002; i++) {
		parent[i] = i;
	}
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		int t;
		cin >> t;
		cost.push_back({ t,i });
	}
	sort(cost.begin(), cost.end());
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		if (find(a) != find(b)) {
			merge(a, b);
		}
	}
	for (int i = 0; i < cost.size(); i++) {
		if (find(Jun) != find(cost[i].second)) {
			merge(Jun, cost[i].second);
			ans += cost[i].first;
		}
	}
	if (ans > k) {
		cout << "Oh no";
	}
	else {
		cout << ans;
	}

	return 0;
}