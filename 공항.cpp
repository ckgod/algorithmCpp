#include <iostream>
#include <vector>
using namespace std;

int g, p;
int parent[100001];
int ans;
vector<int> gi;

int find(int n) {
	if (parent[n] == n) return n;
	else return parent[n] = find(parent[n]);
}

void merge(int n1, int n2) {
	n1 = find(n1);
	n2 = find(n2);
	if (n1 > n2) swap(n1, n2);
	if (n1 != n2) {
		parent[n2] = n1;
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> g >> p;
	for (int i = 0; i <= g; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < p; i++) {
		int a;
		cin >> a;
		gi.push_back(a);
	}
	for (int i = 0; i < gi.size(); i++) {
		if (find(gi[i]) != 0) {
			int doc = find(gi[i]);
			ans++;
			merge(doc, doc - 1);
		}
		else {
			cout << ans;
			return 0;
		}
	}
	cout << ans;


	return 0;
}