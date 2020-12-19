#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


int word[11][11];
bool alpha[27];
int alphaIdx[27];
vector<char> stor;

string str[11];
int n;
int useCnt = 0;
vector<int> alloNum;
long long ans;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str[i];
		for (int j = 0; j < str[i].size(); j++) {
			if (alpha[str[i][j] - 'A' + 1]) continue;
			alpha[str[i][j] - 'A' + 1] = true;
			stor.push_back(str[i][j]);
		}
	}
	for (int i = 1; i <= 26; i++) {
		alphaIdx[i] = -1;
		if (alpha[i]) useCnt++;
	}
	for (int i = 0; i < stor.size(); i++) {
		alphaIdx[stor[i] - 'A' + 1] = i;
	}


	int nine = 10 - useCnt;

	for (int i = useCnt; i > 0; i--) {
		alloNum.push_back(nine);
		nine++;
	}

	do {
		long long sum = 0;
		for (int i = 0; i < n; i++) {
			int tmp = 0;
			for (int j = 0; j < str[i].size(); j++) {
				tmp *= 10;
				tmp += alloNum[alphaIdx[str[i][j] - 'A' + 1]];
			}
			sum += tmp;
		}
		ans = max(ans, sum);
	} while (next_permutation(alloNum.begin(), alloNum.end()));

	cout << ans;

	return 0;
}