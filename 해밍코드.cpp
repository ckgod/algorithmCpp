#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

string orgdata;
string Hcode;
string result;
int arr[13];
int arr1[13];
int parity[5];

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout << "데이터 원본 : ";
	cin >> orgdata;
	int p;
	int c = 1;
	while(1)
	{
		if (orgdata.length()+c+1 <= pow(2,c))
		{
			p = c;
			break;
		}
		c++;
	}
	cout << p << "\n";
	for (int i = 0; i < p; i++)
	{
		int tmp = pow(2, i);
		arr[tmp] = -1;
	}
	int cc = 0;
	for (int i = 1; i <= p + orgdata.length(); i++)
	{
		if (arr[i] != -1)
		{
			arr[i] = orgdata[cc]-'0';
			cc++;
		}
		cout << arr[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < p; i++)
	{
		int pidx = pow(2, i);
		int cur = pidx;
		int cnt = 0;
		while (1)
		{
			for (int j = 0; j < pidx; j++)
			{
				if (arr[cur] == 1)
				{
					cnt++;
				}
				cur++;
				if (cur > orgdata.length() + p + 1) break;
			}
			cur += pidx;
			if (cur > orgdata.length() + p + 1) break;
		}
		if (cnt % 2 == 1) arr[pidx] = 1;
		else arr[pidx] = 0;
	}
	for (int i = 1; i <= p + orgdata.length(); i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n수신된 데이터: ";
	cin >> Hcode;
	for (int i = 1; i <= Hcode.length(); i++)
	{
		arr1[i] = Hcode[i - 1] - '0';
	}
	for (int i = 0; i < p; i++)
	{
		int pidx = pow(2, i);
		int cur = pidx;
		int cnt = 0;
		while (1)
		{
			for (int j = 0; j < pidx; j++)
			{
				if (arr1[cur] == 1)
				{
					cnt++;
				}
				cur++;
				if (cur > Hcode.length() + p + 1) break;
			}
			cur += pidx;
			if (cur > Hcode.length() + p + 1) break;
		}
		if (cnt % 2 == 1) parity[i+1] = 1;
		else parity[i+1] = 0;
	}
	int t = 0;
	int re = 0;
	for (int i = p; i >= 1; i--)
	{
		parity[i] *= pow(2, t);
		t++;
		parity[0] += parity[i];
	}
	cout << parity[0] << "\n";
	if (parity[0] != 0)
	{
		if (arr1[parity[0]] == 0)
		{
			arr1[parity[0]] = 1;
		}
		else
		{
			arr1[parity[0]] = 0;
		}
	}
	else
	{
		cout << "오류없음\n";
	}
	cout << "수정된 데이터 : ";
	for (int i = 1; i <= Hcode.length(); i++)
	{
		cout << arr1[i];
	}

	return 0;
}