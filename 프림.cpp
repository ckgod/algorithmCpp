#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define N 10001

using namespace std;

vector<vector<pair<int, int>>> edge;
priority_queue<pair<int, int>> pq;

bool visited[N];
int v, e, c, k;

void prim(int v) {
	visited[v] = true;

	for (auto u : edge[v]) {
		if (!visited[u.second]) {
			pq.push({ -u.first, u.second });
		}
	}// 정점 v와 연결된 간선을 큐에 담는다

	while (!pq.empty()) {
		auto w = pq.top();
		pq.pop();
		if (!visited[w.second]) {
			k += -w.first;
			prim(w.second);
			return;
		}// 정점이 트리와 연결되지 않았으면 연결한다
	}// 가중치가 낮은 간선을 차례대로 탐색하면서
}

int main() {
	cin >> v >> e;
	edge.resize(v + 1);

	for (int i = 0; i < e; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		edge[x].push_back({ z, y });
		edge[y].push_back({ z, x });
	}
	prim(1);// 1번 정점으로 트리를 만들어 시작
	cout << k;
	return 0;
}