#include <iostream>
using namespace std;

int n; // ÀÚ¸®¼ö
int num;
int tmp;
int t;
int w;
bool flag = true;
int sum;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> num;
	tmp = num;
	while (tmp >= 1)
	{
		tmp = tmp / 10;
		n++;
	}
	int* arr = new int[n];
	t = num - (n * 9);
	w = t;



	for (int i = n - 1; i >= 0; i--)
	{
		arr[i] = w % 10;
		w /= 10;
	}

	while (flag != 0)
	{
		for (int i = 0; i < n; i++)
		{
			sum += arr[i];
		}
		if (sum + t == num)
		{
			flag == false;
			break;
		}
		else if (num == t)
		{
			t = 0;
			break;
		}
		else
		{
			t++;
			w = t;
			sum = 0;
			for (int i = n - 1; i >= 0; i--)
			{
				arr[i] = w % 10;
				w /= 10;
			}
		}
		
		
	}
	cout << t;


	delete[] arr;
	return 0;
}