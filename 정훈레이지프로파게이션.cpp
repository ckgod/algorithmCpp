#include<iostream>
#include<cmath>
#define ll long long
using namespace std;

struct Tree {
	ll value = 0;
	int lazy = 0;
};
Tree tree[4000004];
ll arr[1000001];
ll sgt(int idx, int st, int en) {
	if (st == en) return tree[idx].value = arr[st];
	else {
		int m = (st + en) / 2;
		tree[idx].value = sgt(idx * 2 + 1, st, m) + sgt(idx * 2 + 2, m + 1, en);
	}
	return tree[idx].value;
}
ll sum(int idx, int st, int en, int l, int r) {
	if (tree[idx].lazy != 0) {
		tree[idx].value += (en - st + 1) * tree[idx].lazy;
		if (st != en) {
			tree[2 * idx + 1].lazy += tree[idx].lazy;
			tree[2 * idx + 2].lazy += tree[idx].lazy;
		}
		tree[idx].lazy = 0;
	}
	if (st > r || en < l) return 0;
	else if (st >= l && en <= r) return tree[idx].value;
	else {
		int m = (st + en) / 2;
		return sum(idx * 2 + 1, st, m, l, r) + sum(idx * 2 + 2, m + 1, en, l, r);
	}
}
void update(int idx, ll diff, int st, int en, int l, int r) {
	if (tree[idx].lazy != 0) { // idx��ȣ ��忡 lazy���� ������쿡
		tree[idx].value += (en - st + 1) * tree[idx].lazy; // �ڽļ���ŭ lazy���� �����ְ�
		if (st != en) { // idx��尡 ������尡 �ƴҶ� �ڽ� �θ������� lazy���� �Ѱ��ش�
			tree[2 * idx + 1].lazy += tree[idx].lazy;
			tree[2 * idx + 2].lazy += tree[idx].lazy;
		}
		tree[idx].lazy = 0; // �׸��� �ڱ� lazy�� 0���� �ʱ�ȭ
	}
	if (st > r || en < l) return; // ������Ʈ�� ������ �ƿ� �ƴҰ�� return
	else if (st >= l && en <= r) { // ������ ���ԵǾ� �ִ°�쿡
		tree[idx].value += (en - st + 1) * diff; 
		if (st != en) {
			tree[2 * idx + 1].lazy += diff;
			tree[2 * idx + 2].lazy += diff;
		}
		return;
	}
	int m = (st + en) / 2;
	update(2 * idx + 1, diff, st, m, l, r);
	update(2 * idx + 2, diff, m + 1, en, l, r);
	tree[idx].value = tree[2 * idx + 1].value + tree[2 * idx + 2].value;
}
int main() {
	int n, m, k;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sgt(0, 0, n - 1);
	int a, b, c;
	int d;
	for (int i = 0; i < m + k; i++) {
		cin >> a >> b >> c;
		if (a == 1) {
			cin >> d;
			update(0, d, 0, n - 1, b - 1, c - 1);
		}
		else {
			cout << sum(0, 0, n - 1, b - 1, c - 1) << "\n";
		}
	}
	return 0;
}