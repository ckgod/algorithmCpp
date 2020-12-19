#include <iostream>
using namespace std;


int t;
int x;
int y;
int dis;
int ans;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> t;

	while (t--)
	{
		cin >> x >> y;
		dis = y - x;
		if (dis == 1)
		{
			cout << 1 << "\n";
			continue;
		}
		else if (dis == 2)
		{
			cout << 2 << "\n";
			continue;
		}
		else if (dis == 0)
		{
			cout << 0 << "\n";
			continue;
		}
		int k = (dis-3) / 5;
		int t = (dis-3) % 5;
		ans = 4 + (k * 2);
		if (t == 0 || t == 1)
		{
			ans--;
		}
		cout << ans << "\n";
	}



	return 0;
}