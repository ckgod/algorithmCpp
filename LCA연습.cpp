#include <iostream>
using namespace std;

bool avail[32][15002];
int n, m;
int w[32];
bool ans[8];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> w[i];

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= 15000; j++) {
			if (!avail[i - 1][j]) continue;
			if (j > w[i]) avail[i][j - w[i]] = true;
			else avail[i][w[i] - j] = true;
			avail[i][w[i] + j] = true;
			avail[i][j] = true;
		}
		avail[i][w[i]] = true;
	}
	cin >> m;
	int x;
	for (int i = 0; i < m; i++) {
		cin >> x;
		if (x > 15000) ans[i] = false;
		else if (avail[n][x]) ans[i] = true;
	}
	for (int i = 0; i < m; i++) {
		if (ans[i]) cout << "Y ";
		else cout << "N ";
	}
	cout << "\n";
}