#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
#include <tuple>
using namespace std;

int N, M, K;
int tc;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> tc;
	while (tc--)
	{
		vector<pair<int, int>> timeandcost;
		vector<tuple<int,int, int>> ap[101];
		priority_queue<tuple<int,int, int>> q;
		timeandcost.resize(101);
		for (int i = 0; i < 101; i++)
		{
			timeandcost[i].first = -1;
			timeandcost[i].second = -1;
		}
		cin >> N >> M >> K;
		for (int i = 0; i < K; i++)
		{
			int a, b, c, d; // c가 비용 d가 소요시간
			cin >> a >> b >> c >> d;
			ap[a].push_back(make_tuple(b, c, d));
		}
		q.push(make_tuple(0, 1, 0)); //get<0> : 시간 get<2> : 비용
		while (!q.empty())
		{
			int here = get<1>(q.top());
			int time = -get<0>(q.top());
			int cost = -get<2>(q.top());
			q.pop();
			/*if (cost > M)
			{
				continue;
			}*/
			if (timeandcost[here].first != -1) continue;
			timeandcost[here].first = time;
			timeandcost[here].second = cost;
			for (int i = 0; i < ap[here].size(); i++)
			{
				int there = get<0>(ap[here][i]);
				int ttime = -get<2>(ap[here][i]) - time;
				int tcost = -get<1>(ap[here][i]) - cost;
				if (timeandcost[there].first != -1) continue;

				q.push(make_tuple(ttime, there, tcost));
			}
		}
		/*if (timeandcost[N].second > M || timeandcost[N].second == (-1))
		{
			cout << "Poor KCM\n";
		}
		else
		{*/
			cout << timeandcost[N].first  << " " << timeandcost[N].second << "\n";
	
		
	}

	return 0;
}