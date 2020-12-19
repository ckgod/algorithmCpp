#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
using namespace std;

double S[100001]; // i번째 피드백이 들어왔을때 i 번째 피드백까지 등장한 슬릇머신들의 분산의 평균에 자연로그 스케일을 적용한값
double maxS = 0; double minS = 1;
double alpha = 1.0; double beta = 15.0;
int t, n;
vector<pair<int, pair<double, double>>> slotM; // id, a,b
int ans;

bool checkEnd(int k) {
	//cout << S[k] - minS << "\n" << (maxS - minS) * 0.05 << "\n";
	if ((S[k] - minS) <= (maxS - minS) * 0.05) return true;
	else return false;
}

double calBeta(double a, double b) { // 분산계산
	double t = ((a * b) / ((a + b + 1) * (a + b) * (a + b)));
	//double t = a / (a + b);
	//cout << t << "\n";
	return t;
}

void init() {
	maxS = -10000000;
	minS = 10000000;
	for (int i = 1; i < 100001; i++) {
		S[i] = 0;
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	init();
	cin >> t;
	while (t--) {
		cin >> n;
		bool theEnd = false;
		for (int i = 1; i <= n; i++) {
			bool flag = false;
			int id, count;
			string command;
			cin >> id >> command >> count;

			//if (theEnd) continue;

			for (int j = 0; j < slotM.size(); j++) {
				if (slotM[j].first == id) {
					// 뭔가하고
					if (command == "imp") {
						slotM[j].second.second += count;
					}
					else if (command == "click") {
						slotM[j].second.first += count;
						slotM[j].second.second -= count;
					}
					flag = true;
					break;
				}
			}
			if (flag) { // 이미 있는 슬릇머신 업데이트를 다 했을때
				double tmp = 0;
				int cnt = 0;
				for (int k = 0; k < slotM.size(); k++) {
					if (slotM[k].first != -1) {
						tmp += calBeta(slotM[k].second.first, slotM[k].second.second);
						cnt++;
					}
				}
				tmp /= cnt;
				S[i] = log(tmp);
				//cout << S[i] << "\n";
				//maxS = max(S[i], maxS);
				//minS = min(S[i], minS);
			}
			else { // 새로운 슬릇머신 id가 들어왔을때 
				if (command == "imp") {
					int aid = id;
					double be = beta + count;
					double al = alpha;
					slotM.push_back({ aid,{al,be} });
				}
				else if (command == "click") { // 노출이 돼야 클릭을 할수있으니 여기는 일단 필요없는데 혹시 모르니까 만들어둠
					int aid = id;
					double be = beta - count;
					double al = alpha + count;
					slotM.push_back({ aid,{al,be} });
				}
				double tmp = 0;
				int cnt = 0;
				for (int k = 0; k < slotM.size(); k++) {
					if (slotM[k].first != -1) {
						tmp += calBeta(slotM[k].second.first, slotM[k].second.second);
						cnt++;
					}
				}
				tmp /= cnt;
				S[i] = log(tmp);
				//cout << S[i] << "\n";
				//maxS = max(S[i], maxS);
				//minS = min(S[i], minS);
			}
		}
		for (int i = 1; i <= n; i++) {
			maxS = max(S[i], maxS);
			minS = min(S[i], minS);
		}
		//cout << maxS << "\n" << minS << "\n";
		for (int i = 1; i <= n; i++) {
			if (checkEnd(i)) {
				ans = i;
				break;
			}
			S[i] = 0;
		}
		slotM.clear();
		maxS = -10000000;
		minS = 10000000;
		cout << ans << "\n";
	}


	return 0;
}