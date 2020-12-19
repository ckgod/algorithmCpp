#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, m;
vector<int> g[501];
int ind[501];
int time[501];
int total[501];
queue<int> q;


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < n; j++) {
			int a;
			cin >> a;
			if (j == 0) {
				time[i] = a;
			}
			else {
				if (a == -1) {
					break;
				}
				g[a].push_back(i);
				ind[i]++;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (ind[i] == 0) {
			q.push(i);
			total[i] = time[i];
		}
	}
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < g[cur].size(); i++) {
			int next = g[cur][i];
			ind[next]--;
			total[next] = max(total[next], total[cur] + time[next]);
			if (ind[next] == 0) {
				q.push(next);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << total[i] << "\n";
	}

	return 0;
}