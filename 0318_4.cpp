#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int v, e;
long long d[100001];

vector<vector<pair<int, long long>>> vt;

bool see[100001];

int main() {
	cin >> v >> e;
	vt.resize(v + 1);

	for (int i = 0; i < v; i++) {
		cin >> see[i];
	}

	for (int i = 0; i < e; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		vt[x].push_back({ y,z });
		vt[y].push_back({ x,z });
	}

	for (int i = 0; i < v; i++) {
		if (i == v-1) {
			d[i] = -1;
		}
		else {
			d[i] = -1;
		}
	}

	priority_queue<pair<long long, int>> pq;
	pq.push({ 0,0 });

	while (pq.size()) {
		int here = pq.top().second;
		long long cost = -pq.top().first;

		pq.pop();
		if (d[here] != -1)
			continue;
		if (here != v - 1) {
			if (see[here] == true) {
				continue;
			}
		}

		d[here] = cost;

		for (auto it : vt[here]) {
			int next = it.first;
			long long acost = -it.second - cost;

			if (d[next] != -1)
				continue;

			if (next != v - 1) {
				if (see[next] == true) {
					continue;
				}
			}

			pq.push({ acost,next });
		}
	}
	cout << d[v - 1] << "\n";
	return 0;
}