#include <iostream>
using namespace std;

int n;
int cnt;
int main()
{
	cin >> n;
	while (n != 0)
	{
		n -= 3;
		cnt++;
	}

	cout << cnt;
	return 0;
}