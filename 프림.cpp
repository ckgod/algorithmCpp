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
	}// ���� v�� ����� ������ ť�� ��´�

	while (!pq.empty()) {
		auto w = pq.top();
		pq.pop();
		if (!visited[w.second]) {
			k += -w.first;
			prim(w.second);
			return;
		}// ������ Ʈ���� ������� �ʾ����� �����Ѵ�
	}// ����ġ�� ���� ������ ���ʴ�� Ž���ϸ鼭
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
	prim(1);// 1�� �������� Ʈ���� ����� ����
	cout << k;
	return 0;
}