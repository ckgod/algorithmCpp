#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define ll long long



int N, M, K;
ll arr[1000001];
ll tree[4000004];

ll sgt(int idx, int st, int en) {
	if (st == en) return tree[idx] = arr[st];
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
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M >> K;

	for (int i = 0; i < N; i++) {
		ll t;
		cin >> t;
		arr[i] = t;
	}
	sgt(0, 0, N - 1);

	for (int i = 0; i < M + K; i++) {
		ll a, c;
		int b;
		cin >> a >> b >> c;
		if (a == 1) { // b번째 수를 c로 바꾼다
			ll diff = c - arr[b - 1];
			arr[b - 1] = c;
			update(b - 1, diff, 0, 0, N - 1);
		}
		else if(a == 2){ // b번째 수부터 c번째 수까지의 합
			cout << sum(0, 0, N - 1, b - 1, c - 1) << "\n";
		}
	}


	return 0;
}