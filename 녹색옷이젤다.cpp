#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


int t;
int n;
int num = 1;
int map[126][126];
int rupee[126][126];
bool visit[126][126];
int mx[] = { 0,0,1,-1 };
int my[] = { 1,-1,0,0 };

void init() {
	for (int i = 0; i < 126; i++) {
		for (int j = 0; j < 126; j++) {
			rupee[i][j] = -1;
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	while (1) {
		init();
		cin >> n;
		if (n == 0) break;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
			}
		}
		priority_queue<pair<int,pair<int, int>>> pq;
		pq.push({ -map[0][0],{0,0} });
		visit[0][0] = true;
		while (pq.size()) {
			int herex = pq.top().second.first;
			int herey = pq.top().second.second;
			int cost = -pq.top().first;

			pq.pop();
			if (rupee[herex][herey] != -1) {
				continue;
			}

			rupee[herex][herey] = cost;

			for (int i = 0; i < 4; i++) {
				int nextx = herex + mx[i];
				int nexty = herey + my[i];
				int ncost = -map[nextx][nexty] - cost;

				if (nextx >= n || nexty >= n || nexty < 0 || nextx < 0) {
					continue;
				}

				if (rupee[nextx][nexty] != -1) {
					continue;
				}

				pq.push({ ncost,{nextx,nexty} });
			}
		}
		cout << "Problem " << num << ": " << rupee[n - 1][n - 1] << "\n";
		num++;
	}


	return 0;
}