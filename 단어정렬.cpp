#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct word {
	string w;
	int size;
};

int n;
vector<word> arr;

bool comp(word w1, word w2) {
	if (w1.size == w2.size) return w1.w < w2.w;
	else return w1.size < w2.size;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) {
		word a;
		string str;
		cin >> str;
		a.w = str;
		a.size = str.size();
		arr.push_back(a);
	}
	sort(arr.begin(), arr.end(), comp);
	cout << arr[0].w << "\n";
	for (int i = 1; i < arr.size(); i++) {
		if (arr[i].w == arr[i - 1].w) continue;
		cout << arr[i].w << "\n";
	}

	return 0;
}