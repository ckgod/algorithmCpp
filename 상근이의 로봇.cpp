#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

pair<int, int> S = { 0,1 };
pair<int, int> J = { 0,-1 };
pair<int, int> I = { 1,0 };
pair<int, int> Z = { -1,0 };

int n, m;
vector<pair<int, int>> checkPoint;
vector<int> ypos;
vector<int> xpos;
string command;
int curx, cury;
long long dis;

long long absol(int a) {
	if (a < 0) return -a;
	else return a;
}


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		checkPoint.push_back({ a,b });
		ypos.push_back(b);
		xpos.push_back(a);
		dis += absol(curx - a) + absol(cury - b);
	}
	//cout << dis << "\n";
	sort(xpos.begin(), xpos.end());
	sort(ypos.begin(), ypos.end());
	cin >> command;
	for (int i = 0; i < m; i++) {
		if (command[i] == 'S') {
			int left = 0;
			int right = ypos.size() - 1;
			while (left <= right) {
				int mid = (left + right) / 2;
				if (ypos[mid] <= cury) {
					left = mid + 1;
				}
				else {
					right = mid - 1;
				}
			}
			dis += left;
			dis -= ypos.size() - left;
			cout << dis << "\n";
			curx += S.first;
			cury += S.second;
		}
		else if (command[i] == 'J') {
			int left = 0;
			int right = ypos.size() - 1;
			while (left <= right) {
				int mid = (left + right) / 2;
				if (ypos[mid] < cury) {
					left = mid + 1;
				}
				else {
					right = mid - 1;
				}
			}
			dis -= right + 1;
			dis += ypos.size() - right - 1;
			cout << dis << "\n";
			curx += J.first;
			cury += J.second;
		}
		else if (command[i] == 'I') {
			int left = 0;
			int right = xpos.size() - 1;
			while (left <= right) {
				int mid = (left + right) / 2;
				if (xpos[mid] <= curx) {
					left = mid + 1;
				}
				else {
					right = mid - 1;
				}
			}
			dis += left;
			dis -= xpos.size() - left;
			cout << dis << "\n";
			curx += I.first;
			cury += I.second;
		}
		else if (command[i] == 'Z') {
			int left = 0;
			int right = xpos.size() - 1;
			while (left <= right) {
				int mid = (left + right) / 2;
				if (xpos[mid] < curx) {
					left = mid + 1;
				}
				else {
					right = mid - 1;
				}
			}
			dis -= right + 1;
			dis += xpos.size() - right - 1;
			cout << dis << "\n";
			curx += Z.first;
			cury += Z.second;
		}
	}

	return 0;
}