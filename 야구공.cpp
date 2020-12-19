#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int sunsu[51][10];
int tmp;
vector<int> board[51];
vector<int> grade[9];
vector<int> pmt;
int maxS;

int playGame()
{
	int player = 0;
	int score = 0;
	for (int i = 0; i < N; i++)
	{
		bool ground[4] = { 0,0,0,0 };
		int outcount = 0;
		int situation = board[i][player];
		while (1)
		{
			if (board[i][player] == 0)//¾Æ¿ô
			{
				outcount++;
				if (outcount == 3)
				{
					player = (player + 1) % 9;
					break;
				}
				else
				{
					player = (player + 1) % 9;
					continue;
				}
			}
			else if (board[i][player] == 1)//¾ÈÅ¸
			{
				if (ground[3]) score++;
				ground[3] = ground[2];
				ground[2] = ground[1];
				ground[1] = true;
			}
			else if (board[i][player] == 2)
			{
				if (ground[3]) score++;
				if (ground[2]) score++;
				ground[3] = ground[1];
				ground[2] = true;
				ground[1] = false;
			}
			else if (board[i][player] == 3)
			{
				if (ground[3]) score++;
				if (ground[2]) score++;
				if (ground[1]) score++;
				ground[3] = true;
				ground[2] = false;
				ground[1] = false;
			}
			else if (board[i][player] == 4)
			{
				score++;
				if (ground[3]) score++;
				if (ground[2]) score++;
				if (ground[1]) score++;
				ground[3] = false;
				ground[2] = false;
				ground[1] = false;
			}
			player = (player + 1) % 9;
		}
	}
	return score;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> tmp;
			sunsu[i][j] = tmp;
		}
	}
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < N; j++)
		{
			grade[i].push_back(sunsu[j][i]);
		}
	}
	
	for (int i = 0; i < 9; i++)
	{
		pmt.push_back(i);
	}
	
	for (int i = 0; i < N; i++)
	{
		board[i].resize(9);
	}
	do
	{
		bool check = false;
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (i == 3 && pmt[i] != 0)
				{
					check = true;
					break;
				}
				board[j][i] = grade[pmt[i]][j];
			}
			if (check == true) break;
		}
		if (check == true)
		{
			continue;
		}
		else
		{
			maxS = max(maxS, playGame());
		}
	} while (next_permutation(pmt.begin(),pmt.end()));

	cout << maxS;
	
	return 0;
}