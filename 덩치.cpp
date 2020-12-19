#include <iostream>
using namespace std;

int n;
int cmp;
int cp;

struct person
{
	int w;
	int h;
	int r = 1;
};

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;
	person* p = new person[n];

	for (int i = 0; i < n; i++)
	{
		cin >> p[i].w >> p[i].h;
	}
	for (int i = 0; i < n; i++)
	{
		while (cmp != n - 1)
		{
			if (i == cp)
			{
				cp++;
				continue;
			}
			else
			{
				if (p[i].w < p[cp].w && p[i].h < p[cp].h)
				{
					p[i].r++;
					cp++;
					cmp++;
					continue;
				}
				else
				{
					cp++;
					cmp++;
					continue;
				}
			}
		}
		cp = 0;
		cmp = 0;
	}

	for (int i = 0; i < n; i++)
	{
		cout << p[i].r << " ";
	}



	return 0;
}