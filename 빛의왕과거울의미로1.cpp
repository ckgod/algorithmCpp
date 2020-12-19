#include<iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

class room {
public:
	char state;
	bool visit;
	room()
	{
		this->state = '.';
		this->visit = false;
	}
};


int N, M, x, y;
string str;
room* map[9][9];


int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N >> M >> x >> y;
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		for (int j = 0; j < M; j++)
		{
			map[i][j]->state = str[j];
		}
	}




	return 0;
}