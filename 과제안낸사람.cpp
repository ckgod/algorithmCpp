#include <iostream>
#include <algorithm>
using namespace std;

int arr[28];
bool chk[31];
int ans[30];

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	for (int i = 0; i < 28; i++)
	{
		cin >> arr[i];
	}
	sort(arr,arr + 28);
	
	for (int i = 0; i < 28; i++)
	{
		chk[arr[i]] = true;
	}
	for (int i = 1; i < 31; i++)
	{
		if (chk[i] == false)
		{
			ans[i] = i;
		}
	}
	for (int i = 1; i <= 30; i++)
	{
		if (ans[i] != 0)
		{
			cout << ans[i] << "\n";
		}
	}

	return 0;
}