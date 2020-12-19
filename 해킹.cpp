#include <iostream>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;
#define INF 99999999

int n, m, c;
vector<pair<int, int>> g[10001];
bool visit[10001];
int allTime;
int t;
int cnt;


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> t;
	while (t--) {
		cin >> n >> m >> c;
		for (int i = 0; i < m; i++) {
			int a, b, s;
			cin >> a >> b >> s;
			g[b].push_back({ a,s });
		}
		
		priority_queue<pair<int,int>> pq;
		pq.push({ 0,c });
		while (!pq.empty()) {
			int cur = pq.top().second;
			int ctime = -pq.top().first;
			if (visit[cur]) {
				pq.pop();
				continue;
			}
			visit[cur] = true;
			pq.pop();
			allTime = max(allTime, ctime);
			for (int i = 0; i < g[cur].size(); i++) {
				int next = g[cur][i].first;
				int ntime = -ctime - g[cur][i].second;
				if (visit[next]) continue;
				pq.push({ ntime,next });
			}
		}

		for (int i = 1; i <= n; i++) {
			g[i].clear();
			if (visit[i]) cnt++;
			visit[i] = false;
		}
		cout << cnt << " " << allTime << "\n";
		cnt = 0;
		allTime = 0;
	}

	return 0;
}