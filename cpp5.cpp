#include <iostream>
using namespace std;


int arr[10001];
int n;
int x;


int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> x;
		arr[x]++;
	}

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j < arr[i]; j++)
		{
			cout << i << "\n";
		}
	}

	return 0;
}