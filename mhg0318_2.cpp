#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
#define INF 99999999

int t, n, dis;
string Dna[51];
int dp[4][1001];
int hamming = INF;
char ACGT[] = { 'A','C','G','T' };
int resultCheck[1001];
string result;
int sum;
// A - C - G - T

void init() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 1001; j++) {
			dp[i][j] = 0;
		}
	}
	for (int j = 0; j < 1001; j++) {
		resultCheck[j] = 0;
	}
	for (int i = 0; i < 51; i++) {
		Dna[i] = "";
	}
	hamming = INF;
	sum = 0;
	result = "";
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> t;
	while (t--) {
		cin >> n >> dis;
		for (int i = 0; i < n; i++) {
			cin >> Dna[i];
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < dis; j++) {
				for (int k = 0; k < 4; k++) {
					if (Dna[i][j] != ACGT[k]) {
						dp[k][j]++;
					}
				}
			}
		}
		for (int i = 0; i < dis; i++) {
			for (int j = 0; j < 4; j++) {
				if (hamming > dp[j][i]) {
					hamming = dp[j][i];
					resultCheck[i] = j;
				}
			}
			hamming = INF;
			result += ACGT[resultCheck[i]];
		}
		cout << result << "\n";

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < dis; j++) {
				if (result[j] != Dna[i][j]) {
					sum++;
				}
			}
		}
		cout << sum << "\n";
		init();
	}


	return 0;
}