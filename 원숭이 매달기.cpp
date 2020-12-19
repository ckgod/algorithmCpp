#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

int t;

int main() {
	cin >> t;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	while (t--) {
		string s;
		getline(cin, s);
		int dep = 0;
		int maxD = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '[') {
				dep++;
			}
			else {
				dep--;
			}
			maxD = max(dep, maxD);
		}
		cout << (int)pow(2, maxD) << "\n";
		// -> 이렇게하면 왜 틀리는지
		//cout << (1 << maxD) << "\n";
	}

	return 0;
}