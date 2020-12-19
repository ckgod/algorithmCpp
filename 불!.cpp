#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;


int r, c;
char map[1001][1001];
string str;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		cin >> str;
		for (int j = 0; j < r; j++) {
			map[i][j] = str[j];
		}
	}



	return 0;
}