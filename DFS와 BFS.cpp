#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, start;
vector<int> v[1001];
bool visit[1001];
int vt1, vt2;
queue<int> q;

void DFS(int start)
{
	if (visit[start] == false)
	{
		cout << start << " ";
		visit[start] = true;
	}
	for (int i = 0; i < v[start].size(); i++)
	{
		if (visit[v[start][i]] == false)
		{
			DFS(v[start][i]);
		}
	}
}

void BFS(int start)
{
	q.push(start);
	
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		if (visit[cur] == true) continue;

		visit[cur] = true;
		cout << cur << " ";
		for (int i = 0; i < v[cur].size(); i++)
		{
			if(visit[v[cur][i]] == false) 
				q.push(v[cur][i]);
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n >> m >> start;
	while (m--)
	{
		cin >> vt1 >> vt2;
		v[vt1].push_back(vt2);
		v[vt2].push_back(vt1);
	}
	for (int i = 1; i <= n; i++)
	{
		sort(v[i].begin(), v[i].end());
	}
	DFS(start);
	for (int i = 0; i <= n; i++)
	{
		visit[i] = false;
	}
	cout << "\n";
	BFS(start);

	return 0;
}