#include <iostream>
using namespace std;

void star(int n, int x, int y);

char t[3072][6144];            // ���� n, ���� 2n-1

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)                    // �켱 �������� �ʱ�ȭ
	{
		for (int j = 0; j < 2 * n - 1; j++)
		{
			t[i][j] = ' ';
		}
	}

	star(n, n - 1, 0);                            // n��, x��ǥ, y��ǥ

	for (int i = 0; i < n; i++)                    // ���
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
	if (n == 3)                                    // n�� 3�̸� �����
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
	else                                        // n�� 3�� �ƴϸ� ����Լ�
	{
		star(n / 2, x, y);
		star(n / 2, x - n / 2, y + n / 2);
		star(n / 2, x - n / 2 + n, y + n / 2);
	}
}