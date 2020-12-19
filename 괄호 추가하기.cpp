#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;

string tc;
int maxS;
int N;
vector<char> shake;

string makesic(string tc)
{
	stack<char> s;
	string str = tc;
	string ans;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			ans += str[i];
		}
		else if (str[i] == '(')
		{
			s.push(str[i]);
		}
		else if (str[i] == ')')
		{
			while (!s.empty() && s.top() != '(')
			{
				ans += s.top();
				s.pop();
			}
			s.pop();
		}
		else if (str[i] == '*' || str[i] == '/')
		{
			while (!s.empty() && (s.top() == '*' || s.top() == '/'))
			{
				ans += s.top();
				s.pop();
			}
			s.push(str[i]);
		}
		else if (str[i] == '+' || str[i] == '-')
		{
			while (!s.empty() && s.top() != '(')
			{
				ans += s.top();
				s.pop();
			}
			s.push(str[i]);
		}
	}
	while (!s.empty())
	{
		ans += s.top();
		s.pop();
	}

	return ans;
}

int reward(string ans)
{
	stack<int> s;
	int n1, n2 = 0;
	for (int i = 0; i < ans.length(); i++)
	{
		if (ans[i] >= '0' && ans[i] <= '9')
		{
			s.push(ans[i] - '0');
		}
		else
		{
			if (s.empty())
			{
				return -1;
			}
			n1 = s.top();
			s.pop();
			if (s.empty())
			{
				return -1;
			}
			n2 = s.top();
			s.pop();
			int tmp;
			if (ans[i] == '+')
			{
				tmp = n1 + n2;
				s.push(tmp);
			}
			else if (ans[i] == '-')
			{
				tmp = n2 - n1;
				s.push(tmp);
			}
			else if (ans[i] == '*')
			{
				tmp = n2 * n1;
				s.push(tmp);
			}
		}
	}
	if (s.empty())
	{
		return -1;
	}
	return s.top();
}


int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N;
	cin >> tc;
	string sic = makesic(tc);
	for (int i = 2; i < sic.length(); i++)
	{
		shake.push_back(sic[i]);
	}
	do
	{
		for (int i = 0; i < N; i++)
		{
			maxS = max(maxS,reward(sic));
		}
	} while (next_permutation(shake.begin(),shake.end()));
	
	cout << maxS;

	return 0;
}