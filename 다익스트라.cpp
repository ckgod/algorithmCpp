#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int v, e, s, d[20002];

vector<vector<pair<int, int>>> vt;

int main() {
	cin >> v >> e >> s;
	vt.resize(v + 1);
	for (int i = 0; i < e; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		vt[x].push_back({ y,z });    //인접리스트로 그래프를 형성
	}

	memset(d, -1, sizeof(d));//거리가 담길 배열 d를 나올 수 없는 수(-1)로 초기화

	priority_queue<pair<int, int>> pq;//정보를 담을 힙(거리,정점)
	pq.push({ 0,s });//시작정점의 정보를 삽입

	while (pq.size()) {//pq가 빌 때까지 다익스트라 알고리즘 동작
		int here = pq.top().second;//현재 확인하는 정점
		int cost = -pq.top().first;//거리(비용) -를 붙이는 이유는 pq를 minheap으로 사용하기 위함

		pq.pop();
		if (d[here] != -1)
			continue;//이미 계산되었다면 넘어감

		d[here] = cost;//최단거리 정보를 갱신
		for (auto it : vt[here]) {
			int next = it.first;//다음 정점
			int acost = -it.second - cost;//누적 된 거리

			if (d[next] != -1)
				continue;//이미 계산되었다면 넘어감

			pq.push({ acost,next });
		}
	}
	for (int i = 1; i <= v; i++) {
		if (d[i] == -1)cout << "INF\n";
		else cout << d[i] << "\n";
	}//최단거리 출력
	return 0;
}
/*
5 8 5
1 3 6
2 1 3
1 4 3
4 3 1
3 4 2
5 2 4
5 4 2
4 2 1
*/