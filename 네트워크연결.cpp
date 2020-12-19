#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

struct Edge {
	int a;
	int b;
	int weight;
};

bool comp(Edge e1, Edge e2) {
	return e1.weight < e2.weight;
}

int n, m;
vector<Edge> edge;
int parent[1001];
int setSize[1001];
int ans;

void init(int n) {
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
		setSize[i] = i;
	}
}

int findParent(int node) {
	if (node == parent[node]) return node;
	return parent[node] = findParent(parent[node]);
}

void merge(int n1, int n2) {
	int node1 = findParent(n1);
	int node2 = findParent(n2);
	if (node1 != node2) {
		if (setSize[node1] < setSize[node2]) {
			swap(node1, node2);
		}

		parent[node2] = node1;
		setSize[node1] += setSize[node2];
		setSize[node2] = 0;
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edge.push_back({ a,b,c });
	}
	sort(edge.begin(), edge.end(), comp);
	init(n);
	for (int i = 0; i < edge.size(); i++) {
		if (findParent(edge[i].a) != findParent(edge[i].b)) {
			merge(edge[i].a, edge[i].b);
			ans += edge[i].weight;
		}
	}
	cout << ans;


	return 0;
}