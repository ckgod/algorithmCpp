#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int t;
string str1, str2;
int cnt;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> t;
	while (t--) {
		cin >> str1;
		cin >> str2;
		for (int i = 0; i < str1.size(); i++) {
			if (str1[i] != str2[i]) cnt++;
		}
		cout << "Hamming distance is " << cnt << ".\n";
		cnt = 0;
	}


	return 0;
}