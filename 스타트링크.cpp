#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int building[1000001];
bool visit[1000001];
int F, S, G, U, D;


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> F >> S >> G >> U >> D;
	queue<int> q;
	q.push(S);
	visit[S] = true;
	while (!q.empty()) {
		int curFloor = q.front();
		q.pop();

		for (int i = 0; i < 2; i++) {
			if (i == 0) {
				int nextF = curFloor + U;
				if (nextF > F || visit[nextF] == true) {
					continue;
				}
				q.push(nextF);
				visit[nextF] = true;
				building[nextF] += building[curFloor] + 1;
			}
			else {
				int nextF = curFloor - D;
				if (nextF <= 0 || visit[nextF] == true) {
					continue;
				}
				q.push(nextF);
				visit[nextF] = true;
				building[nextF] += building[curFloor] + 1;
			}
		}
	}

	if (visit[G] == false) {
		cout << "use the stairs\n";
	}
	else {
		cout << building[G] << "\n";
	}


	return 0;
}