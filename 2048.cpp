#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int n;
int map[21][21];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	


	return 0;
}