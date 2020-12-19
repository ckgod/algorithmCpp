#include <iostream>
#include <vector>
using namespace std;

class node
{
public:
	node* parent;
	node* left;
	node* right;
	int data;
	node()
	{
		parent = NULL;
		right = NULL;
		left = NULL;
		this->data = 0;
	}
	node(int a)
	{
		parent = NULL;
		left = NULL;
		right = NULL;
		this->data = a;
	}
};

class BST
{
public:
	node* root;
	int cnt;
	BST()
	{
		root = NULL;
		this->cnt = 0;
	}
	BST(int x)
	{
		root = new node(x);
		this->cnt = 0;
	}
	void insert(int num)
	{
		node* newnode = new node(num);
		node* current = this->root;
		node* cParent = NULL;
		while (current != NULL)
		{
//			cnt++;
			cParent = current;
			if (current->data < num)
			{
				current = current->right;
			}
			else
			{
				current = current->left;
			}
		}
		newnode->parent = cParent;
		if (root == NULL)
		{
			root = newnode;
		}
		else if (cParent->data < num)
		{
			cParent->right = newnode;
		}
		else
		{
			cParent->left = newnode;
		}
	}
	void transPlant(node* n1, node* n2)
	{
		if (n1->parent == NULL) // n1이 루트일때 루트를 n2로 바꿔줌
		{
			this->root = n2;
		}
		else if (n1 == n1->parent->left) // n1이 왼쪽자식일때
		{
			n1->parent->left = n2; // n1에다가 n2를 넣어줌
		}
		else // n1 오른쪽 자식일때
		{
			n1->parent->right = n2; // n1에다가 n2를 넣어줌
		}
		if (n2 != NULL) // n2가 널이 아니면
		{
			n2->parent = n1->parent;
		}
	}
	node* search(node* r, int num)
	{
		if (r == NULL || r->data == num)
		{
			return r;
		}
		if (r->data < num)
		{
			search(r->right,num);
		}
		else
		{
			search(r->left,num);
		}
	}
	void delnode(int num)
	{
		node* dnode = search(this->root, num);
		if (dnode->left == NULL && dnode->right == NULL)
		{
			if (dnode->parent == NULL)
			{
				this->root = NULL;
			}
			else if (dnode == dnode->parent->right)
			{
				dnode->parent->right = NULL;
			}
			else if (dnode == dnode->parent->left)
			{
				dnode->parent->left = NULL;
			}
		}
		else if (dnode->left == NULL && dnode->right != NULL)
		{
			transPlant(dnode, dnode->right);
		}
		else if (dnode->left != NULL && dnode->right == NULL)
		{
			transPlant(dnode, dnode->left);
		}
		else
		{
			node* min = dnode->right; // succesor
			while (min->left != NULL)
			{
				cnt++;
				min = min->left;
			}
			if (min->parent == dnode)
			{
				transPlant(dnode, min);
				min->left = dnode->left;
				dnode->left->parent = min;
			}
			else
			{
				transPlant(min, min->right); //
				min->right = dnode->right;
				dnode->right->parent = min;
				transPlant(dnode, min);
				min->left = dnode->left;
				dnode->left->parent = min;
			}
		}
		delete dnode;
	}
};


BST b;
int n;
int m;
int x;
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	while (n--)
	{
		cin >> x;
		b.insert(x);
	}
	while (m--)
	{
		cin >> x;
		b.delnode(x);
		cout << "cnt : : " << b.cnt << endl;
	}

	return 0;
}