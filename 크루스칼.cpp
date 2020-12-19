#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 10001
using namespace std;

int parent[MAX], setSize[MAX];

struct Edge {
	int u, v, weight; //u, v�� ����
					  //weight�� ����ġ
};


//��Ʈ ã�� �Լ�
int findParent(int node) {
	//���� ��尡 ������ ��Ʈ���
	//�ڽ��� ���� ������ ã�����Ƿ� node ��ȯ
	if (node == parent[node])
		return node;
	//���� ��尡 ������ ��Ʈ�� �ƴ϶��
	//����� ��Ʈ�� ���� ��� ȣ���ϸ鼭 parent[node] ������Ʈ
	return parent[node] = findParent(parent[node]);
}


//������ ��ġ�� �Լ�
void merge(int node1, int node2) {
	node1 = findParent(node1); //node1�� ���� ������ ã��
	node2 = findParent(node2); //node2�� ���� ������ ã��
							   //���� ������ �ƴ� ��쿡�� ��ģ��
	if (node1 != node2) {
		//ũ�Ⱑ �� ū �������� ���� ������ ��
		if (setSize[node1] < setSize[node2])
			swap(node1, node2);

		parent[node2] = node1; //node2 ������ node1�� ������
		setSize[node1] += setSize[node2]; //node1�� ���� ũ�Ⱑ Ŀ��
		setSize[node2] = 0; //node2�� node1�� ����ǹǷ�
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
	//������ ����ġ�� �������� �������� ����
	sort(edge.begin(), edge.end());
	//�ʱ�ȭ
	for (int i = 0; i < V; i++) {
		parent[i] = i;
		setSize[i] = 1;
	}
	long long result = 0;
	for (int i = 0; i < edge.size(); i++) {
		Edge e = edge[i];
		//���� ������ �ƴ� ���� �߰�
		if (findParent(e.u) != findParent(e.v)) {
			result += e.weight;
			merge(e.u, e.v);
		}
	}
	cout << result << "\n";
	return 0;
}