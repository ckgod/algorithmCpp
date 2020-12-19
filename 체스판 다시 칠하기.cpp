#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
#define INF 99999999
#define B 1
#define W 0

int n, m;
int minCnt = INF;
bool map[51][51];
int Bcnt;
int Wcnt;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < m; j++) {
			if (str[j] == 'B') map[i][j] = B;
			else map[i][j] = W;
		}
	}
	for(int i = 0; i < n-7; i++) { // i,j가 시작점
		for (int j = 0; j < m-7; j++) {
			int mapcnt = 0;
			bool curState = W;
			for (int p = i; p < i + 8; p++) { // 왼쪽위가 W일때
				for (int q = j; q < j + 8; q++) {
					if (map[p][q] != curState) {
						Wcnt++;
					}
					mapcnt++;
					if (mapcnt > 0 && mapcnt % 8 == 0) {
						continue;
					}
					else {
						curState = !curState;
					}
				}
			}
			curState = B;
			mapcnt = 0;
			for (int p = i; p < i + 8; p++) { // 왼쪽위가 B일때 
				for (int q = j; q < j + 8; q++) {
					if (map[p][q] != curState) {
						Bcnt++;
					}
					mapcnt++;
					if (mapcnt > 0 && mapcnt % 8 == 0) {
						continue;
					}
					else {
						curState = !curState;
					}
				}
			}
			minCnt = min(minCnt, min( Bcnt, Wcnt));
			Bcnt = 0;
			Wcnt = 0;
		}
	}

	cout << minCnt;
	return 0;
}