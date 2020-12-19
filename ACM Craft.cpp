#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;


int tc;
int N, M;
int BT[1001];
int dp[1001];
vector<int> v[1001];
int w;

int tTime(int des)
{
	if (dp[des] != -1) return dp[des];
	int time = 0;
	if (v[des].size() == 0)
	{
		dp[des] = BT[des];
		return dp[des];
	}
	for (int i = 0; i < v[des].size(); i++)
	{
		dp[des] = max(dp[des], tTime(v[des][i]));
	}
	dp[des] += BT[des];
	return dp[des];
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> tc;
	while (tc--)
	{
		cin >> N >> M;
		for (int i = 1; i <= N; i++)
		{
			cin >> BT[i];
			dp[i] = -1;
		}
		for (int i = 0; i < M; i++)
		{
			int a, b;
			cin >> a >> b;
			v[b].push_back(a);
		}
		cin >> w;
		cout << tTime(w) << "\n";
		for (int i = 0; i <= N; i++)
		{
			BT[i] = 0;
			dp[i] = 0;
			v[i].clear();
		}
	}


	return 0;
}