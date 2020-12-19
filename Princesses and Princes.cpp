#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define married 1
#define notMarried 0

int t;
int n;
vector<int> princess[100001];
bool prince[100001];
bool checkPrincess[100001];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> t;
	while (t--) {
		cin >> n;
		bool opti;
		int girlNum = -1;
		int manNum = -1;
		for (int i = 1; i <= n; i++) {
			int num;
			cin >> num;
			for (int j = 0; j < num; j++) {
				int a;
				cin >> a;
				princess[i].push_back(a);
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < princess[i].size(); j++) {
				if (prince[princess[i][j]] == married) {
					continue;
				}
				else {
					prince[princess[i][j]] = married;
					checkPrincess[i] = married;
					break;
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			if (prince[i] == notMarried) {
				manNum = i;
			}
			if (checkPrincess[i] == notMarried) {
				girlNum = i;
			}
		}
		if (girlNum == -1 || manNum == -1) {
			cout << "OPTIMAL\n";
		}
		else {
			cout << "IMPROVE\n";
			cout << girlNum << " " << manNum << "\n";
		}
		for (int i = 1; i <= n; i++) {
			princess[i].clear();
		}
		for (int i = 0; i < 106; i++) {
			prince[i] = false;
			checkPrincess[i] = false;
		}
	}



	return 0;
}