#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int k;
vector<int> S;
vector<int> tmp;
int t;

void findS(int start)
{
	if (start == k)
	{
		if (tmp.size() == 6)
		{
			for (int i = 0; i < tmp.size(); i++)
			{
				cout << tmp[i] << " ";
			}
			cout << "\n";
		}
	}
	else
	{
		tmp.push_back(S[start]);
		findS(start + 1);
		tmp.pop_back();
		findS(start + 1);
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	while (1)
	{
		cin >> k;
		if (k == 0) break;
		for (int i = 0; i < k; i++)
		{
			cin >> t;
			S.push_back(t);
		}
		findS(0);
		cout << "\n";
		S.clear();
		tmp.clear();
	}



	return 0;
}