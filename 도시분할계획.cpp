#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
	int a;
	int b;
	int weight;
};

int n, m;
vector<Edge> edge;
int parent[100001];
int setSize[100001];
int mW;
int ans;


bool comp(Edge e1, Edge e2) {
	return e1.weight < e2.weight;
}

int find(int n) {
	if (n == parent[n]) return n;
	return parent[n] = find(parent[n]);
}

void merge(int n1, int n2) {
	int no1 = find(n1);
	int no2 = find(n2);
	if (no1 != no2) {
		if (setSize[no1] < setSize[no2]) {
			swap(no1, no2);
		}

		parent[no2] = no1;
		setSize[no1] += setSize[no2];
		setSize[no2] = 0;
	}
}


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		edge.push_back({ a,b,c });
	}
	sort(edge.begin(), edge.end(), comp);
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
		setSize[i] = 1;
	}
	for (int i = 0; i < edge.size(); i++) {
		if (find(edge[i].a) != find(edge[i].b)) {
			merge(edge[i].a, edge[i].b);
			ans += edge[i].weight;
			mW = max(mW, edge[i].weight);
		}
	}
	cout << ans - mW;

	return 0;
}