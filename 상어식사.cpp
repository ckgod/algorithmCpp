#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
#define ll long long

struct shark {
	int speed;
	int size;
	int iq;
	vector<int> isfood;
};

int n;
vector<shark> sharkInfo;
vector<int> canEat[51];
int food[51];
bool visit[51];
int cnt;
bool retry;

bool dfs(int curShark) {
	if (visit[curShark]) {
		if (retry == false) {
			return false;
		}
	}
	visit[curShark] = true;
	for (int i = 0; i < canEat[curShark].size(); i++) {
		if (retry == true) {
			retry = false;
			return false;
		}
		int curFood = canEat[curShark][i];
		if (curFood == food[curShark]) {
			retry = true;
			if (dfs(curFood)) {
				food[curFood] = curShark;
				return true;
			}
		}
		else {
			if (food[curFood] == -1) {
				food[curFood] = curShark;
				return true;
			}
			else if (dfs(food[curFood])) {
				food[curFood] = curShark;
				return true;
			}
		}
	}
	return false;
}

void init() {
	for (int i = 0; i < 51; i++) {
		food[i] = -1;
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	init();
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b, c;
		shark s;
		cin >> a >> b >> c;
		s.size = a;
		s.speed = b;
		s.iq = c;
		sharkInfo.push_back(s);
	}
	for (int i = 0; i < sharkInfo.size(); i++) {
		for (int j = 0; j < sharkInfo.size(); j++) {
			if (i == j) continue;
			bool alreadyDie = false;
			if (sharkInfo[i].speed >= sharkInfo[j].speed &&
				sharkInfo[i].size >= sharkInfo[j].size &&
				sharkInfo[i].iq >= sharkInfo[j].iq) {
				if (sharkInfo[i].speed == sharkInfo[j].speed &&
					sharkInfo[i].size == sharkInfo[j].size &&
					sharkInfo[i].iq == sharkInfo[j].iq) {
					for (int k = 0; k < sharkInfo[i].isfood.size(); k++) {
						if (sharkInfo[i].isfood[k] == j) {
							alreadyDie = true;
						}
					}
					if (alreadyDie) continue;
				}
				canEat[i].push_back(j);
				sharkInfo[j].isfood.push_back(i);
			}
		}
	}
	
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < n; j++) {
			cnt += dfs(j);
			for (int k = 0; k < n; k++) {
				visit[k] = false;
			}
		}
	}
	cout << n - cnt;


	return 0;
}