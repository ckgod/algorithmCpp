#include<iostream>
#include<vector>

using namespace std;

class Node {
public:
	int data;
	Node* parent;
	Node* right;
	Node* left;
	int depth;
	// 생성자
	Node() {
		this->data = NULL;
		this->parent = NULL;
		this->right = NULL;
		this->left = NULL;
		this->depth = 0;
	}
	Node(int data) {
		this->data = data;
		this->parent = NULL;
		this->right = NULL;
		this->left = NULL;
		this->depth = 0;
	}
	// 소멸자
	~Node() {
	}
	// 왼쪽 자식에 추가
	void insertleft(Node* left) {
		this->left = left;
		left->parent = this;
	}
	// 오른쪽 자식에 추가
	void insertright(Node* right) {
		this->right = right;
		right->parent = this;
	}
	// 해당 노드의 자식 수 출력
	void printDegree() {}
	// 해당 노드의 깊이 출력
	void printDepth() {}
};

class BST {
public:
	Node* root;			// root 노드
	int height;			// 트리의 높이
	// 생성자
	BST() {
		root = NULL;
		height = 0;
	}
	// 소멸자
	~BST() {
		this->treeDestructor(this->root);
	}
	// 노드 삽입 연산 (트리의 높이를 함께 고려)
	void insertNode(int data) {
		int height = 0;
		Node* newnode = new Node(data);
		Node* current = this->root;
		Node* cParent = NULL;
		if (root == NULL)
		{
			root = newnode;
		}
		else
		{
			while (current != NULL)
			{
				cParent = current;
				if (current->data < data)
				{
					current = current->right;
				}
				else
				{
					current = current->left;
				}
			}
			newnode->parent = cParent;
			newnode->depth = newnode->parent->depth + 1;
			if (cParent->data < data)
			{
				cParent->right = newnode;
			}
			else
			{
				cParent->left = newnode;
			}
		}
	}
	// 노드 탐색 연산
	Node* findNode(int data) {
		Node* tmp = root;
		while (tmp != NULL) {
			if (tmp->data == data)
			{
				return tmp;
			}
			else {
				if (tmp->data < data)
					tmp = tmp->right;
				else
					tmp = tmp->left;
			}
		}
		return NULL;
	}

	int calHeight(Node* node)
	{
		if (node != NULL)
		{
			int h = node->depth;
			if (h > calHeight(node->left))
			{
				return h;
			}
			else
			{
				return calHeight(node->left);
			}
			if (h > calHeight(node->right))
			{
				return h;
			}
			else
			{
				return calHeight(node->right);
			}
		}
	}

	int ChildSu(Node* node)
	{
		if (node->left == NULL && node->right == NULL)
		{
			return 0;
		}
		else if ((node->left != NULL && node->right == NULL)
			|| (node->left == NULL && node->right != NULL))
		{
			return 1;
		}
		else
		{
			return 2;
		}

	}
	// 트리의 높이 출력
	void printHeight() {

	}

	void transPlant(Node* p, Node* c)
	{
		if (p->parent == NULL)
		{
			this->root = c;
		}
		else if (p == p->parent->left)
		{
			p->parent->left = c;
		}
		else
		{
			p->parent->right = c;
		}
		if (c != NULL)
		{
			c->parent = p->parent;
		}
	}
	// 노드 삭제 연산
	void deleteNode(int data) {
		Node* dnode = findNode(data);
		if (dnode->left == NULL && dnode->right == NULL)
		{
			if (dnode->parent == NULL)
			{
				this->root = NULL;
			}
			else if (dnode == dnode->parent->left)
			{
				dnode->parent->left = NULL;
			}
			else
			{
				dnode->parent->right = NULL;
			}
		}
		else if (dnode->left != NULL && dnode->right == NULL)
		{
			transPlant(dnode, dnode->left);
		}
		else if (dnode->left == NULL && dnode->right != NULL)
		{
			transPlant(dnode, dnode->right);
		}
		else
		{
			Node* min = dnode->right;
			while (min->left != NULL)
			{
				min = min->left;
			}
			if (min->parent != dnode)
			{
				transPlant(min, min->right);
				min->right = dnode->right;
				dnode->right->parent = min;
				
			}
			transPlant(dnode, min);
			min->left = dnode->left;
			dnode->left->parent = min;
		}
	}
	// node의 오른쪽 자식에서 최솟값 탐색
	Node* findMinimum(Node* node) {}
	// 전위 순회(pre-order traversal) 결과 출력
	void printPreorderTraversal(Node* root)
	{
		if (root == NULL) return;
		cout << root->data << " ";
		printPreorderTraversal(root->left);
		printPreorderTraversal(root->right);
	}
	// 후위 순회(post-order traversal)하며 트리의 모든 노드 삭제 (소멸자에서 사용)
	void treeDestructor(Node* root) {
		if (root == NULL)
			return;

		if (root->left != NULL)
			this->treeDestructor(root->left);
		if (root->right != NULL)
			this->treeDestructor(root->right);
		delete(root);
	}
};

vector<int> X;
vector<int> Y;
int T;
int N;
int tmp;
int M;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;
	while (T--)
	{
		BST b;
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			cin >> tmp;
			X.push_back(tmp);
		}
		for (int i = 0; i < X.size(); i++)
		{
			b.insertNode(X[i]);
		}
		cin >> M;
		for (int i = 0; i < M; i++)
		{
			cin >> tmp;
			Y.push_back(tmp);
		}
		for (int i = 0; i < Y.size(); i++)
		{
			b.deleteNode(Y[i]);
		}
		b.printPreorderTraversal(b.root);
		cout << "\n";
		Y.clear();
		X.clear();
	}

	return 0;
}