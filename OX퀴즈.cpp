#include <iostream>
#include <string>
using namespace std;

int t;
int sc;
int ans;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> t;
	string* str = new string[t];

	for(int i = 0; i < t; i++)
	{
		cin >> str[i];
		for (int j = 0; j < str[i].size(); j++)
		{
			if (str[i][j] == 'O')
			{
				sc++;
				ans += sc;
			}
			else if (str[i][j] == 'X')
			{
				sc = 0;
			}
		}
		cout << ans << endl;
		sc = 0;
		ans = 0;
	}
	
	return 0;
}