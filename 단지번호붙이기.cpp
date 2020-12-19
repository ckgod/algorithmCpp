#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int map[26][26];
bool visit[26][26];
int N;
string str;
int xp[] = { 0,0,-1,1 };
int yp[] = { 1,-1,0,0 };
int Danji; // 단지개수
vector<int> cntH; // 단지의 집개수
int cnt;

void DFS(int x, int y)
{
	if (visit[x][y] == false)
	{
		visit[x][y] = true;
		cnt++;
	}
	for (int i = 0; i < 4; i++)
	{
		int curx = x + xp[i];
		int cury = y + yp[i];
		if(curx >= 0 && cury >= 0 && curx < N && cury < N)
		{ 
			if (visit[curx][cury] == false && map[curx][cury] == 1)
			{
				DFS(curx, cury);
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		for (int j = 0; j < N; j++)
		{
			map[i][j] = str[j]-'0';
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == 1 && visit[i][j] == false)
			{
				DFS(i, j);
				Danji++;
				cntH.push_back(cnt);
				cnt = 0;
			}
		}
	}
	sort(cntH.begin(), cntH.end());
	cout << Danji << "\n";
	for (int i = 0; i < cntH.size(); i++)
	{
		cout << cntH[i] << "\n";
	}
	return 0;
}