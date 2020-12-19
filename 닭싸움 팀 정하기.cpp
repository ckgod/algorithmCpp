#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int n, m;
vector<int> F[1001];
vector<int> E[1001];
bool visit[1001];
int teamcnt;


void dfs(int saram) {
	if (visit[saram]) return;
	visit[saram] = true;
	for (int i = 0; i < F[saram].size(); i++) {
		dfs(F[saram][i]);
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n;
	cin >> m;
	for (int i = 0; i < m; i++) {
		char a;
		int b, c;
		cin >> a >> b >> c;
		if (a == 'E') {
			E[b].push_back(c);
			E[c].push_back(b);
		}
		else {
			F[b].push_back(c);
			F[c].push_back(b);
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < E[i].size(); j++) {
			for (int k = 0; k < E[E[i][j]].size(); k++) {
				F[i].push_back(E[E[i][j]][k]);
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (visit[i] == false) {
			dfs(i);
			ans++;
		}
	}
	cout << ans;


	return 0;
}