#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

pair<int, int> p;
vector<int> v[10];
vector<pair<int, int> > vvv;
int n;
int t;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> t;

	while (t--)
	{
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < i + 1; j++)
			{
				v[i].push_back(j + 1);
				cout << v[i][j] << " ";
			}
			cout << "\n";
		}
	}



	return 0;
}