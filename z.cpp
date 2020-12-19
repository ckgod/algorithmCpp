#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int n;
int arr[2 ^ 15][2 ^ 15];
int m1[] = { 0,1};
int n1[] = { 1,-1 };
int r, c;
queue<pair<int, int>> q;
int cnt;

void zfunction(int x, int y)
{
	arr[x][y] = cnt;
	arr[x][y + 1] = ++cnt;
	arr[x + 1][y - 1] = ++cnt;
	arr[x + 1][y + 1] = ++cnt;
}


int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> r >> c;
	for (int i = 0; i <= 2*n; i+=2)
	{
		for (int j = 0; j <= 2*n; j += 2)
		{
			q.push({ i,j });
		}
	}
	while (!q.empty())
	{
		cout << q.front().first << " " << q.front().second << "\n";
		q.pop();
	}


	return 0;
}