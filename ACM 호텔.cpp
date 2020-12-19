#include <iostream>
#include <string>
using namespace std;

int map[100][100];
int H, W, N;
int cnt;
int t;
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> t;
	while (t--)
	{
		cin >> H >> W >> N;
		cnt = 0;
		for (int i = 1; i <= W; i++)
		{
			for (int j = 1; j <= H; j++)
			{
				map[j][i] = ++cnt;
				if (cnt == N)
				{
					if (i < 10)
					{
						cout << j << "0" << i << "\n";
					}
					else
					{
						cout << j << i << "\n";
					}
				}
			}
		}

	}


	return 0;
}