#include<iostream>
#include<vector>
using namespace std;
#define maxn 1001
int n, m, k;
int p[maxn], bp[maxn];
vector<pair<int, int> > blueEdge, redEdge;

int Find(int x, int p[]) {
	if (x == p[x])
		return x;
	return p[x] = Find(p[x], p);
}
void Union(int a, int b, int p[]) {
	int aa = Find(a, p);
	int bb = Find(b, p);
	if (aa != bb)
		p[aa] = bb;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	while (1) {
		cin >> n >> m >> k;
		if (n == 0 && m == 0 && k == 0)
			return 0;
		for (int i = 1; i <= n; i++) {
			p[i] = i;
			bp[i] = i;
		}
		int minK = 0, maxK = 0;
		for (int i = 0; i < m; i++) {
			char c;
			int f, t;
			cin >> c >> f >> t;
			if (c == 'R') {
				Union(f, t, p);
				redEdge.push_back({ f, t });
			}
			else {
				if (Find(f, bp) != Find(t, bp)) {
					Union(f, t, bp);
					maxK++;
				}
				blueEdge.push_back({ f, t });
			}
		}

		for (int i = 0; i < blueEdge.size(); i++) {
			int bf = blueEdge[i].first;
			int bs = blueEdge[i].second;
			if (Find(bf, p) != Find(bs, p)) {
				Union(Find(bf, p), Find(bs, p), p);
				minK++;
			}
		}


		cout << ((k > maxK || k < minK) ? false : true) << endl;
		blueEdge.clear();
		redEdge.clear();
	}
	return 0;
}