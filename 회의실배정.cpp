#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct discuss {
	int begin;
	int end;
};

vector<discuss> list;
int n;
int cnt;

bool compare(discuss a, discuss b) {
	if (a.end == b.end) {
		return a.begin < b.begin;
	}
	else return a.end < b.end;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		discuss d;
		d.begin = a;
		d.end = b;
		list.push_back(d);
	}
	sort(list.begin(), list.end(), compare);
	int temp = 0;
	for (int i = 0; i < list.size(); i++) {
		if (temp <= list[i].begin) {
			temp = list[i].end;
			cnt++;
		}
	}
	cout << cnt;
	

	return 0;
}