#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct fort {
	int begin;
	int end;
	int gap;
};

int n;
vector<fort> list;

bool comp(fort p1, fort p2) {
	if (p1.gap == p2.gap) return p1.end < p2.end;
	else return p1.gap< p2.gap;
}

int absol(int a) {
	if (a < 0) return -a;
	else return a;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		fort f;
		f.begin = i;
		f.end = a;
		f.gap = absol(i - a);
		list.push_back(f);
	}
	sort(list.begin(), list.end(), comp);

	int firstFort = list[0].begin;
	int secondFort = list[0].end;
	int ans = 1;

	for (int i = 0; i < list.size(); i++) {
		cout << list[i].begin << " " << list[i].end << " " << list[i].gap << "\n";
		if (firstFort < list[i].begin && secondFort < list[i].end) {
			firstFort = list[i].begin;
			secondFort = list[i].end;
			ans++;
		}
	}
	cout << ans;

	return 0;
}