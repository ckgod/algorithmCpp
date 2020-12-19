#include <iostream>
using namespace std;

int t, n;

int dpz[41];
int dpo[41];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	dpz[0] = 1;
	dpo[0] = 0;
	dpz[1] = 0;
	dpo[1] = 1;
	dpz[2] = 1;
	dpo[2] = 1;
	for (int i = 3; i < 41; i++) {
		dpz[i] = dpz[i - 1] + dpz[i - 2];
		dpo[i] = dpo[i - 1] + dpo[i - 2];
	}

	cin >> t;
	while (t--) {
		cin >> n;
		cout << dpz[n] << " " << dpo[n] << "\n";
	}

	return 0;
}