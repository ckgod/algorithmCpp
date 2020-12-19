#include <iostream>
#include <cmath>
using namespace std;


int m;
int n;
int K, J, C;
int ck, cj, cc;
int ak, aj, ac;


int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> n;
		int* arr = new int[n];
		for (int j = 0; j < n; j++)
		{
			cin >> arr[j];
			if (j % 3 == 0)
			{
				K += arr[j];
				if(arr[j] != 0) ck++;
			}
			else if (j % 3 == 1)
			{
				J += arr[j];
				if (arr[j] != 0) cj++;
			}
			else if (j % 3 == 2)
			{
				C += arr[j];
				if (arr[j] != 0) cc++;
			}
		}
		if (K == 0)
		{
			ak = 0;
		}
		else ak = floor(K / ck);
		if (J == 0)
		{
			aj = 0;
		}
		else aj = floor(J / cj);
		if (C == 0)
		{
			ac = 0;
		}
		else ac = floor(C / cc);
		cout << K << " " << J << " " << C << "\n"
			<< ak << " " << aj << " "
			<< ac << "\n";
		K = 0, J = 0, C = 0, ck = 0, cj = 0, cc = 0;
		delete[] arr;
	}





	return 0;
}