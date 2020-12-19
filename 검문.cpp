#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int p;
vector<int> arr;
vector<int> ans;

int gcd(int a, int b)
{
	if (a < b)
		swap(a, b);
	if (b == 0) 
		return a;
	else 
		return gcd(b, a % b);
}


int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		arr.push_back(tmp);
	}
	sort(arr.begin(), arr.end());
	p = arr[1] - arr[0];
	for (int i = 2; i < arr.size(); i++)
	{
		p = gcd(p, arr[i] - arr[i - 1]);
	}
	for (int i = 2; i * i <= p; i++)
	{
		if (p % i == 0)
		{
			ans.push_back(i);
			ans.push_back(p / i);
		}
	}
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << " ";
	}
	return 0;
}