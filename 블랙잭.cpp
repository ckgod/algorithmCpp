#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[101];
int ans = -1;
int gap;

int search(int n, int m)
{
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			for (int k = j - 1; k >= 0; k--)
			{
				if (arr[k] + arr[j] + arr[i] > m)
				{
					continue;
				}
				else
				{
					int temp = arr[k] + arr[j] + arr[i];
					ans = max(temp, ans);
				}
			}
		}
	}
	return ans;
}


int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + n);

	cout << search(n, m);


	return 0;
}