#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct edge {
	int a, b;
	int weight;
	bool already;
};

bool comp(edge e1, edge e2) {
	return e1.weight < e2.weight;
}

int n;
int board[202][202];
vector<edge> edgeList;
vector<edge> mst;
int parent[202];
int sumCost, cnt;

int find(int n) {
	if (n == parent[n]) return n;
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
	cin >> n;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> board[i][j];
			if (i < j) {
				if (board[i][j] < 0) {
					edgeList.push_back({ i,j,-board[i][j], true });
				}
				else {
					edgeList.push_back({ i,j,board[i][j] , false });
				}
			}
		}
	}
	sort(edgeList.begin(), edgeList.end(), comp);
	for (int i = 0; i < edgeList.size(); i++) {
		edge e = edgeList[i];
		if (e.already) {
			sumCost += e.weight;
			merge(e.a, e.b);
		}
	}
	for (int i = 0; i < edgeList.size(); i++) {
		edge e = edgeList[i];
		if (find(e.a) != find(e.b)) {
			sumCost += e.weight;
			cnt++;
			mst.push_back(e);
			merge(e.a, e.b);
		}
	}
	cout << sumCost << " " << cnt << "\n";
	for (int i = 0; i < mst.size(); i++) {
		cout << mst[i].a << " " << mst[i].b << "\n";
	}

	return 0;
}