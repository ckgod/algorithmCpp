#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 9999999

int scoreBoard[21][21];
int dp[21];
int N;
int weight;
vector<int> n;
vector<int> ind;
vector<int> team1;
vector<int> team2;
vector<int> person;
int team1S;
int team2S;
int result = INF;


int absol(int n1, int n2)
{
	if (n1 < n2) return n2 - n1;
	else return n1 - n2;
}

void NPsetting(int N)
{
	for (int i = 0; i < N; i++)
	{
		n.push_back(i + 1);
	}
	for (int i = 0; i < N/2; i++)
	{
		ind.push_back(1);
	}
	for (int i = 0; i < n.size()/2; i++)
	{
		ind.push_back(0);
	}
	sort(ind.begin(), ind.end());
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	NPsetting(N);
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> weight;
			scoreBoard[i][j] = weight;
		}
	}
	do {
		for (int i = 0; i < ind.size(); i++)
		{
			if (ind[i] == 1) {
				team1.push_back(n[i]);
			}
			else {
				team2.push_back(n[i]);
			}
		}
		for (int i = 0; i < team1.size(); i++)
		{
			dp[team1[i]] = 1;
		}
		for (int i = 0; i < team2.size(); i++)
		{
			dp[team2[i]] = 2;
		}
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <=N ; j++)
			{
				if (dp[i] == 1 && dp[j] == 1)
				{
					team1S += scoreBoard[i][j];
				}
				else if (dp[i] == 2 && dp[j] == 2)
				{
					team2S += scoreBoard[i][j];
				}
			}
		}
		result = min(result, absol(team1S, team2S));
		team1S = 0;
		team2S = 0;
		team1.clear();
		team2.clear();
	} while (next_permutation(ind.begin(), ind.end()));

	cout << result;

	return 0;
}