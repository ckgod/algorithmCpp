#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int n, m;
int K, L;
char S;
vector<int> win[50001];
vector<int> loser[50001];
int parent[50001];
vector<int> group[50001];


int Find(int x)
{
	if (x == parent[x]) {
		return x;
	}
	else {
		int y = Find(parent[x]);
		parent[x] = y;
		return y;
	}
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	parent[y] = x;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	bool flag = true;

	for (int i = 0; i < n; i++)
	{
		parent[i] = i;
	}

	while (m--)
	{
		cin >> K >> S >> L;
		int deg = 0;
		if (S == '=')
		{
			Union(K, L);
		}
		else if (S == '>')
		{	
			int a = Find(K);
			int b = Find(L);
			if (a == b)
			{
				win[K].push_back(L);
				loser[L].push_back(K);
			}
			else
			{
				win[K].push_back(L);
				loser[L].push_back(K);
			}
		}
	}

	for (int i = 0; i < n; i++) // 이기는데 비겼을때
	{
		for (int j = 0; j < win[i].size(); j++)
		{
			int a = Find(win[i][j]);
			int b = Find(i);
			if (a == b)
			{
				flag = false;
			}
		}
		for (int j = 0; j < loser[i].size(); j++) // 지는데 비겼을때
		{
			int a = Find(loser[i][j]);
			int b = Find(i);
			if (a == b)
			{
				flag = false;
			}
		}
	}
	for (int i = 0; i < n; i++) // 이기는데 졌을때
	{
		for (int j = 0; j < win[i].size(); j++)
		{
			int loser1 = Find(win[i][j]);
			int winer = Find(i);
			for (int k = 0; k < win[loser1].size(); k++)
			{
				if (win[loser1][k] == winer)
				{
					flag = false;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) // 지는데 이겼을때
	{
		for (int j = 0; j < loser[i].size(); j++)
		{
			int winer = loser[i][j];
			int loser1 = i;
			for (int k = 0; k < loser[winer].size(); k++)
			{
				if (loser[winer][k] == loser1)
				{
					flag = false;
				}
			}
		}
	}
	if (flag == false)
	{
		cout << "inconsistent";
	}
	else
	{
		cout << "consistent";
	}




	return 0;
}