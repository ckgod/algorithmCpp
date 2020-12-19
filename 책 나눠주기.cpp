#include <iostream>
#include <vector>
using namespace std;

int t, n, m;
int student[1001];
vector<int> book[1001];
bool visit[1001];
int cnt;

bool dfs(int curBook) {
	if (visit[curBook]) return false;
	visit[curBook] = true;
	for (int i = 0; i < book[curBook].size(); i++) {
		int curStudent = book[curBook][i];
		if (student[curStudent] == 0) {
			student[curStudent] = curBook;
			return true;
		}
		else if (dfs(student[curStudent])) {
			student[curStudent] = curBook;
			return true;
		}
	}
	return false;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 1; i <= m; i++) {
			int a, b;
			cin >> a >> b;
			for (int j = a; j <= b; j++) {
				book[j].push_back(i);
			}
		}
		for (int i = 1; i <= n; i++) {
			cnt += dfs(i);
			for (int j = 1; j <= n; j++) {
				visit[j] = false;
			}
		}
		cout << cnt << "\n";
		cnt = 0;
		for (int i = 1; i <= n; i++) {
			book[i].clear();
		}
		for (int i = 1; i <= m; i++) {
			student[i] = 0;
		}
	}
	
	return 0;
}