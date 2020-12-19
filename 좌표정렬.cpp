#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct pos {
	int x;
	int y;
};

bool comp(pos p1, pos p2) {
	if (p1.y == p2.y) return p1.x < p2.x;
	else return p1.y < p2.y;
}

int n;
vector<pos> v;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		pos p;
		p.x = a;
		p.y = b;
		v.push_back(p);
	}

	sort(v.begin(), v.end(), comp);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i].x << " " << v[i].y << "\n";
	}

	return 0;
}