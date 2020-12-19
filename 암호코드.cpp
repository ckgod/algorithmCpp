#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
#define mod 1000000

string str;
long long dp[5001];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> str;
	
	if (str.size() == 1) {
		if (str[0] == '0') {
			cout << "0";
			return 0;
		}
		else {
			dp[1] = 1;
		}
	}
	else {
		if (str[0] == '0') {
			cout << "0";
			return 0;
		}
		else if(str[0] == '1') {
			if (str[1] == '0') {
				dp[1] = 1;
				dp[2] = 1;
			}
			else {
				dp[1] = 1;
				dp[2] = 2;
			}
		}
		else if (str[0] == '2') {
			if (str[1] == '0') {
				dp[1] = 1;
				dp[2] = 1;
			}
			else if(str[1] < '7') {
				dp[1] = 1;
				dp[2] = 2;
			}
			else {
				dp[1] = 1;
				dp[2] = 1;
			}
		}
		else {
			if (str[1] == '0') {
				cout << "0";
				return 0;
			}
			else {
				dp[1] = 1;
				dp[2] = 1;
			}
		}
	}

	for (int i = 2; i < str.size(); i++) {
		if (str[i - 1] == '1') {
			if (str[i] == '0') {
				dp[i + 1] = dp[i-1] % mod;
			}
			else {
				dp[i + 1] = (dp[i] + dp[i - 1]) % mod;
			}
		}
		else if (str[i - 1] == '2') {
			if (str[i] == '0') {
				dp[i + 1] = dp[i-1] % mod;
			}
			else if (str[i] < '7') {
				dp[i + 1] = (dp[i] + dp[i - 1]) % mod;
			}
			else {
				dp[i + 1] = dp[i] % mod;
			}
		}
		else {
			if (str[i] == '0') {
				cout << "0";
				return 0;
			}
			else {
				dp[i + 1] = dp[i] % mod;
			}
		}
	}

	cout << dp[str.size()];


	return 0;
}