#include <iostream>
#include <cmath>
using namespace std;

int t;
bool isP[10001];
int n;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	for (int i = 2; i < (int)sqrt(10001); i++)
	{
		if (isP[i] == true) continue;
		for (int j = 2 * i; j < 10001; j += i)
		{
			isP[j] = true;
		}
	}

	cin >> t;

	while (t--)
	{
		cin >> n;
		int n1 = n/2;
		int n2 = n / 2;
		while (1)
		{
			if (isP[n2] == false && isP[n1] == false && n1 + n2 == n)
			{
				break;
			}
			n1--;
			n2++;
		}
		cout << n1 << " " << n2 << "\n";
	}

	return 0;
}