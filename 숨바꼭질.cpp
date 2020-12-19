#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int mp[100001];
bool visit[100001];
int ans[100001];
int n, k;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n >> k;
	queue<int> q;
	q.push(n);
	while (!q.empty()) {
		int curx = q.front();
		q.pop();
		visit[curx] = true;
		for (int i = 0; i < 3; i++) {
			int nx = curx;
			if (i == 0) {
				nx--;
			}
			else if (i == 1) {
				nx++;
			}
			else if (i == 2) {
				nx *= 2;
			}
			if (nx < 0 || nx > 100000) continue;
			if (visit[nx]) continue;
			ans[nx] = ans[curx] + 1;
			q.push(nx);
			visit[nx] = true;
		}
	}
	cout << ans[k];

	return 0;
}