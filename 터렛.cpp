#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;


int x1, x2, ypos1, y2, r1, r2;
int tc;
int dis;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> tc;
	while (tc--)
	{
		cin >> x1 >> ypos1 >> r1 >> x2 >> y2 >> r2;
		dis = sqrt(pow((x1 - x2), 2) + pow((ypos1 - y2), 2));
		if (dis == 0 && r1 == r2)
		{
			cout << -1 << endl;
		}
		else if (dis == 0 && r1 != r2)
		{
			cout << 0 << endl;
		}
		else if (dis < r1 + r2)
		{
			if ((max(r1, r2) - min(r1, r2)) == dis)
			{
				cout << 1 << endl;
			}
			else
			{
				cout << 2 << endl;
			}
		}
		else if (dis == r1 + r2)
		{
			cout << 1 << endl;
		}
		else if (dis > r1+r2)
		{
			cout << 0 << endl;
		}

	}


	return 0;
}