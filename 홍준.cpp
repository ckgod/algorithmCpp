#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
#define INF 99999999

int school[200001];
int n;
long long team[2000001];
long long mxP = 0;


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n;
	int right = 0;
	for (int i = 1; i <= n; i++) {
		cin >> school[i];
		right = max(right, school[i]);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= sqrt(school[i]); j++) {
			if (school[i] % j == 0) {
				if (j == school[i] / j) {
					team[j]++;
				}
				else {
					team[j]++;
					team[school[i] / j]++;
				}
			}
		}
	}

	for (int i = 1; i <= right; i++) {
		if (team[i] > 1) {
			long long a = team[i] * i;
			mxP = max(mxP, a);
		}
	}
	cout << mxP;


	return 0;
}