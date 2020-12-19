#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> arr;
vector<int> dp1;
vector<int> dp2;
int tc;
int n, m;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> tc;
	while (tc--)
	{
		int result;
		int s;
		cin >> n;
		s = n;
		while (n--)
		{
			cin >> m;
			arr.push_back(m);
			dp1.push_back(-1111);
			dp2.push_back(-1111);
		}
		for (int i = 0; i < arr.size(); i++)
		{
			if (i == 0)
			{
				dp2[i] = arr[i];
			}
			else
			{
				int x = max(dp1[i - 1], dp2[i - 1]);
				dp1[i] = x;
				int y = max(dp2[i - 1] + arr[i], arr[i]);
				dp2[i] = y;
			}
		}
		result = max(dp1[s-1], dp2[s-1]);
		cout << result << endl;
		dp1.clear();
		dp2.clear();
		arr.clear();
	}


	return 0;
}