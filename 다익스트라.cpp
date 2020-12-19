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
		vt[x].push_back({ y,z });    //��������Ʈ�� �׷����� ����
	}

	memset(d, -1, sizeof(d));//�Ÿ��� ��� �迭 d�� ���� �� ���� ��(-1)�� �ʱ�ȭ

	priority_queue<pair<int, int>> pq;//������ ���� ��(�Ÿ�,����)
	pq.push({ 0,s });//���������� ������ ����

	while (pq.size()) {//pq�� �� ������ ���ͽ�Ʈ�� �˰��� ����
		int here = pq.top().second;//���� Ȯ���ϴ� ����
		int cost = -pq.top().first;//�Ÿ�(���) -�� ���̴� ������ pq�� minheap���� ����ϱ� ����

		pq.pop();
		if (d[here] != -1)
			continue;//�̹� ���Ǿ��ٸ� �Ѿ

		d[here] = cost;//�ִܰŸ� ������ ����
		for (auto it : vt[here]) {
			int next = it.first;//���� ����
			int acost = -it.second - cost;//���� �� �Ÿ�

			if (d[next] != -1)
				continue;//�̹� ���Ǿ��ٸ� �Ѿ

			pq.push({ acost,next });
		}
	}
	for (int i = 1; i <= v; i++) {
		if (d[i] == -1)cout << "INF\n";
		else cout << d[i] << "\n";
	}//�ִܰŸ� ���
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