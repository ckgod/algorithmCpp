#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define N 1000001

int n, m;
int parent[N];

int Find(int x)
{
	if (x == parent[x]) return x;
	else
	{
		int p = Find(parent[x]);
		parent[x] = p;
		return p;
	}
}

void Union(int x, int y)
{
	x = Find(x);
	y = Find(y);
	if (x != y)
	{
		parent[y] = x;
	}
}


int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i <= n; i++)
	{
		parent[i] = i;
	}
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 0)
		{
			Union(b, c);
		}
		else if (a == 1)
		{
			if (Find(b) == Find(c))
			{
				cout << "YES\n";
			}
			else
			{
				cout << "NO\n";
			}
		}
	}


	return 0;
}