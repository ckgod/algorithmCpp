#include <iostream>
#include <cstring>
using namespace std;


int t;
int n;
int s[11];
int cnt;


int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	s[1] = 1, s[2] = 2, s[3] = 4;
	for (int i = 4; i < 11; i++)
	{
		s[i] = s[i - 3] + s[i - 2] + s[i - 1];
	}

	cin >> t;

	while (t--)
	{
		cin >> n;
		cout << s[n] << "\n";
	}



	return 0;
}