#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
#define saro -100

int n, l;
int mp[101][101];
int horizonMp[101][101];
int ans;

int absol(int a, int b) {
	if (a > b) return a - b;
	else return b - a;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mp[i][j];
			horizonMp[i][j] = mp[i][j];
		}
	}
	// 가로길 확인
	for (int i = 0; i < n; i++) {
		int prevH = mp[i][0];
		int curL = 1;
		int checkLowL = 0;
		bool chkDown = false;
		for (int j = 1; j < n; j++) {
			if (absol(prevH, mp[i][j]) >= 2) break;
			if (chkDown) {
				if (prevH == mp[i][j]) {
					checkLowL++;
					if (checkLowL >= l) {
						curL = 0;
					}
					if (j == n - 1) {
						ans++;
						break;
					}
				}
				else if (prevH < mp[i][j]) {
					if(checkLowL)
					if (curL >= l) {
						curL = 1;
						prevH = mp[i][j];
						if (j == n - 1) {
							ans++;
							break;
						}
					}
					else {
						break;
					}
				}
				else if (prevH > mp[i][j]) {
					chkDown = true;
					prevH = mp[i][j];
					checkLowL++;
					if (j == n - 1) {
						if (l == 1) {
							ans++;
							break;
						}
						else break;
					}
				}
			}
			else {
				if (prevH == mp[i][j]) {
					curL++;
					if (j == n - 1) {
						ans++;
						break;
					}
				}
				else if (prevH < mp[i][j]) {
					if (curL >= l) {
						curL = 1;
						prevH = mp[i][j];
						if (j == n - 1) {
							ans++;
							break;
						}
					}
					else {
						break;
					}
				}
				else if (prevH > mp[i][j]) {
					chkDown = true;
					prevH = mp[i][j];
					checkLowL++;
					if (j == n - 1) {
						if (l == 1) {
							ans++;
							break;
						}
						else break;
					}
				}
			}
		}
	}

	return 0;
}