#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define MAX 3001

int parent[MAX];
int setSize[MAX];
int n, m, t;

struct enemy {
	double x;
	double y;
	double r;

};

void init() {
	for (int i = 0; i < MAX; i++) {
		parent[i] = i;
		setSize[i] = 1;
	}
}

double absol(double a) {
	if (a < 0) return -a;
	else return a;
}

double calDis(double x1, double y1, double x2, double y2) {
	double dis = sqrt((pow(abs(x1 - x2), 2) + pow(abs(y1 - y2), 2)));
	return dis;
}

int findParent(int n) {
	if (parent[n] == n) return n;
	else return parent[n] = findParent(parent[n]);
}

void merge(int n1, int n2) {
	n1 = findParent(n1);
	n2 = findParent(n2);
	if (n1 != n2) {
		if (setSize[n2] < setSize[n1]) swap(n1, n2);
		parent[n2] = n1;
		setSize[n1] += setSize[n2];
		setSize[n2] = 0;
	}
}

bool isGroup(int n1, int n2) {
	n1 = findParent(n1);
	n2 = findParent(n2);
	if (n1 == n2) return true;
	else return false;
}

vector<enemy> v;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> t;
	while (t--) {
		init();
		int cnt = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			double a, b, c;
			cin >> a >> b >> c;
			v.push_back({ a,b,c });
		}
		for (int i = 0; i < v.size(); i++) {
			for (int j = i + 1; j < v.size(); j++) {
				double dis = calDis(v[i].x, v[i].y, v[j].x, v[j].y);
				double sumR = v[i].r + v[j].r;
				if (dis <= sumR) {
					if (isGroup(i, j)) continue;
					else {
						merge(i, j);
					}
				}
			}
		}
		for (int i = 0; i < n; i++) {
			if (setSize[i] != 0)  cnt++;
			//cout << i << " : " << setSize[i] << "\n";
		}
		cout << cnt << "\n";
		v.clear();
	}
	return 0;
}