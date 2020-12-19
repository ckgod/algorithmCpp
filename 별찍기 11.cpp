#include <iostream>
using namespace std;

void star(int n, int x, int y);

char t[3072][6144];            // 세로 n, 가로 2n-1

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)                    // 우선 공백으로 초기화
	{
		for (int j = 0; j < 2 * n - 1; j++)
		{
			t[i][j] = ' ';
		}
	}

	star(n, n - 1, 0);                            // n값, x좌표, y좌표

	for (int i = 0; i < n; i++)                    // 출력
	{
		for (int j = 0; j < 2 * n - 1; j++)
		{
			cout << t[i][j];
		}
		cout << "\n";
	}
	return 0;
}

void star(int n, int x, int y)
{
	if (n == 3)                                    // n이 3이면 별찍기
	{
		t[y][x] = '*';

		t[y + 1][x - 1] = '*';
		t[y + 1][x + 1] = '*';

		t[y + 2][x - 2] = '*';
		t[y + 2][x - 1] = '*';
		t[y + 2][x] = '*';
		t[y + 2][x + 1] = '*';
		t[y + 2][x + 2] = '*';
	}
	else                                        // n이 3이 아니면 재귀함수
	{
		star(n / 2, x, y);
		star(n / 2, x - n / 2, y + n / 2);
		star(n / 2, x - n / 2 + n, y + n / 2);
	}
}