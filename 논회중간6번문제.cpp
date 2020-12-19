#include <iostream>
#include <string>
using namespace std;

string result;
char c;
int cnt;

int main()
{
	cout << "ascii : ";
	cin >> c;
	int tmp = c;
	for (int i = 0; i < 8; i++)
	{
		if (tmp == 0)
		{
			result = "0" + result;
			continue;
		}
		if (tmp % 2 == 1)
		{
			result = "1" + result;
			tmp /= 2;
			cnt++;
		}
		else
		{
			result = "0" + result;
			tmp /= 2;
		}
	}

	int p = 0;
	if (cnt % 2 == 0)
	{
		p = 0;
	}
	else
	{
		p = 1;
	}
	cout << (int)c << endl;
	cout << p << " " << result;


	return 0;
}