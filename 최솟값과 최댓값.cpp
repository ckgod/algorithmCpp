#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long

int N, M;
int arr[100001];
int maxtree[4000004];
int mintree[4000004];

int MaxSgt(int idx, int st, int end) {
	if (st == end) maxtree[idx] = arr[st];

	int m = (st + end) / 2;
	return maxtree[idx] = max(MaxSgt(idx * 2 + 1, st, m), MaxSgt(idx * 2 + 2, m + 1, end));
}

int MinSgt(int idx, int st, int end) {
	if (st == end) mintree[idx] = arr[st];

	int m = (st + end) / 2;
	return mintree[idx] = min(MinSgt(idx * 2 + 1, st, m), MinSgt(idx * 2 + 2, m + 1, end));
}

int getMax(int idx, int st, int end, int l, int r) {
	if (st > r || end < l) return 0;
	else if (st >= l && end <= r) {

	}
	else {

	}

}

int getMin(int idx, int st, int end, int l, int r) {

}


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> arr[i];

	while (M--) {
		int a, b;
		cin >> a >> b;
	}

	return 0;
}