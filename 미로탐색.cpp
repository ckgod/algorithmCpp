#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

int x, y;
int map[101][101];
bool visit[101][101];
int rt[101][101];
string col;
int my[] = { 0,0,1,-1 };
int mx[] = { 1,-1,0,0 };
queue<pair<int,int> > q;


int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> x >> y;
	for (int i = 0; i < x; i++)
	{
		cin >> col;
		for (int j = 0; j < y; j++)
		{
			map[i][j] = col[j]-48;
		}
	}
	q.push({ 0,0 });
	rt[0][0] = 1;
	while (!q.empty())
	{
		int curx = q.front().first;
		int cury = q.front().second;
		visit[curx][cury] = true;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = curx + mx[i];
			int ny = cury + my[i];
			if (nx < 0 || ny < 0 || nx >= x || ny >= y || map[nx][ny] == 0 || visit[nx][ny] == true)
			{
				continue;
			}
			q.push({ nx,ny });
			visit[nx][ny] = true;
			rt[nx][ny] = rt[curx][cury] + 1;
		}
		
	}

	cout << rt[x-1][y-1];
	
	return 0;
}