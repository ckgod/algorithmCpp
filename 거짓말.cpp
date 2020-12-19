#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n,m;
int knowCnt;
vector<int> party[51];
bool know[51];
int ans;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	cin >> knowCnt;
	for (int i = 0; i < knowCnt; i++) {
		int a;
		cin >> a;
		know[a] = true;
	}
	for (int i = 0; i < m; i++) {
		int t;
		cin >> t;
		for (int j = 0; j < t; j++) {
			int a;
			cin >> a;
			party[i + 1].push_back(a);
		}
	}
	for (int t = 0; t < 51; t++) {
		for (int i = 1; i <= m; i++) {
			bool flag = false;
			for (int k = 0; k < party[i].size(); k++) {
				if (know[party[i][k]]) flag = true;
			}
			if (flag) {
				for (int k = 0; k < party[i].size(); k++) {
					know[party[i][k]] = true;
				}
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		bool flag = false;
		for (int k = 0; k < party[i].size(); k++) {
			if (know[party[i][k]]) flag = true;
		}
		if (!flag) {
			ans++;
		}
	}
	cout << ans;
	return 0;

}