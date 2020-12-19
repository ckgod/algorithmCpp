#include <iostream>
using namespace std;

int n;
bool graph[101][101];
bool result[101][101];
bool path[101];

void dfs(int start) {
	for (int i = 0; i < n; i++) {
		if (graph[start][i] == 1 && path[i] == false) {
			path[i] = true;
			dfs(i);
		}
	}
}

void init() {
	for (int i = 0; i < 101; i++) {
		path[i] = 0;
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> graph[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		dfs(i);
		for (int j = 0; j < n; j++) {
			if (path[j] == true) {
				result[i][j] = 1;
			}
		}

		init();
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << result[i][j] << " ";
		}
		cout << "\n";
	}



	return 0;
}