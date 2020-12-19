#include <iostream>
#include<cstring>
using namespace std;

int c;
double n;
double s[1001];
double sum;
double cnt;
double ans;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);


	cin >> c;
	for (int i = 0; i < c; i++)
	{
		cin >> n;
		for (int j = 0; j < n; j++)
		{
			cin >> s[j];
			sum += s[j];
		}
		for (int j = 0; j < n; j++)
		{
			if (sum / n < s[j])
			{
				cnt++;
			}
		}
		ans = ((cnt / n) * 100);
		cout << fixed;
		cout.precision(3);
		cout << ans << "%\n";
		sum = 0;
		cnt = 0;
		memset(s, 0, sizeof(s));
	}


	return 0;
}