#include <iostream>
#include <string>
#include <stack>
using namespace std;

stack<char> s;
string str;
string ans;


int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> str;
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
	
	cout << ans << "\n";


	return 0;
}