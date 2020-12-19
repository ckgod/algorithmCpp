#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
#define INF 99999

vector<int> bellman;
vector<int> check;
vector <tuple<int, int, int> > edge;

int n, m;

int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edge.push_back(make_tuple(a, b, c));
	}
	bellman.push_back(-1);
	bellman.push_back(0);
//	bellman[1] = 0;
	for (int i = 2; i <= n; i++) {
		bellman.push_back(INF);
	}
	// 구하기
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < edge.size(); j++) {
			int here = get<0>(edge[j]);
			int there = get<1>(edge[j]);
			int w = get<2>(edge[j]);

			if (bellman[here] == INF) continue;

			if (bellman[there] > bellman[here] + w) {
				bellman[there] = bellman[here] + w;
			}
		}
	}

	// 검증
	check = bellman;

	for (int j = 0; j < edge.size(); j++) {
		int here = get<0>(edge[j]);
		int there = get<1>(edge[j]);
		int w = get<2>(edge[j]);

		if (check[here] == INF) continue;

		if (check[there] > check[here] + w) {
			check[there] = check[here] + w;
		}
	}

	bool flag = true;

	for (int i = 2; i <= n; i++) {
		if (check[i] != bellman[i]) {
			flag = false;
			break;
		}
	}

	if (flag) {
		for (int i = 2; i <= n; i++) {
			if (bellman[i] == INF) {
				cout << -1 << '\n';
			}
			else {
				cout << bellman[i] << '\n';
			}
		}
	}
	else {
		cout << -1 << '\n';
	}

	return 0;
}