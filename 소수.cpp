#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int M, N;
int sum;
int minN = 10001;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> M >> N;
	for (int i = M; i <= N; i++)
	{
		bool chk = false;
		for (int j = 2; j <= (int)sqrt(i)+1; j++)
		{
			if (i == 1) break;
			if (i % j == 0)
			{
				break;
			}
			if (j == (int)sqrt(i)+1)
			{
				chk = true;
			}
		}
		if (chk == true || i == 2)
		{
			sum += i;
			minN = min(i, minN);
		}
	}
	if (sum == 0)
	{
		cout << -1;
	}
	else
	{
		cout << sum << "\n" << minN;
	}



	return 0;
}