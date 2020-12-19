#include <iostream>
using namespace std;

int n;
int ring[101];

int gcd(int a, int b)
{
	if (b == 0) return a;
	else return gcd(b, a % b);
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> ring[i];
	}
	for (int i = 1; i < n; i++)
	{
		int Gd = gcd(ring[0], ring[i]);
		cout << ring[0] / Gd << "/" << ring[i] / Gd << "\n";
	}




	return 0;
}