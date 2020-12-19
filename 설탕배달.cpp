#include <iostream>
#include <algorithm>
using namespace std;

int n;
int cnt;
int c5, c3;
int tmp;
int p1, p2;

int search(int n)
{
	if (n % 5 == 0)
	{
		cnt = n / 5;
		return cnt;
	}
	else
	{
		tmp = n;
		while (1)
		{
			n -= 5;
			c5++;
			if (n < 0)
			{
				cnt = -1;
				c5 = 10001;
				break;
			}
			if (n % 3 == 0)
			{
				c5 += n / 3;
				break;
			}
		}
		n = tmp;
		while (1)
		{
			n -= 3;
			c3++;
			if (n < 0)
			{
				cnt -1;
				c3 = 10001;
				break;
			}
			if (n == 0)
			{
				break;
			}
			if (n % 5 == 0)
			{
				c3 += n / 5;
				break;
			}
		}
		n = tmp;
		if ((n % 3 != 0) && c5 == 10001)
		{
			return cnt = -1;
		}
		cnt = min(c3, c5);
		if (n % 3 == 0)
		{
			if (cnt == -1)
			{
				cnt = n / 3;
				return cnt;
			}
			p1 = n / 3;
			cnt = min(p1, cnt);
		}
		return cnt;
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;


	cout << search(n);



	return 0;
}