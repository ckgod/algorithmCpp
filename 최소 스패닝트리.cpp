#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
#define MV 10001
#define ll long long

int v, e;
vector<pair<int, int>> eg[MV];
bool visit[MV];
int minW;


int prim()
{
	ll ans = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,1 });
	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int spot = pq.top().second;
		pq.pop();
		if (visit[spot]) continue;
		visit[spot] = true;
		ans += cost;
		for (int i = 0; i < eg[spot].size(); i++)
		{
			if (!visit[eg[spot][i].first])
			{
				pq.push({ -eg[spot][i].second,eg[spot][i].first });
			}
		}
		
	}
	return ans;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> v >> e;
	for (int i = 0; i < e; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		eg[a].push_back({ b,c });
		eg[b].push_back({ a,c });
	}
	ll ans = prim();
	cout << ans;


	return 0;
}