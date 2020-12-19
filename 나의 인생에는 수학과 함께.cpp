#include<iostream>
#include<vector>
using namespace std;
#define maxn 1001
int n, m, k;
int p[maxn], bp[maxn];
vector<pair<int, int> > blueEdge, redEdge;
int Find(int x) {
	if (x == p[x])
		return x;
	return p[x] = Find(p[x]);
}
void Union(int a, int b) {
	int aa = Find(a);
	int bb = Find(b);
	if (aa != bb)
		p[aa] = bb;
}
int bFind(int x) {
	if (x == bp[x])
		return x;
	return bp[x] = bFind(bp[x]);
}
void bUnion(int a, int b) {
	int aa = bFind(a);
	int bb = bFind(b);
	if (aa != bb)
		bp[aa] = bb;
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
				Union(f, t);
				redEdge.push_back({ f, t });
			}
			else {
				if (bFind(f) != bFind(t)) {
					bUnion(f, t);
					maxK++;
				}
				blueEdge.push_back({ f, t });
			}
		}

		for (int i = 0; i < blueEdge.size(); i++) {
			int bf = blueEdge[i].first;
			int bs = blueEdge[i].second;
			if (Find(bf) != Find(bs)) {
				Union(Find(bf), Find(bs));
				minK++;
			}
		}


	/*	for (int i = 0; i < redEdge.size(); i++) {
			int rf = redEdge[i].first;
			int rs = redEdge[i].second;
			if (bFind(rf) != bFind(rs)) {
				bUnion(bFind(rf), bFind(rs));
			}
		}*/

		bool ans = true;
		if (k > maxK || k < minK)
			ans = false;
		
		cout << ans << '\n';
		blueEdge.clear();
		redEdge.clear();
	}
	return 0;
}