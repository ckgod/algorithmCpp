#include <iostream>
#include <stack>
#include <string>
using namespace std;

double al[91];
string str;
int an;
stack<double> s;
double result;
double n1, n2;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> an;
	cin >> str;
	for (int i = 65; i < 65+an; i++)
	{
		cin >> al[i];
	}
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			s.push(al[str[i]]);
		}
		else if (str[i] == '*')
		{
			n1 = s.top();
			s.pop();
			n2 = s.top();
			s.pop();
			result = n1 * n2;
			s.push(result);
		}
		else if (str[i] == '/')
		{
			n1 = s.top();
			s.pop();
			n2 = s.top();
			s.pop();
			result = n2 / n1;
			s.push(result);
		}
		else if (str[i] == '+')
		{
			n1 = s.top();
			s.pop();
			n2 = s.top();
			s.pop();
			result = n1 + n2;
			s.push(result);
		}
		else if (str[i] == '-')
		{
			n1 = s.top();
			s.pop();
			n2 = s.top();
			s.pop();
			result = n2 - n1;
			s.push(result);
		}
	}
	result = s.top();
	cout << fixed;
	cout.precision(2);
	cout << result << "\n";

	return 0;
}