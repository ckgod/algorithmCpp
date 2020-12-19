#include <iostream>
using namespace std;

const int MAX = 1e5;
int tree[MAX * 4], input[MAX + 1], lazy[MAX + 4];


// 인덱스를 지정한 갱신
int update(int target, int cost, int node, int start, int end)
{
	if (target < start || end < target) return tree[node];
	if (start == end) return tree[node] = cost;

	int mid = (start + end) / 2;
	
	return tree[node] = update(target, cost, node * 2, start, mid)
		+ update(target, cost, node * 2 + 1, mid + 1, end);
}


// 범위를 지정한 갱신
void update_range(int left, int right, int node, int start, int end, int diff)
{
	if (right < start || end < left) return;

	if (start == end)
	{
		tree[node] += diff;
		return;
	}

	int mid = (start + end) / 2;

	update_range(left, right, node * 2, start, mid, diff);
	update_range(left, right, node * 2 + 1, mid + 1, end, diff);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}


// Input이 주어진 경우 세그먼트 트리를 초기화하는 방법
int init(int node, int start, int end)
{
	if (start == end) tree[node] = input[start];

	int mid = (start + end) / 2;
	return tree[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
}


//구간에 대한 합을 가져오기
int query(int left, int right, int node, int start, int end)
{
	if (right < start || end < left) return 0; // 지금위치가 범위안에 없을때
	if (left <= start && end <= right) return tree[node]; // 범위안에 있을때

	int mid = (start + end) / 2;

	return query(left, right, node * 2, start, mid)
		+ query(left, right, node * 2 + 1, mid + 1, end);
}




int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	




	return 0;
}