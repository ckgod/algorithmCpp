#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;
#define findMST 2

class node {
public:
	int num;
	char name[21];
	int person;
	node(int num, char name[21], int person) {
		this->num = num;
		this->person = person;
		for (int i = 0; i < 21; i++) {
			this->name[i] = name[i];
		}
	}
};


struct edge {
	int c1;
	int c2;
	int weight;
};

int cityPerson[50001]; 
int n, m, q;
vector<node> cityList;
vector<edge> edgeList;
char query;
int totalLength;
int setLength[50001];

int minimum(int a, int b) {
	if (a < b) return a;
	else return b;
}


bool comp(edge e1, edge e2) {
	if (e1.weight == e2.weight) {
		int p1 = cityPerson[e1.c1] + cityPerson[e1.c2];
		int p2 = cityPerson[e2.c1] + cityPerson[e2.c2];
		if (p1 == p2) {
			int n1 = minimum(e1.c1, e1.c2);
			int n2 = minimum(e2.c1, e2.c2);
			return n1 < n2;
		}
		else {
			return p1 > p2;
		}
	}
	else {
		return e1.weight < e2.weight;
	}
}

class UnionFind
{
public:
	list<node>* nodeAddress[50001];

	void init(node a) {
		list<node>* newList = new list<node>;

		newList->push_front(a);
		nodeAddress[a.num] = newList;
	}

	int findLeader(int key) {
		return nodeAddress[key]->front().num;
	}

	void merge(int n1, int n2, int edgeIdx) {
		int parent1 = findLeader(n1);
		int parent2 = findLeader(n2);
		list<node>* list1 = nodeAddress[parent1];
		list<node>* list2 = nodeAddress[parent2];

		if (list1->size() < list2->size()) {
			int t = parent1;
			parent1 = parent2;
			parent2 = t;
		}
		else if (list1->size() == list2->size()) {
			if (parent1 > parent2) {
				int t = parent1;
				parent1 = parent2;
				parent2 = t;
			}
		}

		list<node>* curlist1 = nodeAddress[parent1];
		list<node>* curlist2 = nodeAddress[parent2];

		while(!curlist2->empty()) {
			curlist1->push_back(curlist2->front());
			nodeAddress[curlist2->front().num] = curlist1;
			curlist2->pop_front();
		}
		setLength[parent1] += setLength[parent2] + edgeList[edgeIdx].weight;

		delete curlist2;
	}

	void queryN(int v, int k) {
		list<node>* vList = nodeAddress[v];
		if (vList->size() <= k) {
			cout << "no exist\n";
			return;
		}
		else {
			list<node>::iterator iter = vList->begin();
			for (int i = 0; i < k; i++) {
				iter++;
			}
			cout << iter->num << " " << iter->name << "\n";
			return;
		}
	}

	void queryL(int v) {
		list<node>* vList = nodeAddress[v];
		cout << vList->size() << "\n";
		return;
	}

	int queryI(int c1, int c2, int edgeIdx) {
		int leader1 = findLeader(c1);
		int leader2 = findLeader(c2);
		if (leader1 == leader2) {
			cout << "not union\n";
			return 0;
		}
		else {
			merge(leader1, leader2, edgeIdx);
			list<node>* bigList = nodeAddress[c1];
			totalLength += edgeList[edgeIdx].weight;
			int ID = findLeader(c1);
			int S = bigList->size();
			int D = totalLength;
			if (bigList->size() == n) {
				cout << ID << " " << S << " " << ID << " " << D << "\n";
				return findMST;
			}
			else {
				cout << ID << " " << S << "\n";
				return 1;
			}
		}
	}

	void queryF(int v1, int v2) {
		int leader1 = findLeader(v1);
		int leader2 = findLeader(v2);
		if (leader1 == leader2) {
			cout << "True " << leader1 << "\n";
		}
		else {
			cout << "False " << leader1 << " " << leader2 << "\n";
		}
	}

	void queryW(int v) {
		int leader = findLeader(v);
		cout << setLength[leader] << "\n";
	}
	void queryQ(int edgeIdx) {
		int leader1 = findLeader(edgeList[edgeIdx].c1);
		int leader2 = findLeader(edgeList[edgeIdx].c2);
		if (leader1 != leader2) {
			merge(edgeList[edgeIdx].c1, edgeList[edgeIdx].c2, edgeIdx);
			totalLength += edgeList[edgeIdx].weight;
		}
	}
};



int edgeIdx;
UnionFind uf;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n >> m >> q;
	for (int i = 0; i < n; i++) {
		int a, c;
		char b[21];
		cin >> a >> b >> c;
		node newNode(a, b, c);
		cityList.push_back(newNode);
		uf.init(newNode);
		cityPerson[a] = c;
	}
	for (int i = 0; i < m; i++) {
		edge newEdge;
		cin >> newEdge.c1 >> newEdge.c2 >> newEdge.weight;
		edgeList.push_back(newEdge);
	}
	sort(edgeList.begin(), edgeList.end(), comp);
	while (q--) {
		cin >> query;
		if (query == 'N') {
			int v, k;
			cin >> v >> k;
			uf.queryN(v, k);
		}
		else if (query == 'L') {
			int v;
			cin >> v;
			uf.queryL(v);
		}
		else if (query == 'I') {
			int c1 = edgeList[edgeIdx].c1;
			int c2 = edgeList[edgeIdx].c2;
			//cout << c1 << " " << c2;
			int result = uf.queryI(c1, c2, edgeIdx);
			if (result == findMST) {
				return 0;
			}
			edgeIdx++;
		}
		else if (query == 'F') {
			int v1, v2;
			cin >> v1 >> v2;
			uf.queryF(v1, v2);
		}
		else if (query == 'W') {
			int v;
			cin >> v;
			uf.queryW(v);
		}
		else if (query == 'Q') {
			while (edgeIdx < edgeList.size()) {
				uf.queryQ(edgeIdx);
				edgeIdx++;
			}
			cout << uf.findLeader(cityList[0].num) << " " << totalLength << "\n";
			return 0;
		}
	}
	
	return 0;
}