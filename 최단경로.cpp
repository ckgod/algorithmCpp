#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXVT 20001;

int v, e, w;
int start;
int vt[20001];
vector<pair<int, int>> map[20001];
priority_queue<pair<int, int>> q;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	memset(vt, -1, sizeof(vt));
	cin >> v >> e;
	cin >> start;
	for (int i = 0; i < e; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		map[x].push_back({ y,z });
	}
	q.push({ 0,start });
	while (!q.empty())
	{
		int here = q.top().second;
		int cost = -q.top().first;
		q.pop();
		if (vt[here] != -1) continue;
		vt[here] = cost;
		for (int i = 0; i < map[here].size(); i++)
		{
			int there = map[here][i].first;
			int tcost = -map[here][i].second - cost;
			if (vt[there] != -1) continue;
			q.push({ tcost,there });
		}
	}
	for (int i = 1; i <= v; i++)
	{
		if (vt[i] == -1)
		{
			cout << "INF\n";
		}
		else
		{
			cout << vt[i] << "\n";
		}
	}

	return 0;
}