#include <iostream>
#include <string>
#include <stack>
using namespace std;

string a, b;
stack<int> s;
int sze;
int k;
int tmp;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> a >> b;

	if (a.size() > b.size())
	{
		sze = b.size();
		for (int i = a.size() - 1; i >= 0; i--)
		{
			if (sze == 0)
			{
				tmp = i;
				break;
			}
			if ((a[i] - '0') + (b[sze]-'0') >= 10)
			{
				s.push((a[i] - '0') + (b[sze] - '0') - 10);
				a[i - 1]++;
			}
			else
			{
				s.push((a[i] - '0') + (b[sze] - '0'));
			}
			sze--;
		}
		while (tmp == -1)
		{
			s.push(a[tmp] - '0');
			tmp--;
		}
	}
	else
	{
		sze = a.size();
		for (int i = b.size() - 1; i >= 0; i--)
		{
			if (sze == 0)
			{
				tmp = i;
				break;
			}
			if ((b[i] - '0') + (a[sze] - '0') >= 10)
			{
				s.push((b[i] - '0') + (a[sze] - '0') - 10);
				b[i - 1]++;
			}
			else
			{
				s.push((b[i] - '0') + (a[sze] - '0'));
			}
			sze--;
		}
		while (tmp == -1)
		{
			s.push(b[tmp] - '0');
			tmp--;
		}
	}
	while (!s.empty())
	{
		cout << s.top();
		s.pop();
	}

	return 0;
}