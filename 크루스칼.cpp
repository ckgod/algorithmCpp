#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 10001
using namespace std;

int parent[MAX], setSize[MAX];

struct Edge {
	int u, v, weight; //u, v는 정점
					  //weight는 가중치
};


//루트 찾는 함수
int findParent(int node) {
	//현재 노드가 집합의 루트라면
	//자신이 속한 집합을 찾았으므로 node 반환
	if (node == parent[node])
		return node;
	//현재 노드가 집합의 루트가 아니라면
	//노드의 루트에 대해 재귀 호출하면서 parent[node] 업데이트
	return parent[node] = findParent(parent[node]);
}


//집합을 합치는 함수
void merge(int node1, int node2) {
	node1 = findParent(node1); //node1이 속한 집합을 찾음
	node2 = findParent(node2); //node2가 속한 집합을 찾음
							   //같은 집합이 아닐 경우에만 합친다
	if (node1 != node2) {
		//크기가 더 큰 집합으로 작은 집합이 들어감
		if (setSize[node1] < setSize[node2])
			swap(node1, node2);

		parent[node2] = node1; //node2 집합이 node1에 합쳐짐
		setSize[node1] += setSize[node2]; //node1의 집합 크기가 커짐
		setSize[node2] = 0; //node2가 node1에 흡수되므로
	}
}
int main() {
	int V, E;
	cin >> V >> E;
	vector<Edge> edge;
	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		edge.push_back({ u, v, w });
	}
	//간선의 가중치를 기준으로 오름차순 정렬
	sort(edge.begin(), edge.end());
	//초기화
	for (int i = 0; i < V; i++) {
		parent[i] = i;
		setSize[i] = 1;
	}
	long long result = 0;
	for (int i = 0; i < edge.size(); i++) {
		Edge e = edge[i];
		//같은 집합이 아닐 때만 추가
		if (findParent(e.u) != findParent(e.v)) {
			result += e.weight;
			merge(e.u, e.v);
		}
	}
	cout << result << "\n";
	return 0;
}