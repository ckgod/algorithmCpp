#include <iostream>
#include <vector>
using namespace std;
#define Num 100;


int n, m;
// n 정점의 개수  m 간선의 개수
vector<pair<int, int>> v[100]; // 인접 리스트

int map[100][100]; // 인접행렬
int vertex, edge;
int vt1, vt2;
int stor;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);


	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> vt1 >> vt2 >> stor;
		v[vt1].push_back({ vt2,stor });
		v[vt2].push_back({ vt1,stor });
		map[vt1][vt2] = stor;
		map[vt2][vt1] = stor;
	}
	cout << "--List--\n";
	for (int i = 1; i <= n; i++)
	{
		cout << "정점 " << i << " : ";
		if (v[i].size() == 0)
		{
			cout << "Nothing\n";
			continue;
		}
		for (int j = 0; j < v[i].size(); j++)
		{
			cout << "(" << v[i][j].first << "," << v[i][j].second << ") ";
		}
		cout << "\n";
	}
	cout << "--matrix--\n";
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}