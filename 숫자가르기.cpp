#include <iostream>
using namespace std;
typedef long long ll;

int a, b, c;
int res;
int tmp;
int n;
int ans[10];

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> a >> b >> c;
	
	res = a * b * c;
	tmp = res;
	while (tmp != 0)
	{
		tmp /= 10;
		n++;
	}
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = res % 10;
		res /= 10;
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[j] == i) ans[i]++;
		}
	}
	for (int i = 0; i < 10; i++)
	{
		cout << ans[i] << "\n";
	}
	return 0;
}