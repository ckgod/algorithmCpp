#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int n;
vector<pair<int, int>> tree[10001];
int dis[10001];
bool visit[10001];
int Jirm;

void init(int n) {
	for (int i = 1; i <= n; i++) {
		dis[i] = 0;
		visit[i] = false;
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;
	
	for (int i = 0; i < n - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		tree[a].push_back({ b,c });
		tree[b].push_back({ a,c });
	}
	queue<int> startPos;
	for (int i = 1; i <= n; i++) {
		startPos.push(i);
	}
	while (!startPos.empty()) {
		int start = startPos.front();
		startPos.pop();
		queue<int> q;
		q.push(start);
		visit[start] = true;
		while (!q.empty()) {
			int curPos = q.front();
			q.pop();
			for (int i = 0; i < tree[curPos].size(); i++) {
				int nextPos = tree[curPos][i].first;
				if (visit[nextPos] == true) continue;
				visit[nextPos] = true;
				q.push(nextPos);
				dis[nextPos] = dis[curPos] + tree[curPos][i].second;
				Jirm = max(Jirm, dis[nextPos]);
			}
		}
		init(n);
	}
	
	cout << Jirm;

	return 0;
}