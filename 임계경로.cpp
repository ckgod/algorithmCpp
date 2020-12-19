#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct edge {
	int n1;
	int n2;
	int w;
};

int n, m;
vector<edge> roadList;
vector<pair<int,int>> g[10001];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		g[a].push_back({ b,c });
		roadList.push_back({ a,b,c });
	}

	return 0;
}