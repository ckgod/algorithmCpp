#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm> // can use only sort
using namespace std;

#define endl '\n'
#define MAX_CITYNAME 20
int N; // 설립된 도시들의 개수(2<=N<=50,000)
int M; // 도로들 사이의 존재하는 비포장도로의 개수(1<=M<=500,000)
int q; // 질의의 수(1<=q<=25,000)

string cityNames[50001];
int cityPopulations[50001];
class List;
class City {
public:
	int cityNum;
	City* next;
	List* listPtr;
	City() {
		this->listPtr = 0;
		this->cityNum = -1;
		this->next = 0;
	}
};
class List {
public:
	City* head;
	City* tail;
	int size;
	int len;
	List() {
		this->size = 0;
		this->head = 0;
		this->tail = 0;
		this->len = 0;
	}
};
class Union_Find {
public:
	City* cityPool[1000001];
	int MST;
	int count;
	Union_Find() {
		MST = 0;
		count = 0;
	};
	void make_set(int cityNum, string cityName, int cityPopulation) {
		List* list = new List();
		list->head = new City();
		list->tail = list->head;
		cityPool[cityNum] = list->head;
		cityNames[cityNum] = cityName;
		cityPopulations[cityNum] = cityPopulation;
		list->head->cityNum = cityNum;
		list->head->listPtr = list;
		list->head->next = 0;
		list->size = 1;
	}
	City* find(int cityNum) {
		return cityPool[cityNum]->listPtr->head;
	}
	int make_union(int cityNum1, int cityNum2) {
		City* leader1 = find(cityNum1);
		City* leader2 = find(cityNum2);
		bool first = true;
		if (leader1 == leader2) return -1;

		if (leader1->listPtr->size == leader2->listPtr->size) {
			if (leader1->listPtr->head->cityNum < leader2->listPtr->head->cityNum) first = true;
			else first = false;
		}
		else if (leader1->listPtr->size < leader2->listPtr->size) first = true;
		else  first = false;
		if (!first) {
			City* tmp = leader1;
			leader1 = leader2;
			leader2 = tmp;
		}
		City* cur = leader2;
		while (cur != 0) {
			cur->listPtr = leader1->listPtr;
			cur = cur->next;
		}
		leader1->listPtr->len += leader2->listPtr->len;
		leader1->listPtr->size += leader2->listPtr->size;
		leader1->listPtr->tail = leader2->listPtr->tail;
		leader1->listPtr->tail->next = leader2->listPtr->head;
		delete leader2;
		return leader1->cityNum;
	}
	void queryN(int cityNum, int k) {
		if (cityPool[cityNum]->listPtr->size < k) {
			cout << "no exsit" << endl;
		}
		else {
			City* cur = cityPool[cityNum]->listPtr->head;
			k--;
			while (k > 0) {
				cout << "k : " << k << endl;
				cur = cur->next;
				k--;
			}
			cout << cur->cityNum << " " << cityNames[cur->cityNum] << endl;
		}
	}
	void queryL(int v) {
		cout << cityPool[v]->listPtr->size << endl;
	}
	void queryI(int cityNum1, int cityNum2, int len) {
		int ret = make_union(cityNum1, cityNum2);
		if (ret > 0) {
			MST += len;
			count++;
			if (count == N - 1) {
				cout << cityPool[ret]->listPtr->head->cityNum << " " << cityPool[ret]->listPtr->size << " "
					<< cityPool[ret]->listPtr->head->cityNum << " " << MST << endl;
			}
			else {
				cout << cityPool[ret]->listPtr->head->cityNum << " " << cityPool[ret]->listPtr->size << endl;
			}
		}
		else {
			cout << "not union" << endl;
		}
	}

	void queryF(int cityNum1, int cityNum2) {
		if (cityPool[cityNum1]->listPtr == cityPool[cityNum2]->listPtr) {
			cout << "True " << cityPool[cityNum1]->listPtr->head->cityNum << endl;
		}
		else {
			cout << "False " << cityPool[cityNum1]->listPtr->head->cityNum << " " << cityPool[cityNum2]->listPtr->head->cityNum << endl;
		}
	}
	void queryW(int cityNum) {
		cout << cityPool[cityNum]->listPtr->len << endl;
	}
};
Union_Find uf;

vector<pair<int, pair<int, int>>> load;

bool cmp(pair<int, pair<int, int>> const& a, pair<int, pair<int, int>> const& b) {
	int len1 = a.first;
	int len2 = b.first;
	int population1 = cityPopulations[a.second.first] + cityPopulations[a.second.second];
	int population2 = cityPopulations[b.second.first] + cityPopulations[b.second.second];
	int min1 = min(a.second.first, a.second.second);
	int min2 = min(b.second.first, b.second.second);
	if (len1 == len2 && population1 == population2) return min1 < min2;
	else if (len1 == len2) return population1 > population2;
	else return len1 < len2;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N >> M >> q;
	for (int i = 0; i < N; i++) {
		int cityNum; //도시번호(1<=cityNum<=999,999)
		string cityName; //도시명(1<=len(cityName)<=20)
		int cityPopulation; //도시인구수(1<=cityPopulation<=1,999,999)
		cin >> cityNum >> cityName >> cityPopulation;
		uf.make_set(cityNum, cityName, cityPopulation);
	}

	for (int i = 0; i < M; i++) {
		int cityNum1, cityNum2, len;
		cin >> cityNum1 >> cityNum2 >> len;
		load.push_back({ len,{ cityNum1,cityNum2 } });
	}

	sort(load.begin(), load.end(), cmp);
	int loadIndex = 0;
	for (int i = 0; i < q; i++) {
		char query; cin >> query;
		// cout << "query : " << query << endl;
		if (query == 'N') {
			// cout << "query N" << endl;
			int v, k; cin >> v >> k;
			uf.queryN(v, k);
		}
		else if (query == 'L') {
			//cout << "query L" << endl;
			int v; cin >> v;
			uf.queryL(v);
		}
		else if (query == 'I') {
			int len = load[loadIndex].first;
			int cityNum1 = load[loadIndex].second.first;
			int cityNum2 = load[loadIndex].second.second;
			uf.queryI(cityNum1, cityNum2, len);
			loadIndex++;
		}
		else if (query == 'F') {
			int cityNum1, cityNum2;
			cin >> cityNum1 >> cityNum2;
			uf.queryF(cityNum1, cityNum2);
		}
		else if (query == 'W') {
			int v; cin >> v;
			uf.queryW(v);
		}
		else if (query == 'Q') {
			while (true) {
				int len = load[loadIndex].first;
				int cityNum1 = load[loadIndex].second.first;
				int cityNum2 = load[loadIndex].second.second;
				loadIndex++;
				int ret = uf.make_union(cityNum1, cityNum2);
				if (ret > 0) {
					uf.MST += len;
					uf.count++;
				}
				if (uf.count == N - 1) {
					cout << uf.cityPool[cityNum1]->listPtr->head->cityNum << " " << uf.MST << endl;
				}
			}
		}
	}

}