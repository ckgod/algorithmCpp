#include <iostream>
#include <cmath>
using namespace std;

int n = 1;
bool isP[246913];

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	for (int i = 2; i <= (int)sqrt(246913); i++)
	{
		if (isP[i] == true) continue;
		for (int j = 2 * i; j <= 246913; j += i)
		{
			isP[j] = true;
		}
	}

	while (1)
	{
		cin >> n;
		if (n == 0) break;
		int cnt = 0;
		for (int i = n + 1; i <= 2 * n; i++)
		{
			if (isP[i] == false) cnt++;
		}
		cout << cnt << "\n";
	}


	return 0;
}