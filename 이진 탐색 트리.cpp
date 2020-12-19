#include <iostream>
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
		this->parent = NULL;
		this->left = NULL;
		this->right = NULL;
		this->data = 0;
	}
	node(int x)
	{
		this->parent = NULL;
		this->left = NULL;
		this->right = NULL;
		this->data = x;
	}
};

class BST
{
public:
	int cnt;
	node* root;
	BST()
	{
		this->cnt = 0;
		this->root = NULL;
	}
	BST(int x)
	{
		this->cnt = 0;
		this->root = new node(x);
	}

	void insert(int num)
	{
		node* newnode = new node(num);
		node* current = this->root;
		node* cParent = NULL;
		if (this->root == NULL)
		{
			this->root = newnode;
			return;
		}
		while (current != NULL)
		{
	//		cnt++;
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
		if (cParent->data < num)
		{
			cParent->right = newnode;
		}
		else
		{
			cParent->left = newnode;
		}
	}

	node* search(node* rt, int n)
	{
		if (rt == NULL || rt->data == n)
		{
			return rt;
		}
		if (rt->data < n)
		{
			search(rt->right, n);
		}
		else
		{
			search(rt->left, n);
		}
	}

	void transPlant(node* p, node* c)
	{
		if (p->parent == NULL)
		{
			this->root = c;
		}
		else if (p == p->parent->right)
		{
			p->parent->right = c;
		}
		else
		{
			p->parent->left = c;
		}
		if (c != NULL)
		{
			c->parent = p->parent;
		}
	}

	void erase(int num)
	{
		node* dnode = search(this->root, num);
		if (dnode->left == NULL && dnode->right == NULL)
		{
			if (dnode->parent == NULL)
			{
				this->root = NULL;
			}
			else if(dnode == dnode->parent->right)
			{
				dnode->parent->right = NULL;
			}
			else
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
			node* min = dnode->right;
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
				transPlant(min, min->right);
				min->right = dnode->right;
				dnode->right->parent = min;
				transPlant(dnode, min);
				min->left = dnode->left;
				dnode->left->parent = min;
			}
		}
		delete dnode;
	}

	void inorder(node* v)
	{
		if (v == NULL) return;
		inorder(v->left);
		cout << v->data << " ";
		inorder(v->right);
	}
};

int N, M;
int X;
BST b;
int tmp;
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	while (N--)
	{
		cin >> X;
		b.insert(X);
	}
	b.inorder(b.root);
	cout << "\n";
	while (M--)
	{
		cin >> X;
		b.erase(X);
		cout << b.cnt << "\n";
		b.inorder(b.root);
		cout << "\n";
	}

	return 0;
}