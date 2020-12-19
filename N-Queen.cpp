#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, cnt;
vector<pair<int, int>> pos;

int absol(int m)
{
	if (m < 0)
	{
		return m * -1;
	}
	else
	{
		return m;
	}
}


void Queen(int idx)
{
	bool flag = true;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < pos.size(); j++)
		{
			if (i == pos[j].second) // 일직선
			{
				flag = false;
			}
			else if (absol(pos[j].first - idx) == absol(pos[j].second - i)) // 대각선
			{
				flag = false;
			}
		}
		if (flag)
		{
			pos.push_back({ idx,i });
			if (idx == N - 1)
			{
				if (pos.size() == N)
				{
					cnt++;
					pos.pop_back();
					continue;
				}
				else
				{
					pos.pop_back();
					continue;
				}
			}
			Queen(idx + 1);
			pos.pop_back();
		}
		else
		{
			flag = true;
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N;
	Queen(0);
	cout << cnt;

	return 0;
}