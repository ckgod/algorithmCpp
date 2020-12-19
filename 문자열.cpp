#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string str1, str2;
int dif;
int cnt;
int result = 9999;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> str1 >> str2;
	dif = str2.length() - str1.length();
	for (int i = 0; i <= dif; i++) {
		for (int j = 0; j < str1.length(); j++) {
			if (str1[j] != str2[j + i]) {
				cnt++;
			}
		}
		if (result > cnt) {
			result = cnt;
		}
		cnt = 0;
	}
	cout << result;


	return 0;
}