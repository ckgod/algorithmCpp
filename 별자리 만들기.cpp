#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <tuple>
#include <queue>
using namespace std;

int n;
vector<pair<double, double>> star;
vector<pair<int, double>> eg[101];
bool visit[101];

double prim()
{
	double ans = 0;
	priority_queue<pair<double, int>> pq;
	pq.push({ 0,1 });
	while (!pq.empty())
	{
		double cost = -pq.top().first;
		int next = pq.top().second;
		pq.pop();
		if (visit[next]) continue;
		visit[next] = true;
		ans += cost;
		for (int i = 0; i < eg[next].size(); i++)
		{
			if (!visit[eg[next][i].first])
			{
				pq.push({ -eg[next][i].second, eg[next][i].first });
			}
		}
	}
	return ans;
}


int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n;
	star.push_back({ -1,-1 });
	for (int i = 0; i < n; i++)
	{
		double a, b;
		cin >> a >> b;
		star.push_back({ a,b });
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j) continue;
			double maxX = max(star[i].first, star[j].first);
			double maxY = max(star[i].second, star[j].second);
			double minX = min(star[i].first, star[j].first);
			double minY = min(star[i].second, star[j].second);
			double w = sqrt(pow(maxX - minX, 2) + pow(maxY - minY, 2));
			eg[i].push_back({ j,w });
		}
	}
	double result = prim();
	cout << fixed;
	cout.precision(2);
	cout << result;


	return 0;
}