#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> vc[32001];
int inDegree[32001];
vector<int> result;
int n, m;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		vc[a].push_back(b);
		inDegree[b]++;
	}
	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		if (inDegree[i] == 0) q.push(i);
	}
	while(!q.empty())
	{
		int x = q.front();
		q.pop();
		result.push_back(x);
		for (int i = 0; i < vc[x].size(); i++)
		{
			int y = vc[x][i];
			inDegree[y]--;
			if (inDegree[y] == 0)
			{
				q.push(y);
			}
		}
	}
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}


	return 0;
}