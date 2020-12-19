#include <iostream>
using namespace std;

int n1, n2;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n1 >> n2;
	int a = n1;
	int b = n2;
	while (1)
	{
		if (n2 == 0) break;
		int tmp = n1;
		n1 = n2;
		n2 = tmp % n2;
	}
	int gcd = n1;
	int lcm = a * b / gcd;
	cout << gcd << "\n" << lcm;


	return 0;
}