#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;
#define open 1
#define close 0
#define INF 9999999


int tc;
int n, m;
char map[103][103];
bool visit[103][103];
int mindoor[103][103];
int mindoor2[103][103];
int mindoor3[103][103];
int xp[] = { 0,0,-1,1 };
int yp[] = { 1,-1,0,0 };
string str;
priority_queue<pair<int,pair<int,int>>, vector<pair<int, pair<int, int>>>, greater< pair<int, pair<int, int>>>> q;
queue<pair<int, int>> tmp;
int cnt;

void clearAll()
{
	for (int i = 0; i <= n+1; i++)
	{
		for (int j = 0; j <= m+1; j++)
		{
			visit[i][j] = false;
			map[i][j] = ' ';
			mindoor[i][j] = 0;
			mindoor2[i][j] = 0;
			mindoor3[i][j] = 0;
		}
	}
	while (!q.empty())
	{
		q.pop();
	}
	while (!tmp.empty())
	{
		tmp.pop();
	}
}

void clearV()
{
	for (int i = 0; i <= n+1; i++)
	{
		for (int j = 0; j <= m+1; j++)
		{
			visit[i][j] = false;
		}
	}
}

void bfs1(int sx, int sy)
{
	q.push({ 0,{ sx,sy } });
	visit[sx][sy] = true;
	while (!q.empty())
	{
		int curx = q.top().second.first;
		int cury = q.top().second.second;
		visit[curx][cury] = true;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = curx + xp[i];
			int ny = cury + yp[i];
			if (nx < 0 || nx >= n+2 || ny < 0 || ny >= m+2 || map[nx][ny] == '*'|| visit[nx][ny] == true)
				continue;
			else
			{
				if (map[nx][ny] == '#')
				{
					mindoor[nx][ny] = mindoor[curx][cury] + 1;
				}
				else
				{
					mindoor[nx][ny] = mindoor[curx][cury];
				}
				q.push({ mindoor[nx][ny],{ nx,ny } });
				visit[nx][ny] = true;
			}
		}
	}
}
void bfs2(int sx, int sy)
{
	q.push({ 0,{ sx,sy } });
	visit[sx][sy] = true;
	while (!q.empty())
	{
		int curx = q.top().second.first;
		int cury = q.top().second.second;
		visit[curx][cury] = true;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = curx + xp[i];
			int ny = cury + yp[i];
			if (nx < 0 || nx >= n + 2 || ny < 0 || ny >= m + 2 || map[nx][ny] == '*' || visit[nx][ny] == true)
				continue;
			else
			{
				if (map[nx][ny] == '#')
				{
					mindoor2[nx][ny] = mindoor2[curx][cury] + 1;
				}
				else
				{
					mindoor2[nx][ny] = mindoor2[curx][cury];
				}
				q.push({ mindoor2[nx][ny],{ nx,ny } });
				visit[nx][ny] = true;
			}
		}
	}
}
void bfs3(int sx, int sy)
{
	q.push({ 0,{ sx,sy } });
	visit[sx][sy] = true;
	while (!q.empty())
	{
		int curx = q.top().second.first;
		int cury = q.top().second.second;
		visit[curx][cury] = true;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = curx + xp[i];
			int ny = cury + yp[i];
			if (nx < 0 || nx >= n + 2 || ny < 0 || ny >= m + 2 || map[nx][ny] == '*' || visit[nx][ny] == true)
				continue;
			else
			{
				if (map[nx][ny] == '#')
				{
					mindoor3[nx][ny] = mindoor3[curx][cury] + 1;
				}
				else
				{
					mindoor3[nx][ny] = mindoor3[curx][cury];
				}
				q.push({ mindoor3[nx][ny],{ nx,ny } });
				visit[nx][ny] = true;
			}
		}
	}
}

int main()
{
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> tc;
	while (tc--)
	{
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
		{
			cin >> str;
			for (int j = 1; j <= m; j++)
			{
				map[i][j] = str[j - 1];
				if (str[j - 1] == '$')
				{
					tmp.push({ i,j });
				}
			}
		}
		bfs1(tmp.front().first, tmp.front().second);
		tmp.pop();
		clearV();
		bfs2(tmp.front().first, tmp.front().second);
		clearV();
		bfs3(0, 0);
		for (int i = 0; i <= n+1; i++)
		{
			for (int j = 0; j <= m+1; j++)
			{
				mindoor[i][j] += mindoor2[i][j];
				mindoor[i][j] += mindoor3[i][j];
	//			cout << mindoor[i][j];
			}
	//		cout << endl;
		}
		int result = INF;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if (map[i][j] == '*')
				{
					continue;
				}
				if (map[i][j] == '#')
				{
					result = min(result, mindoor[i][j] - 2);
				}
				else
				{
					result = min(result, mindoor[i][j]);
				}
			}
		}
		cout << result << "\n";
		clearAll();
	}


	return 0;
}