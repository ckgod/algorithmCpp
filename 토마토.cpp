#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int arr[1001][1001];
int days[1001][1001];
bool visit[1001][1001];
int y, x;
int my[] = { 0, 0, 1, -1 };
int mx[] = { 1, -1, 0, 0 };
queue<pair<int, int> > q;
int ans;

void bfs(int sy, int sx)
{
	visit[sy][sx] = true;
	days[sy][sx] = 0;
	while (!q.empty()) 
	{
		int cury = q.front().first;
		int curx = q.front().second;
		visit[cury][curx] = true;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = cury + my[i];
			int nx = curx + mx[i];
			if (ny < 0 || nx < 0 || ny >= y || nx >= x || arr[ny][nx] == 1 || arr[ny][nx] == -1 || visit[ny][nx] == true)
				continue;
			q.push({ ny, nx });
			visit[ny][nx] = true;
			days[ny][nx] = days[cury][curx] + 1;
		}
	}
}

int main() {
	cin >> x >> y;
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 1)
			{
				q.push({ i,j });
			}
			else if (arr[i][j] == -1)
			{
				visit[i][j] = true;
				days[i][j] = 0;
			}
		}
	}

	bfs(q.front().first, q.front().second);

	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			if (visit[i][j] == 0)
			{
				cout << -1;
				return 0;
			}
		}
	}

	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			ans = max(ans, days[i][j]);
		}
	}

	cout << ans;

	return 0;
}