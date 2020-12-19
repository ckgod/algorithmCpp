#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

struct people {
	int age;
	string name;
	int order;
};

int n;
vector<people> p;

bool comp(people p1, people p2) {
	if (p1.age == p2.age) return p1.order < p2.order;
	else return p1.age < p2.age;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		string s;
		cin >> a >> s;

		people ko;
		ko.age = a;
		ko.name = s;
		ko.order = i;
		p.push_back(ko);
	}
	sort(p.begin(), p.end(), comp);
	for (int i = 0; i < p.size(); i++) {
		cout << p[i].age << " " << p[i].name << "\n";
	}

	return 0;
}