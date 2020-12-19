#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> com[101];
int n;
int edge;
int vt1, vt2;
bool visit[101];
int cnt = -1;

void DFS(int start)
{
	if(visit[start] == false)
	{
		cnt++;
		visit[start] = true;
	}
	for (int i = 0; i < com[start].size(); i++)
	{
		if (visit[com[start][i]] == false)
		{
			DFS(com[start][i]);
		}
	}
}


int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n;
	cin >> edge;
	while(edge--)
	{
		cin >> vt1 >> vt2;
		com[vt1].push_back(vt2);
		com[vt2].push_back(vt1);
	}
	for (int i = 1; i <= n; i++)
	{
		sort(com[i].begin(), com[i].end());
	}
	DFS(1);
	cout << cnt << endl;
	return 0;
}