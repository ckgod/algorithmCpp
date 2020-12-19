#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

struct node {
	int num;
	int weight;
};

vector<pair<int,int>> g[16];
int n;
int ans;
int dp[16][16][1025];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < n; j++) {
			if (i != j) {
				g[i + 1].push_back({ j + 1,str[j] });
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		
	}

	return 0;
}