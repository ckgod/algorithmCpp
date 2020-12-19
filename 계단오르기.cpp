#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int st[301]; // 계단 점수가들어감
int dp[301]; // dp[i] -> i계단의 점수 최댓값이 들어감
int n;


int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;
	st[0] = 0;
	for(int i = 1; i <= n; i++)
	{
		cin >> st[i];
	}
	dp[1] = st[1];
	dp[2] = st[1] + st[2];
	dp[3] = max(st[1], st[2]) + st[3];

	for (int i = 4; i <= n; i++)
	{
		dp[i] = max(dp[i - 2], dp[i - 3] + st[i - 1]) + st[i];
	}

	cout << dp[n];



	return 0;
}