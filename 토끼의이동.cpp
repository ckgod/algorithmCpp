#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;


int n;
pair<int, int> dgsUp = { -1,1 };
pair<int, int> dgsDown = { 1,-1 };
pair<int, int> mRight = { 0,1 };
pair<int, int> mDown = { 1,0 };
int moveCnt;
int curRow = 1;
pair<int, int> curPos = { 1,1 };
int m;
string command;
long long result = 1;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	cin >> command;

	for (int i = 0; i < command.size(); i++) {
		if (command[i] == 'U') {
			curPos.first--;
			curRow--;
		}
		else if (command[i] == 'R') {
			curPos.second++;
			curRow++;
		}
		else if (command[i] == 'D') {
			curPos.first++;
			curRow++;
		}
		else if (command[i] == 'L') {
			curPos.second--;
			curRow--;
		}


	}
	


	return 0;
}