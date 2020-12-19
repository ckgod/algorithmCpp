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
	// ������
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
	// �Ҹ���
	~Node() {
	}
	// ���� �ڽĿ� �߰�
	void insertleft(Node* left) {
		this->left = left;
		left->parent = this;
	}
	// ������ �ڽĿ� �߰�
	void insertright(Node* right) {
		this->right = right;
		right->parent = this;
	}
	// �ش� ����� �ڽ� �� ���
	void printDegree() {}
	// �ش� ����� ���� ���
	void printDepth() {}
};

class BST {
public:
	Node* root;			// root ���
	int height;			// Ʈ���� ����
	// ������
	BST() {
		root = NULL;
		height = 0;
	}
	// �Ҹ���
	~BST() {
		this->treeDestructor(this->root);
	}
	// ��� ���� ���� (Ʈ���� ���̸� �Բ� ���)
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
	// ��� Ž�� ����
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
	// Ʈ���� ���� ���
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
	// ��� ���� ����
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
	// node�� ������ �ڽĿ��� �ּڰ� Ž��
	Node* findMinimum(Node* node) {}
	// ���� ��ȸ(pre-order traversal) ��� ���
	void printPreorderTraversal(Node* root)
	{
		if (root == NULL) return;
		cout << root->data << " ";
		printPreorderTraversal(root->left);
		printPreorderTraversal(root->right);
	}
	// ���� ��ȸ(post-order traversal)�ϸ� Ʈ���� ��� ��� ���� (�Ҹ��ڿ��� ���)
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