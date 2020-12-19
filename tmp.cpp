#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;
#define D 0
#define S 1
#define L 2
#define R 3
#define mod 10000

int t;
vector<int> a;
string n1;
int na, nb;
int visit[10001];
int checkV = 1;
string v[10001];

int trans(vector<int> a);
vector<int> untrans(int n);

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> t;
	while (t--) {
		a.resize(4, 0);
		cin >> n1 >> nb;
		na = stoi(n1);
		int idx1 = 3; int idx2 = 3;
		for (int i = n1.length() - 1; i >= 0; i--) {
			a[idx1] = n1[i] - '0';
			idx1--;
		}
		queue<int> q;
		q.push(na);
		v[na] = "";
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			if (cur == nb) break;
			visit[cur] = checkV;
			int next = 0;

			next = (2 * cur) % mod;
			if (visit[next] != checkV) {
				v[next] = v[cur] + "D";
				q.push(next);
				visit[next] = checkV;
			}

			next = cur - 1;
			if (cur == 0) next = 9999;
			if (visit[next] != checkV) {
				v[next] = v[cur] + "S";
				q.push(next);
				visit[next] = checkV;
			}

			vector<int> tmp = untrans(cur);
			swap(tmp[0], tmp[3]);
			swap(tmp[0], tmp[2]);
			swap(tmp[0], tmp[1]);
			next = trans(tmp);
			if (visit[next] != checkV) {
				v[next] = v[cur] + "L";
				q.push(next);
				visit[next] = checkV;
			}

			tmp = untrans(cur);
			swap(tmp[0], tmp[3]);
			swap(tmp[1], tmp[3]);
			swap(tmp[2], tmp[3]);
			next = trans(tmp);
			if (visit[next] != checkV) {
				v[next] = v[cur] + "R";
				q.push(next);
				visit[next] = checkV;
			}

		}
		checkV++;
		cout << v[nb] << "\n";
	}
	
	return 0;
}

int trans(vector<int> a) {
	return ((a[0] * 10 + a[1]) * 10 + a[2]) * 10 + a[3];
}

vector<int> untrans(int n) {
	vector<int> t;
	t.resize(4, 0);
	string s = to_string(n);
	int idx = 3;
	for (int i = s.length() - 1; i >= 0; i--) {
		t[idx] = s[i] - '0';
		idx--;
	}
	return t;
}

