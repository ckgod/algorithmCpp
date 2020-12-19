#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <list>
using namespace std;




int t,m;
int parent[200002];
int setSize[200002];

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
		setSize[node2] = 1;
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> t;
	while (t--) {
		cin >> m;
		int cnt = 0;
		map<string, int> net;
		for (int i = 1; i <= m * 2; i++) {
			parent[i] = i;
			setSize[i] = 1;
		}
		for (int k = 0; k < m; k++) {
			string str1, str2;
			cin >> str1 >> str2;
			if (net.count(str1) == 0) {
				net[str1] = ++cnt;
			}
			if (net.count(str2) == 0) {
				net[str2] = ++cnt;
			}
			merge(net[str1], net[str2]);
			cout << setSize[findParent(net[str1])] << "\n";
		}
	}

	return 0;
}