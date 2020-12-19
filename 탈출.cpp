#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, t, g;
int number[100000];
bool visit[100000];
int cnt[100000];
queue<int> q;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n >> t >> g;
	q.push(n);
	while (!q.empty()) {
		int curN = q.front();
		q.pop();

		visit[curN] = true;
		if (curN == g) {
			break;
		}
		if (cnt[curN] == t) continue;

		for (int i = 0; i < 2; i++) {
			if (i == 0) { // A누를때
				int nextN = curN + 1;
				if (nextN > 99999 || visit[nextN]) continue;
				q.push(nextN);
				cnt[nextN] = cnt[curN] + 1;
				visit[nextN] = true;
			}
			else { // B누를때
				int nextN = curN * 2;
				if (nextN > 99999) {
					break;
				}
				int t = nextN;
				int sizeN = 0;
				int sub = 1;
				while (t > 0) {
					sizeN++;
					t /= 10;
				}
				for (int k = 0; k < sizeN - 1; k++) {
					sub *= 10;
				}
				nextN -= sub;
				if (nextN < 0 || visit[nextN]) continue;
				q.push(nextN);
				cnt[nextN] = cnt[curN] + 1;
				visit[nextN] = true;
			}
		}
	}

	if (cnt[g] > t || !visit[g]) cout << "ANG";
	else cout << cnt[g];



	return 0;
}