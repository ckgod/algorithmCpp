#include <iostream>
#include <vector>
using namespace std;

class node
{
public:
	int elem; // ����� ����
	int storage; // ����� �뷮
	int allstor; // �������뷮�� �ڱ�뷮 ��
	int depth = 0; // ����
	node* parent;
	vector<node*> child;
	node()
	{
		this->allstor = 0;
		this->depth = 0;
		this->storage = 0;
		this->elem = 0;
		parent = NULL;
	}
	node(int n)
	{
		this->allstor = 0;
		this->depth = 0;
		this->storage = 0;
		this->elem = n;
		parent = NULL;
	}
	int getAllStor() 
	{
		return this->allstor;
	}
	int getelem()
	{
		return this->elem;
	}
	int getParent()
	{
		return parent->elem;
	}
	void pushChild(node* ch) // �ڽĳ���߰�
	{
		this->child.push_back(ch);
	}
	void setParent(node* p) // �θ��弳��
	{
		this->parent = p;
	}
	void delChild(node* c) // �ڽĳ�� ����
	{
		for (unsigned int i = 0; i < this->child.size(); i++)
		{
			if (this->child[i] == c)
			{
				this->child.erase(this->child.begin() + i);
			}
		}
	}
};

class tree
{
public:
	node* root = new node();
	vector<node*> nodelist; // �߰��� ����� �����������
	int treesize = 0;
	tree()
	{
		this->root = NULL;
	}
	tree(int e)
	{
		this->root->elem = e;
		nodelist.push_back(root);
	}
public:
	void setStorage(int p, int s) // p��ġ����� storage�� s�Է�
	{
		for (int i = 0; i < nodelist.size(); i++)
		{
			if (nodelist[i]->elem == p)
			{
				nodelist[i]->storage = s;
			}
		}
	}
	void sumStorage(node* alls, node* vroot) // alls����� allstor�� postorder���̿��ؼ� ���������� �뷮�� ��δ���
	{
		for (int i = 0; i < vroot->child.size(); i++)
		{
			sumStorage(alls, vroot->child[i]);
		}
		alls->allstor += vroot->storage;
	}
	void insertNode(int p, int e) // p��ġ��忡 e������ �ڽ��� �߰�
	{
		node* newleaf = new node(e);
	//	node* cur;
		for (int i = 0; i < nodelist.size(); i++)
		{
			if (nodelist[i]->elem == p)
			{
				nodelist[i]->pushChild(newleaf);
				newleaf->setParent(nodelist[i]);
				nodelist.push_back(newleaf);
				newleaf->depth = newleaf->parent->depth + 1;
				/*cur = nodelist[i];
				cur->pushChild(newleaf);
				newleaf->setParent(cur);
				newleaf->depth = newleaf->parent->depth + 1;
				nodelist.push_back(newleaf);*/
			}
		}
	}

	void printChild(int pe) // pe��ġ����� �ڽĵ� ���� ���
	{
		for (int i = 0; i < nodelist.size(); i++)
		{
			if (nodelist[i]->elem == pe)
			{
				if (nodelist[i]->child.size() == 0)
				{
					cout << "0\n";
				}
				else
				{
					for (int j = 0; j < nodelist[i]->child.size(); j++)
					{
						cout << nodelist[i]->child[j]->elem << " ";
					}
					cout << "\n";
				}
			}
		}
	}
	void printParent(int c)
	{
		for (int i = 0; i < nodelist.size(); i++)
		{
			if (nodelist[i]->elem == c)
			{
				if (nodelist[i]->parent == NULL)
				{
					cout << "root!\n";
				}
				else
				{
					cout << nodelist[i]->getParent() << "\n";
				}
			}
		}
	}
	void printDepth(int position)
	{
		for (int i = 0; i < nodelist.size(); i++)
		{
			if (nodelist[i]->elem == position)
			{
				cout << nodelist[i]->depth << "\n";
			}
		}
	}

	node* search(int elem) // elem���������� ���˻� �ּҹ�ȯ
	{
		for (int i = 0; i < nodelist.size(); i++)
		{
			if (nodelist[i]->elem == elem)
			{
				return nodelist[i];
			}
		}
	}

	// Travasal  -> Ʈ���� ����带 �ѹ��� ó���� �� ����

	void preOrder(node* vroot) // �������� : �ڱ���� ó��->����ó��
	{
		cout << vroot->elem << " ";
		for (int i = 0; i < vroot->child.size(); i++)
		{
			preOrder(vroot->child[i]);
		}
	}

	void postOrder(node* vroot) // ����Ʈ���� : ���������� ó��
	{
		for (int i = 0; i < vroot->child.size(); i++)
		{
			postOrder(vroot->child[i]);
		}
		cout << vroot->elem << " ";
	}

	////////////////////////////////

	bool isroot()
	{

	}
	bool isexternal()
	{

	}
};

int N, M;
tree T1(1);
int stor[27];
int nn, st;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	int tmp = N;
	for (int i = 0; i < N; i++)
	{
		cin >> nn >> st;
		stor[nn] = st;
	}
	while (N--)
	{
		vector<int> num;
		for (int i = 0; i < 7; i++)
		{
			int tmp;
			cin >> tmp;
			if (tmp == 0) break;
			num.push_back(tmp);
		}
		for (int i = 1; i < num.size(); i++)
		{
			T1.insertNode(num[0], num[i]);
		}
	}
	N = tmp;
	for (int i = 1; i <= N; i++)
	{
		T1.setStorage(i, stor[i]);
	}
	while (M--)
	{
		int fp;
		cin >> fp;
		if (T1.search(fp)->allstor == 0)
		{
			T1.sumStorage(T1.search(fp), T1.search(fp));
		}
		cout << T1.search(fp)->allstor << "\n";
	}
	//int p = 0;
	//T1.preOrder(T1.root);
	//cout << "\n";
	//T1.postOrder(T1.root);
	//while (M--)
	//{
	//	cin >> p;
	//	T1.printDepth(p);
	//	T1.printChild(p);
	//	T1.printParent(p);
	//}


	return 0;
}