#include <iostream>
#include <vector>
using namespace std;

int n, m;
int visit[1000001];
pair<int, int> person[1000001];
int shirts[1000001];
int ans[1000001];
int checkV = 1;
vector<int> sGraph[1000001];

bool dfs(int curP, int check) {
	if (visit[curP] == check) return false;
	visit[curP] = check;
	int s1 = person[curP].first;
	int s2 = person[curP].second;
	if (shirts[s1] == 0 || dfs(shirts[s1], check)) {
		shirts[s1] = curP;
		ans[curP] = s1;
		return true;
	}
	if (shirts[s2] == 0 || dfs(shirts[s2], check)) {
		shirts[s2] = curP;
		ans[curP] = s2;
		return true;
	}
	return false;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a, b;
		cin >> a >> b;
		person[i].first = a;
		person[i].second = b;
		sGraph[a].push_back(i);
		sGraph[b].push_back(i);
	}
	for (int i = 1; i <= n; i++) {
		dfs(i, checkV);
		checkV++;
	}
	bool isT = true;
	for (int i = 1; i <= n; i++) {
		if (ans[i] == 0) isT = false;
	}
	if (isT) {
		for (int i = 1; i <= n; i++) {
			cout << ans[i] << "\n";
		}
	}
	else {
		cout << "-1";
	}

	return 0;
}