#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

struct price {
	int first;
	int second;
	int gap;
};

int n;
vector<price> foodF;
vector<price> foodG;
long long sumF;
long long sumG;
long long ans[500001];
long long tempF;
long long tempG;
map<int, int> dM;

int absol(int a) {
	if (a < 0) return -a;
	else return a;
}

bool compF(price f1, price f2) {
	if (f1.first == f2.first) return f1.gap < f2.gap;
	else return f1.first < f2.first;
}

bool compG(price f1, price f2) {
	if (f1.second == f2.second) return f1.gap < f2.gap;
	else return f1.second < f2.second;
}


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		price c;
		c.first = a;
		c.second = b;
		c.gap = absol(b - a);
		foodF.push_back(c);
		foodG.push_back(c);
	}
	sort(foodF.begin(), foodF.end(), compF);
	sort(foodG.begin(), foodG.end(), compG);


	sumF = foodF[0].first;
	sumG = foodG[0].first;
	tempF = foodF[0].first;
	tempG = foodG[0].first;
	ans[0] = min(sumF, sumG);
	cout << ans[0] << "\n";

	for (int i = 1; i < n; i++) {
		/*sumF -= tempF;
		sumG -= tempG;

		sumF += foodF[i].first;
		sumG += foodG[i].first;

		sumF += foodF[i - 1].second;
		sumG += foodG[i - 1].second;

		tempF = foodF[i].first;
		tempG = foodG[i].first;

		ans[i] = min(sumF, sumG);*/
		sumF = min(ans[i - 1] + foodG[i].second, ans[i - 1] + foodG[i + 1].second);
		sumG = min(foodG[i].first + )

	}

	return 0;
}