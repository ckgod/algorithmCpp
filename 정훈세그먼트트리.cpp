#include<iostream>
#include<cmath>
#define ll long long
using namespace std;

ll* tree;
ll a[10] = { 1,2,3,4,5,6,7,8,9,10 };

ll sgt(int idx, int st, int en) {
	if (st == en) return tree[idx] = a[st];
	else {
		int m = (st + en) / 2;
		tree[idx] = sgt(idx * 2 + 1, st, m) + sgt(idx * 2 + 2, m + 1, en);
	}
	return tree[idx];
}
ll sum(int idx, int st, int en, int l, int r) {
	if (st > r || en < l) return 0;
	else if (st >= l && en <= r) return tree[idx];
	else {
		int m = (st + en) / 2;
		return sum(idx * 2 + 1, st, m, l, r) + sum(idx * 2 + 2, m + 1, en, l, r);
	}
}
void update(int cidx, ll diff, int idx, int st, int en) {
	if (cidx<st || cidx>en)  return;
	tree[idx] += diff;
	if (st != en) {
		int m = (st + en) / 2;
		update(cidx, diff, 2 * idx + 1, st, m);
		update(cidx, diff, 2 * idx + 2, m + 1, en);
	}
}
int main() {
	int n = 10;
	int h = ceil(log2(n));
	tree = new ll[1 << (h + 1)];
	sgt(0, 0, n - 1);
	cout << sum(0, 0, 9, 3, 3) << "\n";
	a[3] = 5;
	update(3, 1, 0, 0, 9);
	cout << sum(0, 0, 9, 3, 3) << "\n";
	return 0;
}