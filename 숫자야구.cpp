#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n;
int cnt;
vector<pair<string, pair<int, int>>> list;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		int a, b;
		cin >> str >> a >> b;
		list.push_back({ str,{a,b} });
	}
	for (int i = 100; i < 999; i++) {
		bool collect = true;
		string answer = to_string(i);
		if (answer[0] == answer[1] || answer[0] == answer[2] || answer[1] == answer[2]) {
			continue;
		}
		if (answer[1] == '0' || answer[2] == '0') continue;
		for (int j = 0; j < list.size(); j++) {
			int strike = 0;
			int ball = 0;
			string comp = list[j].first;
			for (int k = 0; k < 3; k++) {
				if (comp[k] == answer[k]) {
					strike++;
					continue;
				}
				for (int p = 0; p < 3; p++) {
					if (p == k) continue;
					if (comp[p] == answer[k]) ball++;
				}
			}
			if (strike != list[j].second.first || ball != list[j].second.second) {
				collect = false;
			}
		}
		if (collect) cnt++;
	}
	cout << cnt << "\n";
	return 0;
}